#include "path.hh"
#include <iostream>
#include <ctime>

Path::Path(size_t n, size_t x_max, size_t y_max){
	size_t Sx,Sy;
	srand(time(NULL));
	Sx = rand()%x_max;
	Sy = rand()%y_max;
	start_x = Sx;
	start_y = Sy;
	size=n;
	int j,first_x,first_y;
	path = new Direction[n];
	std::cout<<std::endl;

	for (size_t i = 0; i < n-1;)
	{
		first_x = Sx;  //la position d'origine 
		first_y = Sy;  
		j = rand()%8;
		switch(j){
			case 0: Sy -= 1;break;
			case 1: Sx += 1; Sy -= 1;break;
			case 2: Sx -= 1; Sy -= 1;break;
			case 3: Sy += 1;break;
			case 4: Sx += 1; Sy += 1;break;
			case 5: Sx -= 1; Sy += 1;break;
			case 6: Sx += 1;break;
			case 7: Sx -= 1;break;
		}
       //Pour trouver s'il est hors d' limite
		if( Sx>=0 && Sx < x_max && Sy >= 0 && Sy < y_max ){
			path[i] = (Direction)j;
			i++;
		}else{
			Sx = first_x;
			Sy = first_y;
		}
	}
	std::cout<<std::endl;
}



Path::~Path()
{
	delete [] path;
}

std::string Path::toString() const
{
	std::string p;
	using namespace std;

	for (size_t i = 0; i < size-1 ; i++)
	{
		switch (path[i]){
			case 0 : p.append("S");break;
			case 1 : p.append("SE");break;
			case 2 : p.append("SW");break;
			case 3 : p.append("N");break;
			case 4 : p.append("NE");break;
			case 5 : p.append("NW");break;
			case 6 : p.append("E");break;
			case 7 : p.append("W");break;
		}
		if( i != (size - 2) ){
			p.append("-");
		}
	}
 	return p;
}

void Path::print() const
{
	std::string a = Path::toString();
	std::cout<<"the initial  place is ("<<start_x<<","<<start_y<<") "<< a <<std::endl;
}
