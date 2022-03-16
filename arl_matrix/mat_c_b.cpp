#include "mat_a.h"
#include "complex.h"
using namespace amath;
template mat_a<int>;
template mat_a<double>;
template mat_a<long>;
template mat_a<complex>;

template<typename T>
T mat_a<T>::get_determinant() {
	T otv = 1;
	if (width != height) {
		return -1; // Error with dimension
	}
	T koef;
	T** matrix_n = new T * [width];
	for (int i = 0; i < width; i++) {
		matrix_n[i] = new T[height];
		for (int y = 0; y < height; y++)
			matrix_n[i][y] = matrix[i][y];
	}
	T* buf = new T[width];
	// construct triagnle view 
	int d;
	for (int x = 0; x < width; x++) {
		d = x;
		while (matrix_n[d][d] == 0) { // Производим перестановку
			transpositionLine(d, d + 1, matrix_n, width, height);
			otv *= -1;
			d += 1;
		}
		otv *= matrix_n[x][x];
		for (int y = height - 1; y > x; y--) {
			koef = matrix_n[x][y] / matrix_n[x][x];
			if (matrix_n[x][x] == 0) {
				otv = 0;
				x = width;
				break;
			}
			for (int i = x; i < width; i++) {
				matrix_n[i][y] -= matrix_n[i][x] * koef;

			}
		}
	}
	delete[]buf;
	free(matrix_n, width, height);
	return otv;
}