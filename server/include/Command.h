#ifndef COMMAND_H
#define COMMAND_H

#include "Socket.h"
#include <string>

class Command
{
public:
  virtual int execute(std::string& args, Socket& client) = 0;
  virtual ~Command() = default;
};

#endif
