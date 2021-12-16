#pragma once
#include "stdio.h"
#include "math.h"
struct data {
	double** data;
	int size;
	int height;
};
class SquareMethod
{
private:

public:
	double* getMathematicWaiting(data dt);
	data getData(const char* path);
	double getKoefCorelation(data dt, double* mw, double* sd);
	double* getStandartDeviation(data dt, double* mw)

};

