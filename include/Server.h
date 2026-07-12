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

  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

  Server(Server&& other);
  Server& operator=(Server&& other);

  void start();

  void stop();
};

#endif
