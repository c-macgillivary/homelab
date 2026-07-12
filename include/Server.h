#ifndef SERVER_H
#define SERVER_H

#include "Client.h"
#include "Socket.h"
#include <memory>

class Server
{
private:
  Socket _socket;
  bool _running = false;
  std::unique_ptr<Client> _client = nullptr;

public:
  Server();

  void start();

  void stop();
};

#endif
