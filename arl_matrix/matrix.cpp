#include "matrix.h"
using namespace amath;
/// Construct 
mat::mat() {
	
}

mat::mat(double** matrix, int width, int height) {
	this->matrix = matrix;
	this->width = width;
	this->height = height;
}

mat::mat(int width, int height, bool zero) {
	init(width,height);
	if (zero) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				matrix[x][y] = 0;
			}
		}
	}
}
//File
mat::mat(const char* path) {
	FILE* file;
	fopen_s(&file,path,"r");
	fscanf_s(file,"%d",&width);
	fscanf_s(file, "%d",&height);
	init(width,height);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			fscanf_s(file,"%lf", &matrix[x][y]);
		}
	}
	fclose(file);
}
bool mat::save(const char* path) {
	FILE* file;
	fopen_s(&file, path, "w");
	if (!file) {
		return 0;
	}
	fprintf(file, "%d %d\n", width, height);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			fprintf_s(file, "%lf ", matrix[x][y]);
		}
		fprintf_s(file, "\n");
	}
	fclose(file);
	return 1;
}
//
int mat::init(int width,int height) {
	if (matrix != 0) {
		return 0;
	}
	this->width = width;
	this->height = height;
	matrix = new double*[width];
	for (int i = 0; i < width; i++) {
		matrix[i] = new double[height];
	}
	return 1;
}
///
// Other Functions
const bool mat::exists() {
	return matrix;
}

mat& mat::transpose() {
	double buf = 0;
	for (int y = 0; y < height; y++) {
		for (int x = y; x < width; x++) {
			buf = matrix[y][x];
			matrix[y][x] = matrix[x][y];
			matrix[x][y] = buf;
		}
	}
	buf = height;
	height = width;
	width = buf;
	return *this;
}
double mat::get_determinant() {
	double otv = 1;
	if (width != height) {
		return -1; // Error with dimension
	}
	double koef;
	double** matrix_n = new double* [width];
	for (int i = 0; i < width; i++) {
		matrix_n[i] = new double[height];
		for (int y = 0; y < height; y++)
			matrix_n[i][y] = matrix[i][y];
	}
	double* buf = new double[width];
	// construct triagnle view 
	for (int x = 0; x < width;x++) { 
		if (((matrix_n[x][x]) == 0) && (x != (width - 1))) {
			int i;
		for (i = 0; i < width; i++) {
				buf[i] = matrix[i][x];
			}
			for (i = 0; i < width; i++) {
				matrix[i][x] = matrix[i][x - 1];;
				matrix[i][x - 1] = buf[i];
			}
		}
		otv *= matrix_n[x][x];         
		for (int y = height-1; y > x; y--) {
			koef = matrix_n[x][y] / matrix_n[x][x];
			if (abs(koef) == INFINITY) {
				otv = 0;
				x = width;
				break;
			}
			for (int i = x; i < width; i++) {
				matrix_n[i][y] -= matrix_n[i][x]*koef;
				
			}
		}
	}
	delete[]buf;
	free(matrix_n,width,height);
	return otv;
}
mat mat::get_reverse_nw() {
	double** matrix_n = new double* [width];
	double** matrix_o = new double* [width];
	for (int i = 0; i < width; i++) {
		matrix_n[i] = new double[height];
		matrix_o[i] = new double[height];
		for (int y = 0; y < height; y++) {
			matrix_n[i][y] = matrix[i][y];
			if (i == y) {
				matrix_o[i][y] = 1;
			}
			else {
				matrix_o[i][y] = 0;
			}
		}
		}
	double koef;
		for (int x = 0; x < width; x++)
		{
			for (int y = x+1; y < height; y++) {
				koef = matrix_n[x][y] / matrix_n[x][x];
				if (koef == INFINITY) {
					delete[]matrix_n;
					delete[]matrix_o;
					return mat();
				}
				for (int i = 0; i < width; i++) {
					matrix_n[i][y] -= matrix_n[i][x] * koef;
					matrix_o[i][y] -= matrix_o[i][x] * koef;
				}

			}
		}
		
		for (int x = width-1; x > 0; x--)
		{
			for (int y = 0; y < x; y++) {
				koef = matrix_n[x][y] / matrix_n[x][x];
				if (koef == INFINITY) {
					delete[]matrix_n;
					delete[]matrix_o;
					return mat();
				}
				for (int i = 0; i < width; i++) {
					matrix_o[i][y] -= matrix_o[i][x] * koef;
				}

			}
		}
		for (int y = 0; y < height; y++) {
			koef = matrix_n[y][y];
			for (int i = 0; i < width; i++) {
				matrix_o[i][y] /= koef;
			}
		}
		delete[]matrix_n;
	return mat(matrix_o,width,height);
}

const int mat::get_width() {
	return width;
}
const int mat::get_height() {
	return height;
}

//operations
bool mat::sum_wm(const mat& mt) {
	if (mt.width != width && mt.height != height) {
		return 0;
	}
	for (int y = 0; y < height;y++) {
		for (int x = 0; x < height;x++) {
			matrix[x][y] += mt.matrix[x][y];
		}
	}
	return true;
}
bool mat::subtraction_wm(const mat& mt) {
	if (mt.width != width && mt.height != height) {
		return false;
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < height; x++) {
			matrix[x][y] -= mt.matrix[x][y];
		}
	}
	return true;
}


// operators unary
double* mat::operator[](int i) {
	return matrix[i];
}

bool mat::operator=(const mat& matrix) {
	if (matrix.matrix == 0) {
		return false;
	}
	free(this->matrix, width, height);
	this->matrix = 0;
	init(matrix.width, matrix.height);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			this->matrix[x][y] = matrix.matrix[x][y];
		}
	}
	
	return true;
}
//
//Destruct
int mat::free(double **m,int width,int height) {
	try {
		if (m == 0) {
			return 0;
		}
		for (int i = 0; i < width;i++) {
			delete[]m[i];
		}
		delete[]m;
		return 1;
	}
	catch(std::exception){
		return 0;
	}
}

mat::~mat() {
	free(matrix,width,height);
	matrix = 0;
}
