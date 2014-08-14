//#include "shape.h"
#include "shape2.h"

#include <iostream>

Shape::~Shape() { }

int main()
{
  Shape *s1 = new Square;
  Shape *s2 = new Circle; 
  Shape *s3 = new Triangle; 
  vector<Shape*> vec;
  vec.reserve(5);

  vec.push_back(s1);
  vec.push_back(s1);
  vec.push_back(s3);
  vec.push_back(s1);
  vec.push_back(s2);

  DrawAllShapes(vec);

  vec.clear();
  delete s1;
  delete s2;
  delete s3;

  return 0;
}
