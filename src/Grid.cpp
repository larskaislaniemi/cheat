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

Grid::Grid (Point<int> nx, Point<real> L) {
	cout << "New Grid" << endl;
	Point<int> lx; 

	version = 0;

	if (nx.dim() != L.dim()) {
		throw ex_cheatExceptionDimMismatch();
	}

	this->nx = nx;
	this->L = L;

	this->xs.resize(this->size());

	for (size_t i = 0; i < this->size(); i++) {
		Point<real> curx(this->dim());
		lx = this->lidx(i);

		for (size_t idim = 0; idim < this->dim(); idim++) {
			curx[idim] = this->L[idim] * (real)(lx[idim]) / (real)((this->nx[idim]-1));
		}

		this->xs[i] = Point<real>(this->dim());
		this->xs[i] = curx;
	}
}

void Grid::checkGridCoord(Point<int> x) {
	if (x.dim() != this->dim()) throw ex_cheatExceptionCoordCheck();

	for (size_t idim = 0; idim < this->dim(); idim++) {
		if (x[idim] < 0 || x[idim] >= this->nx[idim]) throw ex_cheatExceptionCoordCheck();
	}

	return;
}

void Grid::checkGridCoord(size_t x) {
	if (x < 0 || x >= this->size()) throw ex_cheatExceptionCoordCheck();
	return;
}

Point<real> Grid::getXs(Point<int> lidx) {
	size_t gidx;
	
	this->checkGridCoord(lidx);

	gidx = this->gidx(lidx);

	return this->xs[gidx];
}

size_t Grid::gidx (Point<int> x) {
	size_t gcoord = 0;

	this->checkGridCoord(x);

	for (size_t idim = 0; idim < this->dim()-1; idim++) {
		gcoord = gcoord + x[idim] * this->nx.prod(idim+1);
	}
	gcoord += x[this->dim()-1];

	return gcoord;
}

Point<int> Grid::lidx (size_t x) {
	Point<int> gx(this->dim());
	int lx = (int)x;

	this->checkGridCoord(x);

	for (size_t idim = 0; idim < this->dim()-1; idim++) {
		int ep = this->nx.prod(idim+1); 
		gx[idim] = lx / ep;
		lx = lx - gx[idim] * ep;
	}
	gx[this->dim()-1] = lx;

	return gx;
}

size_t Grid::dim() {
	return this->nx.dim();
}

size_t Grid::size() {
	int prod;
	prod = this->nx.prod();
	if (prod < 0) throw ex_cheatExceptionInternalConflict();
	return (size_t)prod;
}
