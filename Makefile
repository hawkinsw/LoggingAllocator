CC=g++
#CC=clang++

all: string_test vector_test

string_test: string_main.cpp alloc.h
	$(CC) -o string_test string_main.cpp -g -O0 -std=c++17

vector_test: vector_main.cpp alloc.h
	$(CC) -o vector_test vector_main.cpp -g -O0 -std=c++17

alloc.h:
	true

clean:
	rm -f string_test vector_test *.o core
