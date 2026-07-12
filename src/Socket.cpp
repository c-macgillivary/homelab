#include "Socket.h"
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

ssize_t Socket::send(const void* buf, size_t buf_size)
{
  return ::send(_fd, buf, buf_size, 0);
}

ssize_t Socket::receive(void* buf, size_t buf_size)
{
  return recv(_fd, buf, buf_size, 0);
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

void Socket::close()
{
  if (_fd != -1)
  {
    ::close(_fd);
    _fd = -1;
  }
}
