# Homelab
A program you can run on your homelab and connect to from anywhere
Uses TCP sockets to connect devices over WAN
# Compatability
- Designed specifically for linux installations
- This repo is being tested on an Arch Linux install.
- It may or may not work on other Linux distributions.
    - You are welcome to make a pull request to add compatibility for another distribution.
# Install Instructions
## Prerequisites
- Systemd enabled and running
- Have a linux user and group named `server`
    - `server` should not have sudo privileges
- CMake version 3.24 or newer installed
- Ninja build generator installed
### Configuring Prerequisites
```bash
sudo pacman -S cmake ninja
sudo useradd --system --create-home --user-group server
```
## Installing
- Clone the repository:
``` bash
git clone https://github.com/c-macgillivary/homelab.git
```
- Enter the repo:
``` bash
cd homelab-server
```
- Install the service and compile the binary
``` bash
make deploy
```
