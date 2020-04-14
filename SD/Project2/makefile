
sources = main.cpp src/*.cpp
flags = -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
flags_fast = -O2
CSTD = -std=c++11

# optional, we can just work with relative paths
inc = inc/
inc_params = $(foreach d, $(inc), -I$d)

default: main

main:
	g++ $(CSTD) $(flags) $(sources) $(inc_params) -o main.out

fast:
	g++ $(CSTD) $(flags_fast) $(sources) $(inc_params) -o main.out

clean:
	rm *.o
	rm *.out
