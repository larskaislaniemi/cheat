#ifndef POINT_H
#define POINT_H

#include "CHeat.hpp"
#include "Exceptions.hpp"
#include <vector>

using namespace std;

template <class T>
class Point {
	private:
	vector<T> x;
	size_t dimensions;

	public:
	Point(initializer_list<T> s);
	Point(size_t n);
	Point();
	~Point();
	//Point(const Point<T>& a);
	const size_t dim () const;
	
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	//Point<T>& operator=(const Point<T>&);

	const T prod(size_t, size_t) const;
	const T prod(size_t) const;
	const T prod() const;

};

#endif
