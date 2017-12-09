p04: date.o assignment.o todolist.o project04.o
	g++ -std=c++11 date.o assignment.o todolist.o project04.o -o project04

project04.o: project04.cpp todolist.h assignment.h
	g++ -std=c++11 -c project04.cpp todolist.h assignment.h

todolist.o: todolist.cpp todolist.h assignment.h
	g++ -std=c++11 -c todolist.cpp todolist.h assignment.h

assignment.o: assignment.cpp assignment.h date.h
	g++ -std=c++11 -c assignment.cpp assignment.h date.h

date.o: date.cpp date.h
	g++ -std=c++11 -c date.cpp date.h

clean:
	rm -f *.o p04


