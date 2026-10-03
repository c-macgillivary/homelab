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
    char buf[1024] = { 0 };
    ssize_t bytes = _socket.receive(buf, sizeof(buf) - 1); // -1 because a \0 must be left at the end to terminate the string

    if (bytes > 0) // No exceptions
    {
      std::string input = buf;
      if (input == "exit")
        running = false;
      else
      {
        std::stringstream ss;
        ss << input;

        std::string command = "";
        getline(ss, command, ' ');

        std::vector<std::string> args;

        while (getline(ss, input, ' '))
          args.push_back(input);

        if (auto cmd = CommandRegistry::parse(command))
          cmd->execute(args);
        else
        {
          std::cout << "Invalid command \"" << command << "\"\nValid commands are:" << std::endl;
          CommandRegistry::printCommandsList();
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
