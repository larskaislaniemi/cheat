#include "Field.hpp"
#include "CHeat.hpp"
#include "Grid.hpp"
#include "Exceptions.hpp"
#include <vector>
#include <iostream>

using namespace std;

template <class T_fval>
Field<T_fval>::Field(Grid *grid, string fieldName) {
	throw ex_cheatExceptionNotImplemented();
	cout << "New unknown Field " << fieldName << endl;
	this->grid = grid;
	this->fieldName = fieldName;
	this->is_continuous = false;
	this->values = vector<T_fval>(this->grid->size());
}

template <>
Field<int>::Field(Grid *grid, string fieldName) {
	cout << "New int Field " << fieldName << endl;
	this->grid = grid;
	this->fieldName = fieldName;
	this->is_continuous = false;
	this->gridVersion = grid->getVersion();
	this->values = vector<int>(this->grid->size());
}

template <>
Field<real>::Field(Grid *grid, string fieldName) {
	cout << "New real Field " << fieldName << endl;
	this->grid = grid;
	this->fieldName = fieldName;
	this->is_continuous = true;
	this->gridVersion = grid->getVersion();
	this->values = vector<real>(this->grid->size());
}

template <class T_fval>
void Field<T_fval>::setValues(T_fval (&f)(Point<real>, vector<real>), vector<real>params) {
	for (size_t i = 0; i < grid->size(); i++) {
		this->values[i] = f(grid->getXs(grid->lidx(i)), params);
		cout << "z = " << grid->getXs(grid->lidx(i))[0] << ", val = " << this->values[i] << endl;
	}
}

template <class T_fval>
Field<T_fval>::~Field() {
	cout << "Field " << this->fieldName << " removed" << endl;
}

template <class T_fval>
string Field<T_fval>::getName() {
	return this->fieldName;
}

template <class T_fval>
void Field<T_fval>::syncGrid() {
	/* TODO: implement
	   - check if grid version matches field version
	   - if not, interpolate field data from old
	     grid (stored where??) to new grid
	*/

	// for now, we assume everything's just fine
	this->gridVersion = grid->getVersion();
}

template <class T_fval>
T_fval Field<T_fval>::getValue(size_t idx) const {
	return this->values[idx];
}

template <class T_fval>
void Field<T_fval>::setValue(size_t idx, T_fval val) {
	this->values[idx] = val;
}

template <class T_fval>
void Field<T_fval>::operator=(const Field<T_fval> &B) {
	if (B.grid->size() != this->grid->size()) {
		throw ex_cheatExceptionSizeMismatch();
	}
	for (size_t i = 0; i < B.grid->size(); i++) {
		this->setValue(i, B.getValue(i));
	}
}


template class Field<real>;

