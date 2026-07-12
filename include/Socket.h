#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <sys/types.h>

class Socket
{
private:
  int _fd = -1;

public:
  explicit Socket(int fd);

  ~Socket();

  Socket(const Socket&) = delete;
  Socket& operator=(const Socket&) = delete;

  Socket(Socket&& other);
  Socket& operator=(Socket&& other);

  ssize_t send(const void* buf, size_t buf_size);
  ssize_t receive(void* buf, size_t buf_size);

  int bind(const struct sockaddr* addr, socklen_t addrlen);
  int listen(int backlog);
  int accept();

  void close();
};

#endif
