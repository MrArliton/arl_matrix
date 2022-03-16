#pragma once
#include <iostream>
#include <complex.h>
namespace amath {
	template<typename T>
	class mat_a
	{
	private:
		T** matrix;
		unsigned int width;
		unsigned int height;

		int init(unsigned int width, unsigned int height); // allocate memory
		int free(T** m, unsigned int width, unsigned int height); // free memory
		int transpositionLine(unsigned int x1, unsigned int x2, T** matrix, unsigned int width, unsigned int height);
	public:
		mat_a();
		mat_a(T** matrix, unsigned int width, unsigned int height);
		mat_a(unsigned int width, unsigned int height, bool zero);
		//
		const unsigned int get_width();
		const unsigned int get_height();
		//Other methods
		mat_a& transpose();
		T get_determinant();
		// operators unary
		T* operator[](int i);
		bool operator=(const mat_a& matrix);
		// Operators binary
		friend mat_a<T> operator*(const mat_a<T>& mt1, const mat_a<T>& mt2) {
			if (mt1.width != mt2.height) {
				return mat_a<T>();
			}
			T** mats = new T* [mt2.width];
			for (int i = 0; i < mt2.width; i++) {
				mats[i] = new T[mt1.height];
				for (int d = 0; d < mt1.height; d++) {
					mats[i][d] = 0;
				}
			}

			for (int y = 0; y < mt1.height; y++) {
				for (int x = 0; x < mt2.width; x++) {
					for (int i = 0; i < mt1.width; i++) {
						mats[x][y] += mt1.matrix[i][y] * mt2.matrix[x][i];
					}
				}
			}

			return mat_a<T>(mats, mt2.width, mt1.height);
		}
		friend mat_a<T> operator+(const mat_a<T>& mt1, const mat_a<T>& mt2) {
			if (mt1.width != mt2.width || mt1.height != mt2.height) {
				return mat_a<T>();
			}
			T** mats = new T* [mt1.width];
			for (int i = 0; i < mt1.width; i++) {
				mats[i] = new T[mt2.height];
				for (int t = 0; t < mt2.height; t++) {
					mats[i][t] = mt1.matrix[i][t] + mt2.matrix[i][t];
				}
			}
			return mat_a<T>(mats, mt1.width, mt2.height);
		}
		friend mat_a<T> operator-(const mat_a<T>& mt1, const mat_a<T>& mt2) {
			if (mt1.width != mt2.width || mt1.height != mt2.height) {
				return mat_a<T>();
			}
			T** mats = new T* [mt1.width];
			for (int i = 0; i < mt1.width; i++) {
				mats[i] = new T[mt2.height];
				for (int t = 0; t < mt2.height; t++) {
					mats[i][t] = mt1.matrix[i][t] - mt2.matrix[i][t];
				}
			}
			return mat_a<T>(mats, mt1.width, mt2.height);
		}
		friend std::ostream& operator<<(std::ostream& out, const mat_a<T>& matrix) {
			out << matrix.width << " " << matrix.height << "\n";
			if (matrix.matrix != 0) {
				for (int y = 0; y < matrix.height; y++) {
					for (int x = 0; x < matrix.width; x++) {
						out << matrix.matrix[x][y] << " ";
					}
					std::cout << "\n";
				}
			}
			else {
				std::cout << "Matrix undefined.";
			}
			return out;
		}

		~mat_a();
	};
};

