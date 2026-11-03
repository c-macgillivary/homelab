.PHONY: all configure dserver dclient rserver rclient client server debug release deploy clean

all: debug release

configure: build/.configured

CMAKE_FILES = $(shell find . -name CMakeLists.txt)

build/.configured: $(CMAKE_FILES) CMakePresets.json
	cmake --preset default
	@touch $@

dserver: configure
	cmake --build --preset debug --target server

dclient: configure
	cmake --build --preset debug --target client

rserver: configure
	cmake --build --preset release --target server

rclient: configure
	cmake --build --preset release --target client

client: dclient rclient

server: dserver rserver

debug: dserver dclient

release: rserver rclient

SERVICE_FILE = deploy/server.service
SYSTEMD_FILE = /etc/systemd/system/server.service

deploy: rserver
	git pull
	@if ! cmp -s $(SERVICE_FILE) $(SYSTEMD_FILE); then \
		echo "Updating systemd service file..."; \
		sudo cp $(SERVICE_FILE) $(SYSTEMD_FILE); \
		sudo systemctl daemon-reload; \
	fi
	sudo cmake --install build --config release
	sudo systemctl enable server
	sudo systemctl restart server


clean:
	rm -rf build/
