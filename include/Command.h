#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

class Command
{
public:
  virtual int execute(std::vector<std::string> args) = 0;
  virtual ~Command() = default;
};

#endif
