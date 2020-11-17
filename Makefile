SEP=-------------------------------------
BUILD_DIR=build

all: objects executable
.PHONY=all

executable:
	@echo "Building executable..."
	@echo $(SEP)
	$(MAKE) -C $(BUILD_DIR) -f $(BUILD_DIR).mk executable
	@echo "Finished building executable.."
	@echo $(SEP)
.PHONY=executable

objects:
	@echo "Building object files..."
	@echo $(SEP)
	$(MAKE) -C $(BUILD_DIR) -f $(BUILD_DIR).mk objects DEBUG=$(DEBUG)
	@echo "Finished building object files..."
	@echo $(SEP)
.PHONY=objects

debug: DEBUG=-g
debug: all
.PHONY=debug

clean:
	@echo "Cleaning build directory..."
	@echo $(SEP)
	$(MAKE) -C $(BUILD_DIR) -f $(BUILD_DIR).mk clean
	@echo "Finished cleaning..."
	@echo $(SEP)
.PHONY=clean