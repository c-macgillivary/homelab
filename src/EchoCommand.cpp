#include "EchoCommand.h"
#include "CommandRegistry.h"

bool EchoCommand::_registered = CommandRegistry::registerCommand("echo", EchoCommand::createEchoCommand);

int EchoCommand::execute(const std::vector<std::string>& args, Socket& client)
{
  if (args.size() > 0)
    client.send(args[0].c_str(), args[0].length());

  return 0;
}
