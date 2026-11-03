.PHONY: all configure rserver debug release pull deploy

all: debug release

configure: build/.configured

CMAKE_FILES = $(shell find . -name CMakeLists.txt)

build/.configured: $(CMAKE_FILES) CMakePresets.json
	cmake --preset default
	@touch $@

rserver: configure
	cmake --build --preset release --target server

debug:
	cmake --build --preset debug

release: 
	cmake --build --preset release

pull:
	git pull --ff-only

SERVICE_FILE = deploy/server.service
SYSTEMD_FILE = /etc/systemd/system/server.service

deploy: pull rserver
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
