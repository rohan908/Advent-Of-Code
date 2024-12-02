# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g
INCLUDES = -I../../lib
LIB_OBJ = ../../lib/helper.o

# Source files and target
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJECTS) $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LIB_OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
