#include <string>
#include "Client.h"

int main(int argc, char** argv)
{
  bool givenAddr = argc >= 2;
  std::string addr = givenAddr ? argv[1] : "127.0.0.1";

  Client client;
  return client.connect(addr);
}
