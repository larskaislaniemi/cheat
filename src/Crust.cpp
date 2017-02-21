#include "Crust.hpp"
#include "Grid.hpp"
#include "CHeat.hpp"
#include "Exceptions.hpp"
#include "Field.hpp"

#include <vector>
#include <iostream>

using namespace std;

Crust::Crust(vector<int> nx, vector<real> L) {
	cout << "New Crust" << endl;
	this->grid = new Grid(nx, L);
}

Crust::~Crust() {
	for (int i = 0; i < this->fields.size(); i++) {
		delete this->fields[i];
	}
	delete this->grid;
	cout << "Crust removed" << endl;
}

Field<real>* Crust::getField(string fieldName) {
	for (int i = 0; i < this->fields.size(); i++) {
		if (this->fields[i]->getName() == fieldName) {
			return this->fields[i];
		}
	}
	throw ex_cheatExceptionNoSuchField();
}

void Crust::syncFieldsGrid() {
	for (int i = 0; i < fields.size(); i++) {
		fields[i]->syncGrid();
	}
}

void Crust::addField(string fieldName) {
	for (int i = 0; i < this->fields.size(); i++) {
		if (fieldName == this->fields[i]->getName()) throw ex_cheatExceptionFieldExists();
	}
	this->fields.resize(this->fields.size() + 1);
	this->fieldStatus.resize(this->fields.size() + 1);
	this->fields[this->fields.size()-1] = new Field<real>(this->grid, fieldName);
	this->fieldStatus[this->fieldStatus.size()-1] = 0;
}

void Crust::deleteField(string fieldName) {
	for (int i = 0; i < this->fields.size(); i++) {
		if (fieldName == this->fields[i]->getName()) {
			delete this->fields[i];
			this->fields.erase(this->fields.begin()+i);
			this->fieldStatus.erase(this->fieldStatus.begin()+i);
			return;
		}
	}

	throw ex_cheatExceptionNoSuchField();
}

