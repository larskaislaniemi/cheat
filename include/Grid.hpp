#ifndef GRID_H
#define GRID_H

#include "CHeat.hpp"
#include <vector>

using namespace std;

class Grid {
	private:
	vector<int> nx;	           // num of grid points in each dir
	vector<real> L;            // physical size in each dir
	vector< vector<real> > xs; // physical coordinates, each grid point, each dir
	int version;

	public:
	Grid (vector<int>, vector<real>);
	~Grid();
	int dim();               // dimension of the grid
	int size();		 // total size of the grid

	int gidx(vector<int>);   // global array index from coordinates
	vector<int> lidx(int);   // coordinates from global array index

	vector<real> getXs(vector<int>);  // physical coords at given grid coords

	void checkCoord(vector<int>);  // checks for making sure input coords 
	void checkCoord(int);          //   are valid

	int getVersion() { return this->version; };
};

#endif
