CXX=g++
CXX_FLAGS=-g

BUILD_DIR=../build
INCLUDES=-I../include

SOURCES=$(wildcard *.cpp)
OBJECTS=$(subst .cpp,.o, $(SOURCES))

all: objects
	cd $(BUILD_DIR) && $(MAKE)
.PHONY=all

objects: $(BUILD_DIR)/$(OBJECTS)
.PHONY=objects

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c $< -o $(BUILD_DIR)/$@
