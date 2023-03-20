Target = p4.cc

all:$(Target)
	g++ -std=c++11 $(Target) -o main

test:main
	cat input.txt  | ./main > output.txt
