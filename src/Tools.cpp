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
T_num elemProd (vector<T_num>& v, unsigned int arrFrom, unsigned int arrTo) {
	T_num ret;

	if (v.size() <= arrFrom) {
		throw ex_cheatExceptionInvalidParam();
	}

	ret = v[arrFrom];

	for (int i = arrFrom+1; i < arrTo; i++) {
		ret *= v[i];
	}

	return ret;
}
template <typename T_num>
T_num elemProd (vector<T_num>& v, unsigned int arrFrom) {
	return elemProd (v, arrFrom, (unsigned int)(v.size()));
}
template <typename T_num>
T_num elemProd (vector<T_num>& v) {
	return elemProd (v, (unsigned int)0, (unsigned int)(v.size()));
}

template int elemProd<int> (vector<int>& v, unsigned int arrFrom, unsigned int arrTo);
template int elemProd<int> (vector<int>& v, unsigned int arrFrom);
template int elemProd<int> (vector<int>& v);
