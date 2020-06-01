SRC_DIR=src
BUILD_DIR=build

all: objects
	cd $(SRC_DIR) && $(MAKE)
.PHONY=all

objects:
	cd $(SRC_DIR) && $(MAKE) objects
.PHONY=objects

clean:
	cd $(BUILD_DIR) && $(MAKE) clean
.PHONY=clean