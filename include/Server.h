#ifndef SERVER_H
#define SERVER_H

class Server
{
private:
  int _socket_fd;
  unsigned short _port;
  bool _running;

public:
  /**
   * Constructor for Server
   */
  Server(unsigned short port);

  /**
   * Destructor for Server
   */
  ~Server();

  /**
   * Start the server
   */
  void start();

  /**
   * Stop the server
   */
  void stop();
};

#endif
