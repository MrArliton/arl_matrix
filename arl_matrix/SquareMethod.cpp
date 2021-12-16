#include "SquareMethod.h"
double* SquareMethod::getMathematicWaiting(data dt) { // Выборочное
	double* mw = new double[dt.height];
	for (int i = 0; i < dt.height; i++) {
		mw[i] = 0;
		for (int x = 0; x < dt.size; x++) {
			mw[i] += dt.data[i][x];
		}
		mw[i] /= dt.size;
	}
	return mw;
}
double* SquareMethod::getStandartDeviation(data dt, double* mw) { // c наличием мат ожидания
	double* sd = new double[dt.height];
	for (int x = 0; x < dt.height; x++) {
		sd[x] = 0;
		for (int y = 0; y < dt.size; y++) {
			sd[x] += pow((dt.data[x][y] - mw[x]), 2);
		}
		sd[x] = pow(sd[x] / dt.size, 1.0 / 2.0);
	}
	return sd;
}
double SquareMethod::getKoefCorelation(data dt, double* mw, double* sd) {
	double sm = 0;
	for (int i = 0; i < dt.size; i++) {
		sm += ((dt.data[0][i] - mw[0]) * (dt.data[1][i] - mw[1])) / (dt.size * sd[0] * sd[1]);
	}
	return sm;
}
data SquareMethod::getData(const char* path) {
	FILE* file = 0;
	fopen_s(&file, path, "r");
	if (!file) {
		throw "Error";
	}
	data dt;
	fscanf_s(file, "%d %d", &dt.height, &dt.size);
	dt.data = new double* [dt.height];
	for (int i = 0; i < dt.height; i++) {
		dt.data[i] = new double[dt.size];
	}
	for (int h = 0; h < dt.height; h++) {
		for (int i = 0; i < dt.size; i++) {
			fscanf_s(file, "%lf", &dt.data[h][i]);
		}
	}
	return dt;
}
