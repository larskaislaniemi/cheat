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

	nx[IX] = 10; nx[IY] = 10; nx[IZ] = 40;
	L[IX] = 50e3; L[IY] = 50e3; L[IZ] = 100e3;

	cr = new Crust(nx, L);

	cr->addField("temperature");
	cr->addField("heat conductivity");
	cr->addField("heat capacity");
	cr->addField("density");

	cr->getField("temperature")->setValues(setIniTemp_cb, vector<real>{ 1, 10.0 });
	cr->getField("heat conductivity")->setValues(setConstValue_cb, vector<real>{ 2.5 });
	cr->getField("heat capacity")->setValues(setConstValue_cb, vector<real>{ 800 });
	cr->getField("density")->setValues(setConstValue_cb, vector<real>{ 2800 });

	delete cr;

	return 0;
}

/* Examples of usage */
/*
	x[idz] = 4;  x[idx] = 5;  x[idy] = 2;
	Point<int> xx {1,2,3};
	cr->deleteField("test");
	cr->getField("koe")->setValues(cb_iniTemp, vector<real> { L[0] });

*/
