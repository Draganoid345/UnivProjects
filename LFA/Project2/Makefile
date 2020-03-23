
sources = main.cpp #src/*.cpp
flags = -std=c++11 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
flags_fast = -std=c++11 -O2

# optional, we can just work with relative paths
inc = src/ inc/
inc_params = $(foreach d, $(inc), -I$d)

default: main

main:
	g++ $(flags) $(sources) $(inc_params) -o main.out

fast:
	g++ $(flags_fast) $(sources) $(inc_params) -o main.out

clean:
	rm *.o
	rm *.out
