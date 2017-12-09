# AssignmentManager-salketbi1
This is an application that can be use to keep track of assigned homework with a todo list to stay organize.

## Input/Output
[project04.cpp lines 28-263] ([/project04.cpp#L28](/project04.cpp#L28 "project04.cpp#L28"))

[date.cpp line 17] ([/date.cpp#L17](/date.cpp#L17 "date.cpp#L17"))

[todolist.cpp lines 91-99] ([/todolist.cpp#L91](/todolist.cpp#L91 "todolist.cpp#L91"))

[assignment.cpp lines 38-56] ([/assignment.cpp#L38](/assignment.cpp#L38 "assignment.cpp#L38"))

For input I read the input with getline() into string variables. For the output cout is used.

## Control Flow
[project04.cpp lines 27-238] ([/project04.cpp#L27](/project04.cpp#L27 "project04.cpp#L27"))

[assignment.cpp line 53] ([/assignment.cpp#L53](/assignment.cpp#L53 "assignment.cpp#L53"))

[todolist.cpp lines 13-97] ([/todolist.cpp#L13](/todolist.cpp#L13 "todolist.cpp#L13"))

If/else and one switch statement is used for the decision making of my application to direct the the user to the correct output.
 
## Iteration
[project04.cpp lines 22-240] ([/project04.cpp#L22](/project04.cpp#L22 "project04.cpp#L22"))

[assignment.cpp lines 37,49] ([/assignment.cpp#L37](/assignment.cpp#L37 "assignment.cpp#L37"))

[todolist.cpp lines 16,82,92] ([/todolist.cpp#L16](/todolist.cpp#L16 "todolist.cpp#L16"))

For the iteration in the program I use while and for loops. I use for loop for iterate the vector of assignments and in the display() for assignment to print asterisks to represent the priority using the int value in priority.

## Data Structure
[todolist.cpp lines 33,45] ([/todolist.cpp#L33](/todolist.cpp#L33 "todolist.cpp#L33"))

The applicaation is build around a vector data structure that store dynmically Assignment objects at the run time. In todolist.cpp the program push assignment objects to the vector and also to remove them.

## Function
[date.cpp lines 2-18] ([/date.cpp#L2](/date.cpp#L2 "date.cpp#L2"))

[assignment.cpp lines 7-57] ([/assignment.cpp#L7](/assignment.cpp#L7 "assignment.cpp#L7"))

[todolist.cpp lines 2-103] ([/todolist.cpp#L2](/todolist.cpp#L2 "todolist.cpp#L2"))

[project04.cpp lines 134-269] ([/project04.cpp#L134](/project04.cpp#L134 "project04.cpp#L134"))

In the main() i use functions to get user input and validate it. Also I use void function for displayinga banner and a menu. In my classes I keept the private datas private and make public functions to get them and in the TodoList class some void functions to modify the vector for assignments. 

## File IO
[todolist.cpp lines 13-40, 78-86] ([/todolist.cpp#L13](/todolist.cpp#L13 "todolist.cpp#L13"))

I create ofstream and ifstream objects so the program will save the data when it close and read in data when it open.

## Class
[date.h line 10] ([/date.h#L10](/date.h#L10 "date.h#L10"))

[assignment.h line 6] ([/assignment.h#L6](/assignment.h#L6 "assignment.h#L6"))

[todolist.h line 11] ([/todolist.h#L11](/todolist.h#L11 "todolist.hL11"))

The application is made of a TodoList class that rely on an Assignment class that also uses a Date class.
