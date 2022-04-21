

#include <iostream>
#include "mat_a.h"
#include "Algoritms.h"
#include "complex.h"
#include "plm.h"
#include "interpole.h"
using namespace amath;


int main()
{
	printAll();
	
}
/*std::cout << "Complex\n";
	complex** ms = new complex*[2];
	ms[0] = new complex[2];
	ms[1] = new complex[2];
	ms[0][0] = 0; ms[0][1] = 1;
	ms[1][0] = 4; ms[1][1] = complex(3,2);

	mat_a<complex> a1(ms,2,2);
	std::cout << a1 << "\n";
	std::cout << a1.get_determinant() << "\n";
	std::cout << "Polimons" << "\n";
	plm** pl = new plm*[2];
	double a[3] = { 1,2,3 };
	pl[0] = new plm[2];
	pl[1] = new plm[2];
	pl[0][0] = plm(a, 2);
	pl[0][1] = plm(a, 2);
	pl[1][0] = plm(a, 2);
	pl[1][1] = plm(a, 2);
	mat_a<plm> pls(pl,2,2);
	plm** pl1 = new plm * [2];
	double ad[3] = { 2,2,1 };
	double ad2[3] = { 1,1,1 };
	pl1[0] = new plm[2];
	pl1[1] = new plm[2];
	pl1[0][0] = plm(ad, 2);
	pl1[0][1] = plm(ad, 2);
	pl1[1][0] = plm(ad2, 2);
	pl1[1][1] = plm(ad, 2);
	mat_a<plm> pls1(pl1, 2, 2);
	std::cout << "First" << "\n";
	std::cout << pls << "\n";
	std::cout << "Second" << "\n";
	std::cout << pls1 << "\n";
	std::cout << "Sum" << "\n";
	std::cout << pls+pls1 << "\n";
	std::cout << "Multiplication" << "\n";
	std::cout << pls * pls1 << "\n";
	*/

//mat a("C:\\Users\\MrArl\\source\\repos_education\\TestEducation\\Files\\matrix1.txt");
	//mat b("C:\\Users\\MrArl\\source\\repos_education\\TestEducation\\Files\\matrix2.txt");
//	std::cout << a << "\n" << b << "\n";
//	mat x = a.get_reverse_nw()*b;
	//std::cout << a*a.get_reverse_nw() << "\n";
	//std::cout << a.get_determinant()<< "\n";
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

