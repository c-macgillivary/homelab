#ifndef CLIENT_H
#define CLIENT_H

#include "Socket.h"

class Client
{
private:
  Socket _socket;

public:
  explicit Client(int fd);

  void serve();
};

#endif
