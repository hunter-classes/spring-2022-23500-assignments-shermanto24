main: main.o Stack.o Node.o
	g++ -o main main.o Stack.o Node.o

tests: tests.o Stack.o Node.o
	g++ -o tests tests.o Stack.o Node.o


main.o: main.cpp Stack.h
	g++ -c main.cpp

tests.o: tests.cpp Stack.h
	g++ -c tests.cpp

# Stack.o: Stack.cpp Stack.h Node.h
# 	g++ -c Stack.cpp

# Node.o: Node.o Node.h
# 	g++ -c Node.cpp


clean:
	rm -f *o main tests
