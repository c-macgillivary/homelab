#ifndef ECHO_COMMAND_H
#define ECHO_COMMAND_H

#include "Command.h"
#include <memory>
#include <string>
#include <vector>

class EchoCommand : public Command
{
private:
  static bool _registered;

public:
  int execute(const std::vector<std::string>& args, Socket& client) override;

  static std::unique_ptr<Command> createEchoCommand()
  {
    return std::make_unique<EchoCommand>();
  }
};

#endif
