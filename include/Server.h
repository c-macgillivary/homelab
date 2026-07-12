#ifndef SERVER_H
#define SERVER_H

class Server
{
private:
  int _socket_fd;
  unsigned short _port;
  bool _running;

public:
  Server(unsigned short port);

  ~Server();

  void start();

  void stop();
};

#endif
