assign_8 : main.o bst.o rbtree.o
	g++ -g main.o bst.o rbtree.o -o assign_8

main.o : main.cpp bst.h rbtree.h
	g++ -g -c main.cpp -o main.o

bst.o : bst.cpp bst.h
	g++ -g -c bst.cpp -o bst.o

rbtree.o : rbtree.cpp rbtree.h
	g++ -g -c rbtree.cpp -o rbtree.o
