#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include "path.hh"

class PassGrid{
  public:
    PassGrid(size_t w, size_t h);
    PassGrid(const PassGrid & p);
    ~PassGrid();
    //getter
    std::size_t getW() const {return _w;}
    std::size_t getH() const {return _h;}
    char operator()(size_t i, size_t j) const {return grid[i][j];}
    //Operation
    void reset();
    void save(std::ostream&out) const;
    void load(std::istream&in) ;
    void print() const;
    std::string generate(const Path& p)const ;

  private:
    char ** grid;
    std::size_t _w;
    std::size_t _h;
    static std::default_random_engine _generator;
    static std::uniform_int_distribution<int> _distribution;
    void fillPG();

};
