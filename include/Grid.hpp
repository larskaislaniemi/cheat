#ifndef GRID_H
#define GRID_H

#include "CHeat.hpp"
#include "Point.hpp"
#include <vector>

using namespace std;

class Grid {
	private:
	Point<int> nx;             // num of grid points in each dir
	Point<real> L;             // physical size in each dir
	vector< Point<real> > xs;  // physical coordinates, 'Point' for each grid point
	int version;

	public:
	Grid (Point<int>, Point<real>);
	~Grid();
	size_t dim();            // dimension of the grid
	size_t size();		 // total size of the grid

	size_t gidx(Point<int>); // global array index from coordinates
	Point<int> lidx(size_t); // coordinates from global array index

	Point<real> getXs(Point<int>);  // physical coords at given grid coords

	void checkGridCoord(Point<int>);  // checks for making sure input grid 
	void checkGridCoord(size_t);      //   point is valid

	int getVersion() { return this->version; };
};

#endif
