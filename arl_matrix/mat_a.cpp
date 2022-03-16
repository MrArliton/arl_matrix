#include "mat_a.h"
#include "complex.h"
using namespace amath;
template mat_a<int>;
template mat_a<double>;
template mat_a<complex>;
template mat_a<long>;

template<typename T>
mat_a<T>::mat_a() {

}
template<typename T>
mat_a<T>::mat_a(T** matrix,unsigned int width, unsigned int height) {
	this->matrix = matrix;
	this->width = width;
	this->height = height;
}
template<typename T>
mat_a<T>::mat_a(unsigned int width, unsigned int height, bool zero) {
	init(width, height);
	if (zero) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				matrix[x][y] = 0;
			}
		}
	}
}
//
template<typename T>
const unsigned int  mat_a<T>::get_width() {
	return width;
}
template<typename T>
const unsigned int  mat_a<T>::get_height() {
	return height;
}
//Other methods
template<typename T>
mat_a<T>& mat_a<T>::transpose() {
	T buf = 0;
	for (int y = 0; y < height; y++) {
		for (int x = y; x < width; x++) {
			buf = matrix[y][x];
			matrix[y][x] = matrix[x][y];
			matrix[x][y] = buf;
		}
	}
	unsigned int d;
	d = height;
	height = width;
	width = d;
	return *this;
}
template<typename T>
T mat_a<T>::get_determinant() {
	T otv = 1;
	if (width != height) {
		return -1; // Error with dimension
	}
	T koef;
	T** matrix_n = new T* [width];
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
//
template<typename T>
int mat_a<T>::init(unsigned int width, unsigned int height) {
	if (matrix != 0) {
		return 0;
	}
	this->width = width;
	this->height = height;
	matrix = new T* [width];
	for (int i = 0; i < width; i++) {
		matrix[i] = new T[height];
	}
	return 1;
}
///
// Other Functions
template<typename T>
int mat_a<T>::transpositionLine(unsigned int y1, unsigned int y2, T** matrix, unsigned int width, unsigned int height) {//private
	if (y2 >= height || y1 > y2) {
		return 0;
	}
	T buf;
	for (int i = 0; i < width; i++) {
		buf = matrix[i][y2];
		matrix[i][y2] = matrix[i][y1];
		matrix[i][y1] = buf;
	}
	return 1;
}
//Unary operators
template<typename T>
T* mat_a<T>::operator[](int i) {
	return matrix[i];
}
template<typename T>
bool mat_a<T>::operator=(const mat_a& matrix) {
	if (free(this->matrix, this->width, this->height)) {
		this->matrix = matrix.matrix;
		this->width = matrix.width;
		this->height = matrix.height;
	}
	else {
		return false;
	}
	return true;
}

//
template<typename T>
int mat_a<T>::free(T** m, unsigned int width, unsigned int height) {
	try {
		if (m == 0) {
			return 0;
		}
		for (int i = 0; i < width; i++) {
			delete[]m[i];
		}
		delete[]m;
		return 1;
	}
	catch (std::exception) {
		return 0;
	}
}
template<typename T>
mat_a<T>::~mat_a() {
	if (matrix != 0) {
		free(matrix, width, height);
		matrix = 0;
	}
}