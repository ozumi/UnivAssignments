
assign_5 : main.o dijkstra.o minheap.o
	g++ -g main.o dijkstra.o minheap.o -o assign_5

main.o : main.cpp dijkstra.h minheap.h
	g++ -g -c  main.cpp -o main.o

dijkstra.o : dijkstra.cpp dijkstra.h
	        g++ -g -c  dijkstra.cpp -o dijkstra.o


minheap.o : minheap.cpp minheap.h
	g++ -g -c  minheap.cpp -o minheap.o
