# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g
LIB_DIR = ../lib
LIB_SRC = $(LIB_DIR)/helper.cpp
LIB_OBJ = $(LIB_SRC:.cpp=.o)

all: lib

lib: $(LIB_OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJ)
