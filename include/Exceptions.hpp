#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "CHeat.hpp"
#include <exception>

using namespace std;

class ex_cheatException : public exception {
	virtual const char* what() const throw() { return "CHeat specific exception"; }
};

class ex_cheatExceptionInvalidParam : public ex_cheatException {
	virtual const char* what() const throw() { return "Invalid parameter"; }
};

class ex_cheatExceptionCoordCheck : public ex_cheatException {
	virtual const char* what() const throw() { return "Coordinate check failed"; }
};

class ex_cheatExceptionFieldExists : public ex_cheatException {
	virtual const char* what() const throw() { return "Field exists"; }
};

class ex_cheatExceptionNoSuchField : public ex_cheatException {
	virtual const char* what() const throw() { return "No such field"; }
};

class ex_cheatExceptionNotImplemented : public ex_cheatException {
	virtual const char* what() const throw() { return "Not implemented"; }
};

class ex_cheatExceptionSizeMismatch : public ex_cheatException {
	virtual const char* what() const throw() { return "Grid/array sizes do not match"; }
};

class ex_cheatExceptionDimMismatch : public ex_cheatException {
	virtual const char* what() const throw() { return "Dimensions do not match"; }
};

class ex_cheatExceptionInternalConflict : public ex_cheatException {
	virtual const char* what() const throw() { return "Internal conflict"; }
};

#endif
