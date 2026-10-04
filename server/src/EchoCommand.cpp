#include "EchoCommand.h"
#include "CommandRegistry.h"

bool EchoCommand::_registered = CommandRegistry::registerCommand("echo", EchoCommand::createEchoCommand);

int EchoCommand::execute(std::string& args, Socket& client)
{
  client.send("print " + args + "\n");

  return 0;
}
