#include "Algoritms.h"

#include <iostream>
//Other
double amath::min(double x, double y) {
	if (x > y) {
		return y;
	}
	else {
		return x;
	}
}

double amath::max(double x, double y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}
//Sorts
void amath::mergeSort(int *mas,int left,int right,int middle) {
	int *l = new int[middle-left+2];
	int *r = new int[right-middle+1];
	for (int i = 0; i <= middle - left;i++) {
		l[i] = mas[left + i];
		std::cout << l[i] << "\n";
	}
	l[middle - left + 1] = INT32_MAX;
	r[right - middle] = INT32_MAX;
	std::cout <<"----\n";
	for (int i = 1; i <= right - middle;i++) {
		r[i-1] = mas[middle+i];
		std::cout << r[i-1] << "\n";
	}
	int i=0, j = 0;
	for (int e = 0; e <= right-left;e++) {
		if (r[i] < l[j]) {
			mas[left + e] = r[i];
			i += 1;
		}
		else {
			mas[left+e] = l[j];
			j += 1;
		}
	} 
	delete[]r;
	delete[]l;
}
void amath::mergeSort(int* mas, int length){
	int d, i;
	for (i = 2; i < length; i *= 2) {
		for (d = 0; d < length/i; d += 1) {
			mergeSort(mas, i * d, i * d + i-1,min(length,i*d+i/2-1));
			for (int i = 0; i < 10; i++) {
				std::cout << mas[i] << " ";
			}

			std::cout << "\n" << i * d << " " << i * d + i - 1 << " " << i * d + i / 2 - 1 << "\n";
		}
	}
	mergeSort(mas, 0, length-1, length-d-2);
}
//
long long amath::getNOD(long long one, long long two) {
	long long r;
	long long last;
	long long buf;
	if (one > two) {
		 r = two;
		 last = one % two;
	}
	else {
		r = one;
		last = two % one;
	}

	while (true) {
		buf = last;
		last = r % last;
		r = buf;
		if (last == 0) {
			return r;
		}
		
	}
}
//Codings
void amath::codingCeasar_wm(char* str, int ind) {
	int i = 0;
	while (str[i]!=0) {
		if (str[i] == 90) {
			str[i] = 64+ind;
		}
		else if (str[i] == 97) {
		str[i] = 121+ind;
		}
		else {
			str[i] += ind;
		}
		i++;
	}
}
void amath::decodingCeasar_wm(char* str,int ind) {
	int i = 0;
	while(str[i]!=0) {
		if (str[i] == 65) {
			str[i] = 89+ind;
		}
		else if (str[i] == 122) {
			str[i] = 96+ind;
		}
		else {
			str[i] -= ind;
		}
		i++;
	}
}
//Строки обозгначают индексами от 0 до длины-1 алфавита
void amath::codingWishener_wm(int* str, const int* codingWord,int lengthA) {
	int length = 0;
	while (codingWord[length] != -1) {
		length += 1;
	}
	int i = 0;
	while (str[i]!=-1) {
		str[i] = (str[i] + codingWord[i % length])%(lengthA);
		i += 1;
	}

} 
void amath::decodingWishener_wm(int* str,const int* codingWord, int lengthA) {
	int length = 0;
	while (codingWord[length] != -1) {
		length += 1;
	}
	int i = 0;
	while (str[i] != -1) {
		str[i] = (lengthA+str[i] - codingWord[i % length]) % (lengthA);
		i += 1;
	}

}
// Formul of Tealor
double amath::sin(const double& x) {
	double ch = x;
	double otv = x;
	for (int i = 1; i < iterations; i++) {
		ch *= (x * x)/((1+i*2)*(1+i*2-1));
		if (i % 2 == 0) {
			otv += ch;
		}
		else {
			otv -= ch;
		}
	}
	return otv;
}
double amath::cos(const double& x) {
	double ch = 1;
	double otv = 1;
	for (int i = 1; i < iterations; i++) {
		ch *= (x * x) / ((i * 2) * (i * 2 - 1));
		if (i % 2 == 0) {
			otv += ch;
		}
		else {
			otv -= ch;
		}
	}
	return otv;
}