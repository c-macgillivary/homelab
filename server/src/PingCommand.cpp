#include "PingCommand.h"
#include "CommandRegistry.h"

bool PingCommand::_registered = CommandRegistry::registerCommand("echo", PingCommand::createPingCommand);

int PingCommand::execute(std::string& args, Socket& client)
{
  client.send("print pong\n");
  return 0;
}
