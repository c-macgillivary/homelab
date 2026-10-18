#!/usr/bin/env bash
set -e

# Move to the projects root dir
cd "$(dirname "$0")/.."

# Rebuild and compile the new server
cmake --preset default
cmake --build build --preset release --target server
sudo cmake --install build --config release

# Restart the server service
sudo systemctl restart server
