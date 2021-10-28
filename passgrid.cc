#include "passgrid.hh"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <fstream>
#include<time.h>
using namespace std;
// obtain a seed from the system clock:
std::default_random_engine PassGrid::_generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> PassGrid::_distribution(33,94);


PassGrid::PassGrid(const PassGrid & p)
{
    _w = p.getW();
    _h = p.getH();
    grid = new char *[_h];
    for(size_t i = 0; i < _h; i++ ){
      grid[i] = new char[_w];
    }
    for (size_t i = 0; i < p.getH(); i++)  
    {
      for (size_t j = 0; j < p.getW(); j++)
      {
        grid[i][j] = p(i,j);
      }
    }
}

PassGrid::PassGrid(std::size_t w, std::size_t h)
{

  	_h = h;
  	_w = w;
  	grid = new char *[_h];
  	for(size_t i = 0; i < _h; i++ ){
  		grid[i] = new char[_w];
  	}
    srand(time(NULL));
    reset();
}

PassGrid::~PassGrid()
{
  for(size_t i=0; i< _h; i++){  
    delete [] grid[i];
  }
  delete [] grid;
}


void PassGrid::save(std::ostream& out) const
{
    for (size_t i = 0; i < _h; i++)
    {
      for (size_t j = 0; j < _w; j++)
      {
        out << grid[i][j] << '\t';
      }
      out << std::endl;
    }
}

void PassGrid::print() const
{
  	for (size_t i = 0; i < _h; i++ ){
  		for (size_t j = 0; j < _w; j++ ){
  			std::cout << grid[i][j] << " " ;
  		}
  		
  	}

}

void PassGrid::load(std::istream& in)
{
  	for (size_t i = 0; i < _h; i++)
    {
      for (size_t j = 0; j < _w; j++)
      {
        in >> grid[i][j];
      }
    }
}

void PassGrid::reset()
{
    srand(time(NULL));
  	for(size_t i = 0; i < _h; i++ ){
  		for(size_t j = 0; j < _w; j++){
        while(1){
          grid[i][j] = _distribution(_generator);
          if( (int)grid[i][j] != 38 && (int)grid[i][j] != 60 ){
            break;
          }
  		  }
      }
  	}

}


std::string PassGrid::generate(const Path& p)const
{
  size_t w = p.getStartX();
  size_t h = p.getStartY();
  std::string password;
  char *a = new char[p.getSize()+1];
  a[0] = grid[h][w];
  for (size_t i = 0; i < p.getSize()-1 ; i++)
  {
      switch (p(i)){
      case 0: h -= 1; a[i+1] = grid[h][w];break;
      case 1: w += 1; h -= 1;a[i+1] = grid[h][w];break;
      case 2: w -= 1; h -= 1;a[i+1] = grid[h][w];break;
      case 3: h += 1; a[i+1] = grid[h][w];break;
      case 4: w += 1; h += 1;a[i+1] = grid[h][w];break;
      case 5: w -= 1; h += 1;a[i+1] = grid[h][w];break;
      case 6: w += 1; a[i+1] = grid[h][w];break;
      case 7: w -= 1; a[i+1] = grid[h][w];break;
    }
  }
  password.append(a);
  return password;
}

