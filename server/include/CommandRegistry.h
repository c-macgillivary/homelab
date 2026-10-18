#ifndef COMMAND_REGISTRY_H
#define COMMAND_REGISTRY_H

#include <Command.h>
#include <memory>
#include <string>
#include <unordered_map>

class CommandRegistry
{
public:
  using Creator = std::unique_ptr<Command> (*)();

  CommandRegistry() = default;
  CommandRegistry(const CommandRegistry&) = delete;
  CommandRegistry(const CommandRegistry&&) = delete;
  CommandRegistry& operator=(const CommandRegistry&) = delete;
  CommandRegistry& operator=(const CommandRegistry&&) = delete;

  static int registerCommand(std::string name, Creator creator);

  static std::unique_ptr<Command> parse(std::string);

  static std::string getCommandsList();

  static std::unordered_map<std::string, Creator>& map();
};

#endif
