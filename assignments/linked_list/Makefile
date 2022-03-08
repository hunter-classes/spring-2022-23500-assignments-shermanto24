OBJECTS=main.o List.o Node.o OList.o ONode.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o OList.o ONode.o
	$(CXX) -o main $(OBJECTS)


main.o: main.cpp List.h


List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h


OList.o: OList.cpp OList.h ONode.h

ONode.o: ONode.cpp ONode.h


clean:
	rm -f $(OBJECTS)
