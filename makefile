install: BinaryRelation

BinaryRelation: Relation.o main.o
	g++ -o BinaryRelation Relation.o main.o -std=c++11

main.o:
	g++ -c -o main.o main.cpp -std=c++11

Relation.o: Relation.h
	g++ -c -o Relation.o Relation.cpp -std=c++11

clean:
	rm Relation.o main.o BinaryRelation