all : dates lists 
	echo "all compiled"

dates : dates.cc CDate.o 
	g++ -Wall -g dates.cc CDate.o -o dates

CDate.o : CDate.cc CDate.h 
	g++ -Wall -g -c CDate.cc -o CDate.o 

linked_list.o : linked_list.cc linked_list.h
	g++ -Wall -g -c linked_list.cc -o linked_list.o

lists.o : lists.cc linked_list.h
	g++ -std=c++11 -Wall -g -c lists.cc -o lists.o

lists : lists.o linked_list.o
	g++ -Wall -g lists.o linked_list.o -o lists 

clean :
	rm -f dates CDate.o linked_list.o lists.o lists
 
