CXX=g++
CXX_FLAGS=
LDFLAGS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

EXECUTABLE=dk-country
OBJECTS=$(wildcard *.o)

all: $(EXECUTABLE)
.PHONY=all

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

clean:
	rm -f *.o
.PHONY=clean