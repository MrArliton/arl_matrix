﻿

#include <iostream>
#include "matrix.h"
#include "Algoritms.h"
#include "complex.h"
#include "plm.h"
//#include "interpol.h"
using namespace amath;
#include "interpol.h"
int main()
{
	mat a("C:\\Users\\MrArl\\source\\repos_education\\TestEducation\\Files\\matrix1.txt");
	mat b("C:\\Users\\MrArl\\source\\repos_education\\TestEducation\\Files\\matrix2.txt");
//	std::cout << a << "\n" << b << "\n";
//	mat x = a.get_reverse_nw()*b;
	std::cout << a*a.get_reverse_nw() << "\n";
	std::cout << a.get_determinant()<< "\n";
	//std::cout << a.get_determinant();
//	std::cout << x <<" " << "\n";
	//double a[] = { 1,2,8 };
	//double b[] = { 1,2,4 };
	//amath::plm t(a,2);
	//amath::plm r(b,2);
	//std::cout << t << "\n" << r << "\n";
	//amath::plm g = (t * r);
	//std::cout << g << "\n";
	//
//	char alpha[] = { 'a', 'b', 'c', 'd' };
//	int cod[] = {0,1,2,-1};
//	int* s = new int[8];
//	s[0] = 0; s[1] = 3; s[2] = 2; s[3] = 1;
//	s[4] = 2; s[5] = 3; s[6] = 1; s[7] = -1;
//	for (int i = 0; i < 7; i++) {
//		std::cout << alpha[s[i]] << " ";
//	}
//	std::cout <<"\n";
//	codingWishener_wm(s,cod,4);
//	for (int i = 0; i < 7; i++) {
//		std::cout << alpha[s[i]] << " ";
//	}
//	std::cout << "\n";
	//decodingWishener_wm(s, cod, 4);
//for(int i = 0;i<7;i++){
//		std::cout << alpha[s[i]] << " ";
//	}

//	printAll();
//	std::cout << amath::cos(10) << "\n";
	//amath::mergeSort(a, 0, 3, 1);
	
	//for(int i = 0;i<4;i++){
//		std::cout << a[i] << " ";
//	}

}
