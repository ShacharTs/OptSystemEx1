CXX = g++
CXXFLAGS = -Wall  -std=c++17 -g

TARGET = mandelbrot
SRC = Ex2.cpp
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
