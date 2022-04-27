main: main.o Stack.o Node.o Queue.o
	g++ -o main main.o Stack.o Node.o Queue.o

tests: tests.o Stack.o Node.o Queue.o
	g++ -o tests tests.o Stack.o Node.o Queue.o


main.o: main.cpp Stack.h Queue.h
	g++ -c main.cpp

tests.o: tests.cpp Stack.h Queue.h
	g++ -c tests.cpp

# Stack.o: Stack.cpp Stack.h Node.h
# 	g++ -c Stack.cpp

# Node.o: Node.o Node.h
# 	g++ -c Node.cpp


clean:
	rm -f *o main tests
