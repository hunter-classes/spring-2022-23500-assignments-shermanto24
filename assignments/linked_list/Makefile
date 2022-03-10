main: main.o List.o Node.o OList.o ONode.o
	g++ -o main main.o List.o Node.o OList.o ONode.o

tests: tests.o OList.o ONode.o
	g++ -o tests tests.o OList.o ONode.o


main.o: main.cpp OList.h
	g++ -c main.cpp

tests.o: tests.cpp OList.h
	g++ -c tests.cpp


# List.o: List.cpp List.h Node.h
#
# Node.o: Node.cpp Node.h


OList.o: OList.cpp OList.h ONode.h
	g++ -c OList.cpp

ONode.o: ONode.cpp ONode.h
	g++ -c ONode.cpp


clean:
	rm -f *o main tests
