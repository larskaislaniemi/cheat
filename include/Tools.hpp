#ifndef TOOLS_H
#define TOOLS_H

#include <vector>

using namespace std;

// Product of all (numeric) elements within the vector
template <typename T_num> T_num elemProd (vector<T_num>& v, unsigned int arrFrom, unsigned int arrTo);
template <typename T_num> T_num elemProd (vector<T_num>& v, unsigned int arrFrom);
template <typename T_num> T_num elemProd (vector<T_num>& v);


#endif
