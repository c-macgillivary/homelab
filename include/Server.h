#ifndef SERVER_H
#define SERVER_H

class Server
{
private:
  int _socket_fd = -1;
  unsigned short _port = 8080;
  bool _running = false;

public:
  Server(unsigned short port);

  ~Server();

  void start();

  void stop();
};

#endif
