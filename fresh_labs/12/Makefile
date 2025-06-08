.PHONY: clean build

clean:
	@echo "Cleaning..."
	@rm -rf build

build:
	@echo "Building..."
	@mkdir -p build
	@cd build && cmake .. && cmake --build . -- -j$(nproc)

all: build

.DEFAULT_GOAL := all
