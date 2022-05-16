main: main.o Dictionary.o List.o Node.o Person.o
	g++ -o main main.o List.o Node.o Person.o

tests: tests.o Dictionary.o List.o Node.o Person.o
	g++ -o tests tests.o Dictionary.o List.o Node.o Person.o


main.o: main.cpp Dictionary.h
	g++ -c main.cpp

tests.o: tests.cpp Dictionary.h
	g++ -c tests.cpp


clean:
	rm -f *o main tests
