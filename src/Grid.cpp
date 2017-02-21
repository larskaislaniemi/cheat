#include "Grid.hpp"
#include "CHeat.hpp"
#include "Exceptions.hpp"
#include "Tools.hpp"
#include <vector>
#include <iostream>

using namespace std;

Grid::~Grid () {
	cout << "Grid removed" << endl;
}

Grid::Grid (vector<int> nx, vector<real> L) {
	cout << "New Grid" << endl;
	vector<int> lx;

	version = 0;

	if (nx.size() != L.size()) {
		throw ex_cheatExceptionInvalidParam();
	}

	this->nx = nx;
	this->L = L;

	this->xs.resize(elemProd(this->nx));

	for (int i = 0; i < elemProd(this->nx); i++) {
		vector<real> curx(this->dim());
		lx = this->lidx(i);

		for (int idim = 0; idim < this->dim(); idim++) {
			curx[idim] = this->L[idim] * (real)(lx[idim]) / (real)((this->nx[idim]-1));
		}

		this->xs[i] = curx;
	}
}

int Grid::size() {
	return elemProd(this->nx);
}

void Grid::checkCoord(vector<int> x) {
	if (x.size() != this->nx.size()) throw ex_cheatExceptionCoordCheck();

	for (int idim = 0; idim < this->dim(); idim++) {
		if (x[idim] < 0 || x[idim] >= this->nx[idim]) throw ex_cheatExceptionCoordCheck();
	}

	return;
}

void Grid::checkCoord(int x) {
	if (x < 0 || x >= elemProd(this->nx)) throw ex_cheatExceptionCoordCheck();
	return;
}

vector<real> Grid::getXs(vector<int> lidx) {
	int gidx;
	
	this->checkCoord(lidx);

	gidx = this->gidx(lidx);

	return this->xs[gidx];
}

int Grid::gidx (vector<int> x) {
	int gcoord = 0;

	this->checkCoord(x);

	for (int idim = 0; idim < this->dim()-1; idim++) {
		gcoord = gcoord + x[idim] * elemProd(this->nx, idim+1);
	}
	gcoord += x[this->dim()-1];

	return gcoord;
}

vector<int> Grid::lidx (int x) {
	vector<int> gx(this->dim());
	int lx = x;

	this->checkCoord(x);

	for (int idim = 0; idim < this->dim()-1; idim++) {
		int ep = elemProd(this->nx, idim+1);
		gx[idim] = (int)(lx / ep);
		lx = lx - gx[idim] * ep;
	}
	gx[this->dim()-1] = lx;

	return gx;
}

int Grid::dim() {
	return (int)(this->nx.size());
}

