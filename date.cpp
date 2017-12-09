#include "date.h"
Date::Date(int m, int d) 
: month(m), day(d) {}

string Date::getString()
{
  char delim=',';
  ostringstream str;
  
  str << month << delim << day;

  return str.str();
}

void Date::display()
{
  cout << month << "/" << day << endl;
}
