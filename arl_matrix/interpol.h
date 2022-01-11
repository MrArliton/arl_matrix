#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "math.h"
struct data {
	double** data;
	int size;
	int height;
};


double* getMathematicWaiting(data dt) { // Выборочное
	double* mw =(double*) malloc(sizeof(double) * dt.height);
	for (int i = 0; i < dt.height; i++) {
		mw[i] = 0;
		for (int x = 0; x < dt.size; x++) {
			mw[i] += dt.data[i][x];
		}
		mw[i] /= dt.size;
	}
	return mw;
}

double* getStandartDeviation(data dt,double *mw) { // c наличием мат ожидания
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
data getData(const char* path) {
	FILE* file = 0;
	fopen_s(&file,path,"r");
	//assert(file);
	data dt;
	fscanf_s(file,"%d %d",&dt.height,&dt.size);
	dt.data = new double*[dt.height];
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
//a simple version

double getKoefCorelation(data dt, double* mw,double* sd) {
	double sm = 0;
	for (int i = 0; i < dt.size; i++) {
		sm += ((dt.data[0][i] - mw[0]) * (dt.data[1][i] - mw[1]));
	}
	sm /= (dt.size * sd[0] * sd[1]);
	return sm;
}
double getFuntion(double arg,double * mw,double* sd,double kc) {
	return mw[1] + (sd[1] / sd[0]) * kc * (arg - mw[0]);
}
//
void printAll() {
	data d = getData("C:\\Users\\MrArl\\source\\repos_education\\Interpol\\dat.txt"); // Прописать путь до файлы статистики
	double* mw = getMathematicWaiting(d);
	printf_s("math waiting:%lf %lf\n",mw[0],mw[1]);
	double* sd = getStandartDeviation(d, mw);
	printf_s("standart deviation:%lf %lf\n", sd[0], sd[1]);
	double cor = getKoefCorelation(d, mw, sd);
	printf_s("KoefCorelation:%lf\n",cor);
	printf_s("Argument for predicate:");
	double arg;
	scanf_s("%lf",&arg);
	printf_s("Function value:%lf with arg:%lf\n", getFuntion(arg, mw, sd, cor), arg);
}

//