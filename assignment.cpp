#include "assignment.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Assignment::Assignment(int i, string c, string n, string d, Date dd, int p,
bool com)
: id(i), course(c), name(n), description(d), 
dueDate(dd), priority(p), complete(com)
{
}

string Assignment::getString()
{
  char delim=',';
  ostringstream str;
  
  str << id << delim << course << delim << name << delim << description 
    << delim << priority << delim << dueDate.getString() << delim
    << complete;

  return str.str();
}

bool Assignment::getCompleted()
{
  return complete;
}

void Assignment::markCompleted()
{
  complete = true;
}
void Assignment::display()
{
  for (int i=0;i< priority;i++)
    cout << "*";
  cout << endl;

  cout << "ID #" << id << endl;
  cout << "--Course: " << course << endl;
  cout << "--Name: " << name << endl;
  cout << "--Description: " << description << endl;
  cout << "--Due: ";
  dueDate.display();
  cout << "Priority: ";

  for (int i=0;i<priority;i++)
    cout << "*";
  cout << endl;

  if (complete)
    cout << "[x]" << endl;
  else
    cout << "[ ]" << endl;
}
