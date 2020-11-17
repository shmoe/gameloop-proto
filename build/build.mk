CXX=g++
CXX_FLAGS=
LDFLAGS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
INCLUDES=-I../include
SRC_DIR=../src

EXECUTABLE=dk-country
SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(subst .cpp,.o, $(notdir $(SOURCES)))

executable: $(EXECUTABLE)
.PHONY=executable

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(DEBUG) $(CXX_FLAGS) $(INCLUDES) -c $< -o $@

objects: $(OBJECTS)
.PHONY=objects

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
.PHONY=clean