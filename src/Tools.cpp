#include "Tools.hpp"
#include "CHeat.hpp"
#include "Exceptions.hpp"
#include <vector>

using namespace std;

/*
   HELPER FUNCTIONS
*/

// Product of all (numeric) elements within the vector
template <typename T_num>
T_num elemProd (vector<T_num>& v, size_t arrFrom, size_t arrTo) {
	T_num ret;

	if (v.size() <= arrFrom) {
		throw ex_cheatExceptionInvalidParam();
	}

	ret = v[arrFrom];

	for (size_t i = arrFrom+1; i < arrTo; i++) {
		ret *= v[i];
	}

	return ret;
}
template <typename T_num>
T_num elemProd (vector<T_num>& v, size_t arrFrom) {
	return elemProd (v, arrFrom, (size_t)(v.size()));
}
template <typename T_num>
T_num elemProd (vector<T_num>& v) {
	return elemProd (v, (size_t)0, (size_t)(v.size()));
}

template int elemProd<int> (vector<int>& v, size_t arrFrom, size_t arrTo);
template int elemProd<int> (vector<int>& v, size_t arrFrom);
template int elemProd<int> (vector<int>& v);
