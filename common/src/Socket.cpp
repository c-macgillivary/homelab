#include "Socket.h"
#include <arpa/inet.h>
#include <cstdint>
#include <sys/socket.h>
#include <unistd.h>

Socket::Socket(int fd) :
  _fd(fd)
{
}

Socket::~Socket()
{
  close();
}

Socket::Socket(Socket&& other) :
  _fd(other._fd)
{
  other._fd = -1;
}

Socket& Socket::operator=(Socket&& other)
{
  if (&other != this)
  {
    close();

    _fd = other._fd;
    other._fd = -1;
  }

  return *this;
}

ssize_t Socket::sendHeader(uint32_t size)
{
  uint32_t networkSize = htonl(size);
  auto ptr = reinterpret_cast<const char*>(&networkSize);
  ssize_t total = 0;

  while (total < sizeof(networkSize))
  {
    ssize_t sent = ::send(_fd, ptr + total, sizeof(networkSize) - total, 0);

    if (sent <= 0)
      return -1;

    total += sent;
  }

  return total;
}

ssize_t Socket::sendPayload(const std::string& msg)
{
  ssize_t total = 0;
  size_t size = msg.size();

  while (total < size)
  {
    ssize_t sent = ::send(_fd, msg.data() + total, size - total, 0);

    if (sent <= 0)
      return -1;

    total += sent;
  }

  return total;
}

ssize_t Socket::send(const std::string& msg)
{
  if (msg.size() > UINT32_MAX)
    return -1;

  uint32_t size = msg.size();

  if (sendHeader(size) < 0)
    return -1;

  return sendPayload(msg);
}

ssize_t Socket::receiveHeader(uint32_t& size)
{
  uint32_t networkSize;
  auto ptr = reinterpret_cast<char*>(&networkSize);
  ssize_t total = 0;

  while (total < sizeof(networkSize))
  {
    ssize_t received = ::recv(_fd, ptr + total,
                              sizeof(networkSize) - total, 0);

    if (received <= 0)
      return -1;

    total += received;
  }

  size = ntohl(networkSize);

  return total;
}

ssize_t Socket::receivePayload(std::string& msg, uint32_t size)
{
  msg.resize(size);
  ssize_t total = 0;

  while (total < size)
  {
    ssize_t recvd = ::recv(_fd, msg.data() + total, size - total, 0);

    if (recvd <= 0)
      return -1;

    total += recvd;
  }

  return total;
}
ssize_t Socket::receive(std::string& msg)
{
  uint32_t size;

  if (receiveHeader(size) < 0)
    return -1;

  return receivePayload(msg, size);
}

int Socket::bind(const struct sockaddr* addr, socklen_t addrlen)
{
  return ::bind(_fd, addr, addrlen);
}

int Socket::listen(int backlog)
{
  return ::listen(_fd, backlog);
}

int Socket::accept()
{
  return ::accept(_fd, nullptr, nullptr);
}

int Socket::connect(std::string addrStr)
{
  sockaddr_in addr{};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  inet_pton(AF_INET, addrStr.data(), &addr.sin_addr);

  return ::connect(_fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
}

void Socket::close()
{
  if (_fd != -1)
  {
    ::close(_fd);
    _fd = -1;
  }
}
