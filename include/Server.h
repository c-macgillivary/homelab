#ifndef SERVER_H
#define SERVER_H

#include "Socket.h"
class Server
{
private:
  Socket _socket;
  bool _running = false;

public:
  Server();

  void start();

  void stop();
};

#endif
