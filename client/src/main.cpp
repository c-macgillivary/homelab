#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

int main()
{
  system("clear");

  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress));

  std::string str = "";
  while (true)
  {
    std::cout << "Send to server: ";
    getline(std::cin, str);
    send(clientSocket, str.c_str(), str.length(), 0);

    char buf[1024] = { 0 };
    int bytes = recv(clientSocket, buf, sizeof(buf), 0);

    if (bytes > 0)
      std::cout << "Received from server: \"" << buf << "\"" << std::endl;
  }

  return 0;
}
