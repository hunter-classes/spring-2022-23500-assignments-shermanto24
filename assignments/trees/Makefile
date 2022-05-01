main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

tests: tests.o Node.o BSTree.o
	g++ -o tests tests.o Node.o BSTree.o

main.o: main.cpp BSTree.h
	g++ -c main.cpp

tests.o: tests.cpp BSTree.h
	g++ -c tests.cpp

clean:
	rm -f *o main tests
