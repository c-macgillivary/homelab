#include "Client.h"

Client::Client(int fd) :
  _socket(fd)
{
}

void Client::serve()
{
  bool running = true;
  while (running)
  {
    char buf[1024] = { 0 };
    ssize_t bytes = _socket.receive(buf, sizeof(buf));
    if (bytes == 0)
      running = false;
    else
    {
      _socket.send(buf, bytes);
    }
  }
}
