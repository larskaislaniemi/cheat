#include "CHeat.hpp"
#include "Point.hpp"

using namespace std;

template <class T>
Point<T>::Point(initializer_list<T> s) : x(s) {
	this->dimensions = s.size();
}

template <class T>
Point<T>::Point(size_t n) {
	this->dimensions = n;
	this->x = vector<T>(n);
}

template <class T>
Point<T>::Point() {
	this->dimensions = 0;
	this->x = vector<T>(0);
}


template <class T>
Point<T>::~Point() { }

template <class T>
T& Point<T>::operator[](size_t idx) { return this->x[idx]; }

template <class T>
const T& Point<T>::operator[](size_t idx) const { return this->x[idx]; }

template <class T>
const size_t Point<T>::dim() const { return this->dimensions; }

/*
template <class T>
Point<T>::Point(const Point<T>& a) {
	this->dimensions = a.dim();
	this->x = vector<T>(this->dimensions);

	for (size_t i = 0; i < a.dim(); i++) {
		this->x[i] = a[i];
	}
}*/

/*
template <class T>
Point<T>& Point<T>::operator=(const Point<T>& b) {
	if (b.dim() != this->dimensions) {
		throw ex_cheatExceptionDimMismatch();
	}
	for (size_t i = 0; i < this->dimensions; i++) {
		this->x[i] = b[i];
	}
	return *this;
}*/


template <class T>
const T Point<T>::prod() const {
	return this->prod(0, this->dimensions);
}

template <class T>
const T Point<T>::prod(size_t from) const {
	return this->prod(from, this->dimensions);
}

template <class T>
const T Point<T>::prod(size_t from, size_t to) const {
	T ini;

	if (this->dimensions <= 0) return 0;

	ini = this->x[from];

	for (size_t i = from+1; i < to; i++) {
		ini = ini * this->x[i];
	}

	return ini;
}

template class Point<real>;
template class Point<int>;

