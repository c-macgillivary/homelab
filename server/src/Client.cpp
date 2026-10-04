#include "Client.h"
#include "CommandRegistry.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Client::Client(int fd) :
  _socket(fd)
{
}

void Client::serve()
{
  bool running = true;
  while (running)
  {
    std::string input = "";
    ssize_t bytes = _socket.receive(input, 1024);

    if (bytes > 0) // No exceptions
    {
      if (input == "exit")
        running = false;
      else
      {
        size_t pos = input.find(' ');
        std::string command = input.substr(0, pos);
        std::string args = input.substr(pos + 1);

        if (auto cmd = CommandRegistry::parse(command))
          cmd->execute(args, _socket);
        else
        {
          std::string errorMessage = "Invalid command \"" + command + "\"\nValid commands are:\n" + CommandRegistry::getCommandsList();
          _socket.send(errorMessage);
        }
      }
    }
    else if (bytes == 0)
    {
      running = false;
    }
    else
    {
      // Handle socket error
    }
  }
}
