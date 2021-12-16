#pragma once
namespace amath {
	long long getNOD(long long one, long long two);
	//Other
	double min(double x, double y);
	double max(double x, double y);
	//Codings
	void codingCeasar_wm(char* str,int ind = 1); // ���� ������ �����������
	void decodingCeasar_wm(char* str, int ind = 1); // ���� ������ �������������
	void codingWishener_wm(int* str, const int* codingWord, int lengthA); // ���� ������ �����������
	void decodingWishener_wm(int* str, const int* codingWordc, int lengthA); // ���� ������ �������������
	char* codingWishener(int* str, const char* codingWord,const char* alpha); // ���� ������ ����������� �������� ������, ���������� ������
	char* decodingWishener(int* str, const int* codingWord, const char* alpha); // ���� ������ ������������� �������� ������, ���������� ������
	//Sort
	void mergeSort(int* mas,int left,int right, int middle);
	void mergeSort(int* mas, int length);
	// Functions realized by Formul of Tealor
#define iterations 10000 // amount of iterations in taylor's formula
	double sin(const double& x);
	double cos(const double& x);
}
