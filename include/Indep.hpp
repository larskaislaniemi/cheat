#ifndef INDEP_H
#define INDEP_H

#include "CHeat.hpp"
#include "Point.hpp"
#include <vector>

using namespace std;

real setIniTemp_cb(Point<real> coord, vector<real> params);
real setConstValue_cb(Point<real> coord, vector<real> params);

#endif
