#include "Server.h"
#include "Client.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <sys/socket.h>

const unsigned short PORT = 8080;

Server::Server() :
  _socket(-1) // Intialize with an empty socket
{
  system("clear");
  std::cout << "----------------------------------------\nInitializing HomeLab\n\n";

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1)
  {
    std::cout << "ERROR\n";
    perror("socket");
    std::cout << "Aborting server initialization\n\n";
    return;
  }

  _socket = Socket(fd);

  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  _socket.bind(reinterpret_cast<const sockaddr*>(&serverAddress), sizeof(serverAddress));

  _socket.listen(1);

  std::cout << "HomeLab initialized successfully\n----------------------------------------\n";
}

Server::Server(Server&& other) :
  _socket(std::move(other._socket)),
  _client(std::move(other._client)),
  _running(other._running)
{
}

Server& Server::operator=(Server&& other)
{
  if (&other != this)
  {
    _socket.close();
    _socket = std::move(other._socket);

    _client = std::move(other._client);

    _running = other._running;
  }

  return *this;
}

void Server::start()
{
  std::cout << "Starting HomeLab\n\n";

  if (!_socket.isOpen())
  {
    std::cout << "ERROR\nSocket not initialized\nAborting server start\n\n";
    return;
  }

  std::cout << "HomeLab started successfully\n----------------------------------------\n";
  std::cout << "Waiting for client to connect\n\n";

  int client_fd = _socket.accept();
  if (client_fd == -1)
    // Add error handling for failing accepts
    return;

  std::cout << "Client connected\n";

  _client = std::make_unique<Client>(client_fd);

  _client->serve();
}

void Server::stop()
{
}
