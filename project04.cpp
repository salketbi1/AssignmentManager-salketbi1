#include "todolist.h"
#include "assignment.h"
#include <iostream>

using namespace std;

void banner();
void menu();
bool validInput(char c);
bool validInput(int n);
char getChoice();
int getPriority();
int getID(int size);
Date getDate();
Assignment getAssignment(int size);

int main()
{
  TodoList todo;
  char choice;

  while (tolower(choice)!='q')
  {
    banner();
    menu();

    if (todo.getSize()>0)
      cout << "(" << todo.getCompleted() << " / " << todo.getSize() 
        << " assignments completed)" << endl;

    choice = getChoice();
    
    switch(choice)
    {
      case 'a':
        todo.addAssignment(getAssignment(todo.getSize()));
        cout << "assignment added\n" << endl;
        break;

      case 'r':
        if (todo.getSize()>0)
        {
          todo.removeAssignment(getID(todo.getSize()));
          cout << "assignment removed\n" << endl;
        }

        else
          cout << "no assignments to remove\n" << endl;
        break;

      case 'm':
        if (todo.getSize()>0 && todo.getSize()>todo.getCompleted())
        {
          todo.markCompleted(getID(todo.getSize()));
        }
        else
          cout << "no assignments to mark\n" << endl;
        break;

      case 'v':
        if (todo.getSize()>0)
          todo.display();
        else
          cout << "no assignments to display\n" << endl;
        break;

      case 'q':
        break;

      default:
        cout << "error" << endl;
        break;
    }
  }

  todo.save();
  
  return 0;
}

void banner()
{
  cout << "  ------------------" << endl;
  cout << "< Homework Todo List >" << endl;
  cout << "  ------------------" << endl;
}

void menu()
{
  cout << "::[a]dd assignment" << endl;
  cout << "::[r]emove assignment" << endl;
  cout << "::[m]ark as completed" << endl;
  cout << "::[v]iew assignments " << endl;
  cout << "::[q]uit\n" << endl; 
}

bool validInput(char c)
{
  if (!isalpha(c))
    return false;

  if (!(tolower(c)=='a') && !(tolower(c)=='r') && !(tolower(c)=='m')
        && !(tolower(c)=='v') && !(tolower(c)=='q'))
    return false;

  return true;
}

bool validInput(int n)
{
  return ( (n>0) && (n<6) );
}

char getChoice()
{
  char c;
  string line;

  do{
    cout << "# ";
    getline(cin,line);
    c = line[0];

    if (!validInput(c))
    {
      cout << "choice not understood. ";
      cout << "options: a,r,m,v,q" << endl;
    }
  } while(!validInput(c));

  return c;
}

int getPriority()
{
  string priority;
  bool valid = false;

  do{
    cout << "# ";
    getline(cin,priority);
    
    if (!isdigit(priority[0])||priority.length()!= 1)
      valid = false;
    
    if (validInput(atoi(priority.c_str())))
      return atoi(priority.c_str());
    else
      valid = false;

    if (!valid)
      cout << "priority not understood. options are 1,2,3,4,5." << endl;
  }while(!valid);
}

int getID(int size)
{
  string id;
  bool valid;

  cout <<endl;
  do{
    valid = true;
    cout << "id #: ";
    getline(cin,id);
  
    for (int i=0;i<id.length();i++)
      if (!isdigit(id[i]))
        valid = false;

    if (valid)
    {
      if (atoi(id.c_str())>0 && atoi(id.c_str())<=size)
        valid = true;
      else
        valid = false;
    }

    if (!valid)
    {
      cout << "id not understood. options are (1";

      if (size==1)
        cout << ")" << endl;
      else
        cout << "-" << size << ")" << endl;
    }
    
  }while (!valid);

  return atoi(id.c_str());
}

Date getDate()
{
  string month;
  string day;
  bool valid;

  do{
    valid = true;
    cout << "\tmonth: ";
    getline(cin,month);

    if (month.length()==1 && !isdigit(month[0]))
      valid = false;
    else if (month.length()==2 && (!isdigit(month[0])||!isdigit(month[1])))
      valid = false;
    else if (month.length()>2)
      valid = false;

    if (valid && (atoi(month.c_str())>0 && atoi(month.c_str())<13))
      valid = true;
    else
      valid = false;

    if (!valid)
      cout << "month not understood. options are (1-12)" << endl;
  }while(!valid);

  do{
    valid= true;
    cout << "\tday: ";
    getline(cin,day);
  
    if (day.length()==1 && !isdigit(day[0]))
      valid = false;
    else if (day.length()==2 && (!isdigit(day[0])||!isdigit(day[1])))
      valid = false;
    else if (day.length()>2)
      valid = false;

    if (valid && (atoi(day.c_str())>0 && atoi(day.c_str())<32))
        valid = true;
    else
      valid = false;

    if (!valid)
      cout << "day not understood. options are (1-31)" << endl;
  }while(!valid);

    Date d(atoi(month.c_str()), atoi(day.c_str()));
    
    return d;
}

Assignment getAssignment(int size)
{
  string title;
  string name;
  string desc;
  int p;

  cout << "\ncourse title: ";
  getline(cin,title);
  cout << "assignment name: ";
  getline(cin,name);
  cout << "description: ";
  getline(cin,desc);
  cout << "due date: "<<endl;;
  Date dueDate(getDate());

  cout << "priority (1-5): ";
  p = getPriority();

  Assignment a(size+1,title,name,desc,dueDate,p);

  return a;
}
