#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}

  Point(const int x, const int y) : x{x}, y{y} {}

  Point(const Point &other) :
    x(other.x),
    y(other.y)
  {}

  string getStringPoints()
  {
    ostringstream oss;
    oss << "x= " << x << " y= " << y << endl;
    return oss.str();
  }
};

struct Line
{
  Point *start, *end;

  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line(const Line &other) :
    start(new Point(*other.start) ),
    end(new Point(*other.end) )
  {}

  Line deep_copy() const
  {
    Line newObject = Line(*this);
    return newObject;
  }

  void printLine()
  {
    cout << "start= " << start->getStringPoints();
    cout << "end= "   << end->getStringPoints();
  }
};


