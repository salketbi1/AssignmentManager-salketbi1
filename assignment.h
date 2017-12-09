#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "date.h"

class Assignment
{
  private:
    int id;
    string course;
    string name;
    string description;
    Date dueDate;
    bool complete;
    int priority;
  public:
    Assignment(int i, string c, string n, string d, Date dd, int p,
        bool com = false);
    string getString();
    bool getCompleted();
    void markCompleted();
    void display();
};

#endif
