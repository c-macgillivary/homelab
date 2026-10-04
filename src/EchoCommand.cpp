#include "EchoCommand.h"
#include "CommandRegistry.h"

bool EchoCommand::_registered = CommandRegistry::registerCommand("echo", EchoCommand::createEchoCommand);

int EchoCommand::execute(const std::vector<std::string>& args, Socket& client)
{
  if (args.size() > 0)
  {
    std::string s = args[0] + "\n";
    client.send(s.data(), s.length());
  }

  return 0;
}
