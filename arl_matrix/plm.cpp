#include "plm.h"
using namespace amath;
plm::plm(const double* koefs,int degree) {
	this->degree = degree + 1;
	this->koefs = new double[this->degree];
	if (koefs[degree] == 0&&degree!=0) {
		throw "error with init plm";
	}
	for (int i = 0; i < this->degree;i++) {
		this->koefs[i] = koefs[i];
	}
}
plm::plm() {
	
}
plm::plm(int number) {
	this->degree = 1;
	this->koefs = new double[this->degree];
	koefs[0] = number;
}
plm::plm(const plm& copy) {
	degree = copy.degree;
	koefs = new double[degree];
	for (int i = 0; i < degree; i++) {
		koefs[i] = copy.koefs[i];
	}
}
/*plm::plm(int degree) {
	this->degree = degree + 1;
	this->koefs = new double[this->degree];
	
}*/
//other
plm& plm::copy(double* koefs, int degree) {
	this->koefs = koefs;
	this->degree = degree;
	return *this;
}
//operators
plm& plm::operator=(const plm& pol1) {
	degree = pol1.degree;
	if (degree == -1) {
		return *this;
	}
	if (degree != -1) {
		free(koefs);
	}
	koefs = new double[degree];
	for (int i = 0; i < degree;i++) {
		koefs[i] = pol1.koefs[i];
	}
	return *this;
}
plm& plm::operator+=(const plm& pol1) {
	if (pol1.degree == -1) {
		return *this;
	}
	if (pol1.degree > degree) {
		double* koefs_b = new double[pol1.degree];
		for (int i = 0; i < degree; i++) {
			koefs_b[i] = koefs[i];
		}
		for (int i = degree; i < pol1.degree; i++) {
			koefs_b[i] = 0;
		}
		free(koefs);
		degree = pol1.degree;
		koefs = koefs_b;
	}
	for (int i = 0; i < degree; i++) {
		koefs[i] += pol1.koefs[i];
	}
	return *this;
}
plm& plm::operator-=(const plm& pol1) {
	if (pol1.degree == -1) {
		return *this;
	}
	if (pol1.degree > degree) {
		double* koefs_b = new double[pol1.degree];
		for (int i = 0; i < degree; i++) {
			koefs_b[i] = koefs[i];
		}
		for (int i = degree; i < pol1.degree; i++) {
			koefs_b[i] = 0;
		}
		free(koefs);
		degree = pol1.degree;
		koefs = koefs_b;
	}
	for (int i = 0; i < degree; i++) {
		koefs[i] -= pol1.koefs[i];
	}
	return *this;
}
plm& plm::operator*=(const plm& pol1) {
	*this = *this * pol1;
	return *this;
}
void plm::free(double* koefs) {
	if (koefs != 0) {
		delete[]koefs;
		koefs = 0;
	}
}

plm::~plm() {
	free(koefs);
	degree = -1;
}
