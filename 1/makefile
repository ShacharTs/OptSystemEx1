CXX = g++
CXXFLAGS = -Wall -g -std=c++17

TARGET = main
SRC = Ex1.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all main clean run debug ddd

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: main
	ulimit -c unlimited && ./$(TARGET)

debug: main
	gdb ./$(TARGET) core

ddd: main
	ddd ./$(TARGET) core

clean:
ifeq ($(OS),Windows_NT)
	del /F /Q $(TARGET).exe $(OBJ)
else
	rm -f $(TARGET) $(OBJ) core
endif
