#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
  system("clear");

  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  bool givenServerAddress = argc >= 2;
  std::string serverAddressStr = givenServerAddress ? argv[1] : "127.0.0.1";

  sockaddr_in serverAddress{};
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080);
  inet_pton(AF_INET, serverAddressStr.data(), &serverAddress.sin_addr);

  connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress));

  std::string str = "";
  while (true)
  {
    std::cout << "Send to server: ";
    getline(std::cin, str);
    send(clientSocket, str.c_str(), str.length(), 0);
    if (str == "exit")
      break;

    char buf[1024] = { 0 };
    int bytes = recv(clientSocket, buf, sizeof(buf), 0);

    if (bytes > 0)
      std::cout << "Received from server: \"" << buf << "\"" << std::endl;
  }

  return 0;
}
