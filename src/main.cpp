#include <vector>
#include <iostream>
#include "CHeat.hpp"
#include "Crust.hpp"
#include "Indep.hpp"
#include "Point.hpp"


using namespace std;

/*
   MAIN
*/
int main (int argc, char *argv[]) {
	Crust *cr;
	Point<int> nx(3);	// num of grid points
	Point<real> L(3);	// physical size
	Point<int> x(3);	// grid point locator

	Point<int> a, b, c;

	nx[0] = 5; nx[1] = 6; nx[2] = 3;
	L[idz] = 1.0; L[idx] = 1.0; L[idy] = 1.0;
	x[idz] = 4;  x[idx] = 5;  x[idy] = 2;

	Point<int> xx {1,2,3};

	cr = new Crust(nx, L);
	cr->addField("test");
	cr->addField("test2");
	*(cr->getField("test")) = *(cr->getField("test2"));
	cr->deleteField("test");
	delete cr;
	cr = new Crust(nx, L);
	cr->addField("koe");

	cr->getField("koe")->setValues(cb_iniTemp, vector<real> { L[0] });

	a = Point<int>({1,2,3});
	b = Point<int>({4,5,6});
	c = b;
	b[1] = 9;
	cout << c[1] << endl;
	//while(true) {}

	return 0;
}
