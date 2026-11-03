#ifndef PING_COMMAND_H
#define PING_COMMAND_H

#include "Command.h"
#include <memory>
#include <string>

class PingCommand : public Command
{
private:
  static bool _registered;

public:
  int execute(std::string& args, Socket& client) override;

  static std::unique_ptr<Command> createPingCommand()
  {
    return std::make_unique<PingCommand>();
  }
};

#endif
