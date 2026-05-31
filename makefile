CXX = clang++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lgtest -lgtest_main

TARGET = matrix_test_tdd
SRC = matrix_test_tdd.cpp
HEADER = matrix.hpp utility.hpp

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC) $(HEADER)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET)
