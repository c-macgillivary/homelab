#include "Client.h"
#include <arpa/inet.h>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

Client::Client() :
  _socket(socket(AF_INET, SOCK_STREAM, 0))
{
}

int Client::connect(std::string addrStr)
{
  int code = _socket.connect(addrStr);

  if (code == -1)
  {
    perror("Error connecting to HomeLab");
    return code;
  }

  system("clear");
  std::cout << "HomeLab Connected" << std::endl;

  std::string input = "";
  while (true)
  {
    std::cout << "❱ ";
    getline(std::cin, input);
    _socket.send(input);
    if (input == "exit")
      break;
    int bytes = _socket.receive(input);

    if (bytes > 0)
    {
      std::string_view sv = input;
      size_t spacePos = sv.find(' ');

      std::string_view command = sv.substr(0, spacePos);
      std::string_view rest = (spacePos == std::string_view::npos) ? "" : sv.substr(spacePos + 1);

      if (command == "print")
      {
        std::cout << rest;
      }
      else
        std::cout << "this is what the server sent:\n\n"
                  << input << std::endl;
    }
  }

  return 0;
}
