all: test

test: main.cpp alloc.h
	g++ -o test main.cpp -g -O0 -std=c++17

alloc.h:
	true
