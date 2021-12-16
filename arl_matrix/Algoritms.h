#pragma once
namespace amath {
	long long getNOD(long long one, long long two);
	//Other
	double min(double x, double y);
	double max(double x, double y);
	//Codings
	void codingCeasar_wm(char* str,int ind = 1); // Шифр цезаря кодирование
	void decodingCeasar_wm(char* str, int ind = 1); // Шифр цезаря Декодирование
	void codingWishener_wm(int* str, const int* codingWord, int lengthA); // Шифр цезаря кодирование
	void decodingWishener_wm(int* str, const int* codingWordc, int lengthA); // Шифр цезаря Декодирование
	char* codingWishener(int* str, const char* codingWord,const char* alpha); // Шифр цезаря кодирование выделяет память, освободить память
	char* decodingWishener(int* str, const int* codingWord, const char* alpha); // Шифр цезаря Декодирование выделяет память, освободить память
	//Sort
	void mergeSort(int* mas,int left,int right, int middle);
	void mergeSort(int* mas, int length);
	// Functions realized by Formul of Tealor
#define iterations 10000 // amount of iterations in taylor's formula
	double sin(const double& x);
	double cos(const double& x);
}
