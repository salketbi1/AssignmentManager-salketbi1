#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Date
{
  private:
    int month;
    int day;
  public:
    Date(int m, int d);
    string getString();
    void display();
};

#endif
