#include <iostream>
#pragma once

// ¬начале объ€вл€ем количество столбцов(width), а потом количество строк(height).
// wm - with me
// nw - allocation memory for new matrix мы создаЄм новую матрицу с выделенной пам€тью
namespace amath {
	class mat {
	private:
		double** matrix = 0;
		int width;
		int height;
		int init(int width, int height); // allocate memory
		int free(double** m, int width, int height); // free memory
		int transpositionLine(int x1, int x2, double** matrix,int width,int height);
	public:

		mat(int width, int height, bool zero);
		mat(const char* path);
		mat(double** matrix, int width, int weight);
		mat();
		bool save(const char* path);
		const int get_width();
		const int get_height();
		//Other methods
		mat& transpose();

		const bool exists(); // check with exists

		// operations
		bool sum_wm(const mat& mt);
		bool subtraction_wm(const mat& mt);
		double get_determinant();
		mat get_reverse_nw();
		// operators unary
		double* operator[](int i);
	//	bool operator=(mat& matrix);
		bool operator=(const mat& matrix);
		// operators binary
		friend mat operator*(const mat& mt1, const mat& mt2) {
			if (mt1.width != mt2.height) {
				return mat();
			}
			double** mats = new double*[mt2.width];
			for (int i = 0; i < mt2.width; i++) {
				mats[i] = new double[mt1.height];
				for (int d = 0; d < mt1.height; d++) {
					mats[i][d] = 0;
				}
			}
			
			for (int y = 0; y < mt1.height;y++) {
				for (int x = 0; x < mt2.width;x++) {
					for (int i = 0; i < mt1.width; i++) {
						mats[x][y] += mt1.matrix[i][y] * mt2.matrix[x][i];
					}
				}
			}

			return mat(mats, mt2.width, mt1.height);
		}
		friend mat operator+(const mat& mt1, const mat& mt2) {
			if (mt1.width != mt2.width || mt1.height != mt2.height) {
				return mat();
			}
			double** mats = new double* [mt1.width];
			for (int i = 0; i < mt1.width; i++) {
				mats[i] = new double[mt2.height];
				for (int t = 0; t < mt2.height; t++) {
					mats[i][t] = mt1.matrix[i][t] + mt2.matrix[i][t];
				}
			}
			return mat(mats, mt1.width, mt2.height);
		}
		friend mat operator-(const mat& mt1, const mat& mt2) {
			if (mt1.width != mt2.width || mt1.height != mt2.height) {
				return mat();
			}
			double** mats = new double* [mt1.width];
			for (int i = 0; i < mt1.width; i++) {
				mats[i] = new double[mt2.height];
				for (int t = 0; t < mt2.height; t++) {
					mats[i][t] = mt1.matrix[i][t] - mt2.matrix[i][t];
				}
			}
			return mat(mats, mt1.width, mt2.height);
		}
		friend std::ostream& operator<<(std::ostream& out , const mat& matrix) {
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
		~mat();
	};
}