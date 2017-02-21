#include <vector>
#include "CHeat.hpp"
#include "Crust.hpp"
#include "Indep.hpp"


using namespace std;

/*
   MAIN
*/
int main (int argc, char *argv[]) {
	Crust *cr;
	vector<int> nx(3);
	vector<real> L(3);
	vector<int> x(3);
	int gx = 18;


	nx[0] = 5; nx[1] = 6; nx[2] = 3;
	L[idz] = 1.0; L[idx] = 1.0; L[idy] = 1.0;
	x[idz] = 4;  x[idx] = 5;  x[idy] = 2;
	//g = new Grid(nx, L);

	//cout << g->getXs(x)[idz] << " " << g->getXs(x)[idx] << " " << g->getXs(x)[idy] << endl;

	//Field test(g, "testi");

	cr = new Crust(nx, L);
	cr->addField("test");
	cr->addField("test2");
	cr->deleteField("test");
	delete cr;
	cr = new Crust(nx, L);
	cr->addField("koe");

	cr->getField("koe")->setValues(cb_iniTemp, L);

	while(true) {}

	return 0;
}

