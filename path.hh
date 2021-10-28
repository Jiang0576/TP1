#pragma once
#include<iostream>
#include<cstdlib>
#include <string>

typedef enum  Direction {N, NE, NW , S, SE, SW, E,W}  Direction;
// A Path is build with a size and 2 Bounds
class Path{
  public:
  Path(size_t n, size_t x_max, size_t y_max);
  ~Path();
  std::size_t getSize() const { return size;}
  std::size_t getStartX()const{ return start_x;}
  std::size_t getStartY()const{ return start_y;}
  std::string toString() const;
  void print()const;
  Direction  operator()(size_t i) const{ return path[i];}
 private:
  std::size_t size;
  Direction *path; 
  std::size_t start_x;
  std::size_t start_y;
  
};
