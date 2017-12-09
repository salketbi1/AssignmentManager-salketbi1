#ifndef TODOLIST_H
#define TODOLIST_H

#include "assignment.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class TodoList
{
  private:
    vector<Assignment> assignments;
    int size;
    int completedAssignments;
  public:
    TodoList();
    int getCompleted();
    int getSize();
    void addAssignment(Assignment a);
    void removeAssignment(int i);
    void markCompleted(int i);
    void display();
    void save();
};

#endif
