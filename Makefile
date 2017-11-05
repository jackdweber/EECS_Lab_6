#	Author: John Gibbons
#	Date: 2016.10.26

prog: main.o
	g++ -g -Wall -std=c++11 main.o test.o LinkedListOfInts.o -o prog

test.o: test.cpp test.h
	g++ -g -Wall -std=c++11 -c test.cpp

main.o: main.cpp 
	g++ -g -Wall -std=c++11 -c main.cpp



#Add needed Test.o recipe and compiler command


#DON'T delete LinkedList.o!
clean:
	rm main.o *.*~ prog
