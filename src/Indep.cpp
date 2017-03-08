#include "Indep.hpp"
#include "CHeat.hpp"
#include <vector>

using namespace std;

real setIniTemp_cb(Point<real> coord, vector<real> params) {
	if (params[0] == 1) {
		/* linear geotherm */
		return coord[IZ] * params[1];
	} else {
		throw ex_cheatExceptionInvalidParam();
	}
}

real setConstValue_cb(Point<real> coord, vector<real> params) {
	return params[0];
}
