CXX = g++

CXXFLAGS = -std=c++23 -Wall -Wextra

.PHONY: all clean

all: matrix

matrix: matrix.o
	$(CXX) $^ -o $@

matrix.o: MatrixMultiplication.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f matrix matrix.o
