#ifndef COMMAND_H
#define COMMAND_H

#include "Socket.h"
#include <string>
#include <vector>

class Command
{
public:
  virtual int execute(const std::vector<std::string>& args, Socket& client) = 0;
  virtual ~Command() = default;
};

#endif
