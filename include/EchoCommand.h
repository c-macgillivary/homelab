#ifndef ECHO_COMMAND_H
#define ECHO_COMMAND_H

#include "Command.h"
#include <memory>
#include <string>

class EchoCommand : public Command
{
private:
  static bool _registered;

public:
  int execute(std::string& args, Socket& client) override;

  static std::unique_ptr<Command> createEchoCommand()
  {
    return std::make_unique<EchoCommand>();
  }
};

#endif
