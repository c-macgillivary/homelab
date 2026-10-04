#include "EchoCommand.h"
#include "CommandRegistry.h"

bool EchoCommand::_registered = CommandRegistry::registerCommand("echo", EchoCommand::createEchoCommand);

int EchoCommand::execute(std::string& args, Socket& client)
{
  args = "print " + args + "\n";
  client.send(args.data(), args.length());

  return 0;
}
