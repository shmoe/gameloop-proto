CXX=g++
CXX_FLAGS=

BUILD_DIR=../build
INCLUDES=-I../include

SOURCES=$(wildcard *.cpp)
OBJECTS=$(subst .cpp,.o, $(SOURCES))

objects: $(BUILD_DIR)/$(OBJECTS)
.PHONY=objects

%.o: %.cpp
	$(CXX) $(DEBUG) $(CXX_FLAGS) $(INCLUDES) -c $< -o $(BUILD_DIR)/$@
