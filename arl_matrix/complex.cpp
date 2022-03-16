#include "complex.h"
using namespace amath;
complex::complex(double r,double i) {
	this->r = r;
	this->i = i;
}

complex::complex(double r) {
	this->r = r;
	this->i = 0;
}
complex::complex() {
	r = 0;
	i = 0;   
}
complex complex::getCC() {
	return complex(r, -i);
}

//operators
complex& complex::operator=(complex d){ 
	this->r = d.r;
	this->i = d.i;
	return *this;
}
