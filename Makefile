#variables
CXX=g++
CFLAGS=-c -std=c++11 -Iinclude
LDFLAGS= -LDependencies/lib
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp
SOURCES+=$(wildcard src/*.cpp)
OBJECTS=$(subst .cpp,.o,$(subst src/,,$(SOURCES)))
EXECUTABLE=life
BINDIR=/bin


all:  makeOBJ
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS)

makeOBJ:
	$(CXX) $(CFLAGS) $(SOURCES)


clean: 
	rm -rf $(OBJECTS) $(EXECUTABLE)
