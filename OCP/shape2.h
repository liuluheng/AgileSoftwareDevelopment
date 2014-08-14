#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Shape {
 public:
  virtual ~Shape();

  virtual void draw() const = 0;
  bool Precedes(const Shape &) const;

  bool operator<(const Shape &s) { return Precedes(s); }

 private:
  static const char *typeOrderTable[];
};

class Square : public Shape {
 public:
  void draw() const { cout << "Square" << endl; }

  operator bool() const { return true; }
};

class Circle : public Shape {
 public:
  void draw() const { cout << "Circle" << endl; }
};

class Triangle: public Shape {
 public:
  void draw() const { cout << "Triangle" << endl; }
};

const char *Shape::typeOrderTable[] =
{
  typeid(Circle).name(),
  typeid(Square).name(),
  typeid(Triangle).name(),
  nullptr
};

bool Shape::Precedes(const Shape &s) const
{
  const char *thisType = typeid(*this).name();
  const char *argType = typeid(s).name();
  bool done = false;
  int thisOrd = -1;
  int argOrd = -1;

  for (int i = 0; !done; i++) {
    const char *tmp = typeOrderTable[i];
    if (tmp != 0) {
      if (strcmp(tmp, thisType) == 0) {
        thisOrd = i;
      }
      if (strcmp(tmp, argType) == 0) {
        argOrd = i;
      }
      if ((thisOrd >= 0) && (argOrd >= 0)) {
        done = true;
      }
    }
    else {
      done = true;
    }
  }

  return thisOrd < argOrd;
}

template <typename T>
class Lessp {
 public:
  bool operator() (const T p, const T q) { return *p < *q; }
};

void DrawAllShapes(vector<Shape*> &list)
{
  vector<Shape*> orderedList = list;

  sort(orderedList.begin(),
       orderedList.end(),
       Lessp<Shape*>());

  for (auto s : orderedList) {
    s->draw();
  }
}

#endif
