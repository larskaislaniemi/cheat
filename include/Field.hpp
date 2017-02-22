#ifndef FIELD_H
#define FIELD_H

#include "CHeat.hpp"
#include "Grid.hpp"
#include <vector>
#include <string>

using namespace std;

template <class T_fval>
class Field {
	private:
	Grid *grid;             // grid with which this field is associated
	string fieldName;       // field name
	vector<T_fval> values;  // field values
	int gridVersion;        // up to which version of grid
	                        //   the field is synced
	void setValue(int, T_fval); // direct access set-value

	public:
	Field<T_fval>(Grid*, string);
	~Field();
	string getName();
	void syncGrid();
	void setValues(T_fval (&)(vector<real>, vector<real>), vector<real>);
	T_fval getValue(int) const;

	void operator=(const Field<T_fval> &B);

	bool is_continuous;
};

#endif
