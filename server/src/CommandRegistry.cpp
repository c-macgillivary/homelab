#include <CommandRegistry.h>
#include <iostream>

std::unordered_map<std::string, CommandRegistry::Creator> CommandRegistry::_map;

int CommandRegistry::registerCommand(std::string name, Creator creator)
{
  if (_map.contains(name))
    return -1;
  _map[name] = creator;
  return 0;
}

std::unique_ptr<Command> CommandRegistry::parse(std::string command)
{
  if (_map.contains(command))
      return _map[command]();

  return nullptr;
}

std::string CommandRegistry::getCommandsList()
{
  std::string s = "";
  for (const auto& [key, value] : _map)
    s += "\t" + key + "\n";

  s+= "\n";
  return s;
}
