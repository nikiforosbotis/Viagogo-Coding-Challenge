grid: event.o ticket.o main.o
	g++ -Wall -g event.o ticket.o main.o -o grid

main.o: main.cpp ticket.h event.h
	g++ -Wall -g -c main.cpp

event.o: event.cpp ticket.h
	g++ -Wall -g -c event.cpp

ticket.o: ticket.cpp ticket.h
	g++ -Wall -g -c ticket.cpp
