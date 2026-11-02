# Homelab
A program you can run on your homelab and connect to from anywhere
Uses TCP sockets to connect devices over WAN
# Compatability
- Designed specifically for linux installations
- This repo is being tested on an Arch Linux install
- It may or may not work on other Linux distributions
    - You are welcome to make a pull request to add compatibility for another distribution
# Install Instructions
## Prerequisites
### Build
- Have the following installed:
    - GCC or Clang with C++26 support
    - CMake version 3.24 or newer
    - Ninja build generator
    - GNU Make
### Deployment
- Systemd enabled and running
- `sudo` privileges
- Have a linux user and group named `server`
  - `server` should not have sudo privileges

## Configuring Prerequisites
```bash
sudo pacman -S cmake ninja clang make
sudo useradd --system --create-home --user-group server
```
- **NOTE**: configuring `systemd` is the user's responsibility
## Installing
- Clone and enter the repository:
``` bash
git clone https://github.com/c-macgillivary/homelab.git
cd homelab
```
- Install the service and compile the binary
``` bash
make deploy
```
