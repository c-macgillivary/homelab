#ifndef SOCKET_H
#define SOCKET_H

#include <cstdint>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>

class Socket
{
private:
  int _fd = -1;

  ssize_t sendHeader(uint32_t size);
  ssize_t sendPayload(const std::string& msg);
  ssize_t receiveHeader(uint32_t& size);
  ssize_t receivePayload(std::string& msg, uint32_t size);

public:
  explicit Socket(int fd);

  ~Socket();

  Socket(const Socket&) = delete;
  Socket& operator=(const Socket&) = delete;

  Socket(Socket&& other);
  Socket& operator=(Socket&& other);

  ssize_t send(const std::string& msg);
  ssize_t receive(std::string& msg);

  int bind(const struct sockaddr* addr, socklen_t addrlen);
  int listen(int backlog);
  int accept();
  int connect(std::string addrStr);

  void close();

  bool isOpen()
  {
    return _fd == -1 ? false : true;
  }
};

#endif
