FLAGS = -std=c++14

main: main.o funcs.o
	g++ $(FLAGS) -o main main.o funcs.o

tests: tests.o funcs.o
	g++ $(FLAGS) -o tests tests.o funcs.o

main.o: main.cpp funcs.h
	g++ $(FLAGS) -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ $(FLAGS) -c funcs.cpp

tests.o: tests.cpp funcs.h
	g++ $(FLAGS) -c tests.cpp

clean:
	rm funcs.o main.o tests.o
