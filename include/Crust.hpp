#ifndef CRUST_H
#define CRUST_H

#include "CHeat.hpp"
#include "Field.hpp"
#include "Grid.hpp"
#include <vector>

using namespace std;

class Crust {
	private:
	Grid *grid;
	vector<Field<real>*> fields;
	vector<int> fieldStatus;

	public:
	Crust(vector<int>, vector<real>);
	~Crust();
	Field<real>* getField(string);
	void syncFieldsGrid();
	void addField(string);
	void deleteField(string);

	
};

#endif
