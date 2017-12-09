#include "todolist.h"
TodoList::TodoList() 
: size(0), completedAssignments(0)
{
  int id;
  string course;
  string name;
  string description;
  int month;
  int day;
  bool complete;
  int priority;
  ifstream in("assignments_todo.dat");
  char delim=',';

  while (in>>id)
  {
    in.ignore();
    getline(in,course,',');
    getline(in,name,',');
    getline(in,description,',');
    in >> priority;
    in.ignore();
    in >> month;
    in.ignore();
    in >> day;
    in.ignore();
    in >> complete;
    in.ignore();

    Date tempDate(month,day);
    Assignment tempAssignment(id,course,name,description,tempDate,priority, complete);
    assignments.push_back(tempAssignment);
    size++;

    if (complete)
      completedAssignments++;
  }

  in.close();
}
  
void TodoList::addAssignment(Assignment a)
{
  assignments.push_back(a);
  size++;
}

void TodoList::removeAssignment(int i)
{
  if (assignments[i - 1].getCompleted())
    completedAssignments--;

  assignments.erase(assignments.begin() + (i - 1));
  size--;

}

void TodoList::markCompleted(int i)
{
  if (!assignments[i-1].getCompleted())
  {
    assignments[i-1].markCompleted();
    completedAssignments++;
  }
}

int TodoList::getCompleted()
{
  return completedAssignments;
}

int TodoList::getSize()
{
  return size;
}

void TodoList::save()
{
  ofstream out("assignments_todo.dat");

  for (int i=0;i<assignments.size();i++)
    out << assignments[i].getString() << endl;

  out.close();
}

void TodoList::display()
{
  string ent;
  cout << endl;
  for (int i=0;i<assignments.size();i++)
  {
    assignments[i].display();
    cout << endl;
    
    if (i%2)
    {
      cout << "enter to continue" << endl;
      getline(cin,ent);
    }
  }
}
