#ifndef SERVER_H
#define SERVER_H

class Server
{
private:
  int _socket_fd = -1;
  bool _running = false;

public:
  Server();

  void start();

  void stop();
};

#endif
