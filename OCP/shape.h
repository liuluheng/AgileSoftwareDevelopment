#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <vector>
#include <algorithm>
//#include <typeinfo>

using namespace std;

class Shape {
 public:
  virtual ~Shape();

  virtual void draw() const = 0;
  virtual bool Precedes(const Shape &) const = 0;

  bool operator<(const Shape &s) { return Precedes(s); }

};

class Square : public Shape {
 public:
  void draw() const { cout << "Square" << endl; }
  virtual bool Precedes(const Shape &) const { return false; }

  operator bool() const { return true; }
};

class Circle : public Shape {
 public:
  void draw() const { cout << "Circle" << endl; }
  virtual bool Precedes(const Shape &) const;
};

bool Circle::Precedes(const Shape &s) const
{
  //const Square &sq = dynamic_cast<const Square&>(s);
  if (dynamic_cast<const Square&>(s))
    return true;
  else
    return false;
}

class Triangle: public Shape {
 public:
  void draw() const { cout << "Triangle" << endl; }
  virtual bool Precedes(const Shape &) const { return false; }
};


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
