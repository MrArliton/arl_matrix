#include <vector>
#include "assert.h"
#include <math.h>
#include <iostream>
#include <fstream>

std::vector<double> x;
std::vector<double> y;

std::vector<double> getMathematicWaiting(std::vector<double> x, std::vector<double> y){ // Выборочное
	std::vector<double> buf;
	buf.resize(2);

	buf.at(0) = 0;
		for (int e = 0; e < x.size(); e++) {
			buf.at(0) += x.at(e);
		}
		buf.at(0) /= x.size();
		buf.at(1) = 0;
		for (int e = 0; e < x.size(); e++) {
			buf.at(1) += y.at(e);
		}
		buf.at(1) /= x.size();

	return buf;
}

std::vector<double> getStandartDeviation(std::vector<double> x, std::vector<double> y, std::vector<double> mw) { // c наличием мат ожидания
	std::vector<double> buf;
	buf.resize(2);
	
		buf[0] = 0;
		for (int e = 0; e < x.size(); e++) {
			buf[0] += pow((x.at(e) - mw[0]), 2);
		}
		buf[0] = pow(buf[0] / x.size(), 1.0 / 2.0);
		buf[1] = 0;
		for (int e = 0; e < x.size(); e++) {
			buf[1] += pow((y.at(e) - mw[1]), 2);
		}
		buf[1] = pow(buf[1] / y.size(), 1.0 / 2.0);
	
	return buf;
}
bool getData(const char* path) {
	std::ifstream file(path);
	if(!file) return false;
	//assert(file);
	long size;
	file >> size;
	x.reserve(size);
	y.reserve(size);
	double buf;
		for (int i = 0; i < size; i++) {
			file >> buf;
			x.push_back(buf);
		}
		for (int i = 0; i < size; i++) {
			file >> buf;
			y.push_back(buf);
		}
		return true;
}
//a simple version

double getKoefCorelation(std::vector<double> x, std::vector<double> y, std::vector<double> mw, std::vector<double> sd) {
	double sm = 0;
	for (int i = 0; i < x.size(); i++) {
		sm += ((x[i] - mw[0]) * (y[i] - mw[1]));
	}
	sm /= (x.size() * sd[0] * sd[1]);
	return sm;
}
double getFuntion(double arg, std::vector<double> mw, std::vector<double> sd, double kc) {
	return mw[1] + (sd[1] / sd[0]) * kc * (arg - mw[0]);
}
//
void printAll() {
	getData("C:\\Users\\MrArl\\source\\repos_education\\Interpol\\dat.txt"); // Прописать путь до файлы статистики
	std::vector<double> mw = getMathematicWaiting(x,y);
	printf_s("math waiting:%lf %lf\n", mw[0], mw[1]);
	std::vector<double> sd = getStandartDeviation(x,y, mw);
	printf_s("standart deviation:%lf %lf\n", sd[0], sd[1]);
	double cor = getKoefCorelation(x,y, mw, sd);
	printf_s("KoefCorelation:%lf\n", cor);
	printf_s("Argument for predicate:");
	double arg;
	scanf_s("%lf", &arg);
	printf_s("Function value:%lf with arg:%lf\n", getFuntion(arg, mw, sd, cor), arg);
}

//