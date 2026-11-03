#ifndef CLIENT_H
#define CLIENT_H

#include "Socket.h"
#include <string>

class Client
{
private:
  Socket _socket;

public:
  Client();

  int connect(std::string addrStr);
};

#endif
