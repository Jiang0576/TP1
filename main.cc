#include<iostream>
#include<fstream>
#include<string>
#include "passgrid.hh"
using namespace std;
int main()
{
  	PassGrid pg(10,10);
  	pg.print();
  	pg.reset();
  	std::cout << std::endl;
  	pg.print();
  	
  	Path c(8,10,10);
  	c.print();
  	std::cout<<"password : "<< pg.generate(c) << std::endl;

	string filename;
  	filename="ma_grille.svg";
  	pg.draw(filename);

//----------------------------------- test save()
  	// std::cout<<std::endl;
  	// PassGrid copy(pg);
  	// copy.print();

  	// fstream outfile;
  	// outfile.open("data.txt",fstream::out);
  	// if(!outfile){
  	// 	cout<<"open file error\n";
  	// }

  	// copy.save(outfile);
  	// std::cout<<std::endl;

//---------------------------------- test load()
  	// fstream infile;
  	// infile.open("data.txt",fstream::in);
  	// pg.load(infile);
  	// pg.print();  

  	return 0;
}
