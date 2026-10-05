#include <CommandRegistry.h>

int CommandRegistry::registerCommand(std::string name, Creator creator)
{
  if (map().contains(name))
    return -1;
  map()[name] = creator;
  return 0;
}

std::unique_ptr<Command> CommandRegistry::parse(std::string command)
{
  if (map().contains(command))
    return map()[command]();

  return nullptr;
}

std::string CommandRegistry::getCommandsList()
{
  std::string s = "";
  for (const auto& [key, value] : map())
    s += "\t" + key + "\n";

  s += "\n";
  return s;
}

std::unordered_map<std::string, CommandRegistry::Creator> CommandRegistry::map()
{
  static std::unordered_map<std::string, Creator> map;
  return map;
}
