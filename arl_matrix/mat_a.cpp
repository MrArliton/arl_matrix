#include "mat_a.h"
#include "complex.h"
#include "plm.h"
using namespace amath;
template mat_a<int>;
template mat_a<double>;
template mat_a<long>;
template mat_a<complex>;
template mat_a<plm>;


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
			delete[] m[i];
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