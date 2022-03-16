#pragma once
#include <iostream>
namespace amath {
	
	class plm
	{
		// Важно! Элементы полинома идут от нулевой степени и выше слева на право, а не наоборот как обычно. 
	private:
		double* koefs = 0; // 
		int degree = 0; // Степень указывается на 1 еденицу больше, тоесть если степень полинома 4 то  degree = 5, так как у нас существует ещё нулевая степень
		int print_s = 0;
		void free(double* koefs);
	//	plm(int degree);
		plm& copy(double* koefs, int degree); // copying pointer of koefs
	public:
		plm(const double* koefs, int degree); 
		plm(const plm& copy);
		plm(int number); // полином нулевой степени
		plm();

		// unary operators
		plm& operator=(const plm& pol1);
		plm& operator+=(const plm& pol1);
		plm& operator-=(const plm& pol1);
		plm& operator*=(const plm& pol1);
		// global operators
		friend plm operator*(const plm& pol1,const plm& pol2) {
			int mx, mn;
			double* koefs_nw;
			if (pol1.degree > pol2.degree) {
				mx = pol1.degree;
				mn = pol2.degree;
			}else{
				mx = pol2.degree;
				mn = pol1.degree;
			}
			koefs_nw = new double[mx + mn-1];
			for (int i = 0; i < mx + mn - 1; i++) {
				koefs_nw[i] = 0;
			}
			if (pol1.degree >= pol2.degree) {
				for (int i = 0; i < mx; i++) {
					for (int d = 0; d < mn; d++) {
						koefs_nw[i + d] += pol1.koefs[i] * pol2.koefs[d];
					}
				}
			}
			else {
				for (int i = 0; i < mx; i++) {
					for (int d = 0; d < mn; d++) {
						koefs_nw[i + d] += pol1.koefs[d] * pol2.koefs[i];
					}
				}
			}
			return plm().copy(koefs_nw, mx + mn - 2);
		}
		friend plm operator+(plm& pol1, plm& pol2) {
			int mn, mx;
			double* koefs_nw;
			if (pol1.degree == pol2.degree) { // Если степени полиномов равны, то проверяем на обнуление высшей степени
				mx = pol1.degree;
				for (int i = 1; i < mx; i++) {
					if (pol1.koefs[mx - i] + pol2.koefs[mx - i] == 0) {
						mx -= 1;
					}
					else {
						break;
					}
				}
				koefs_nw = new double[mx];
				for (int i = 0; i < mx; i++) {
					koefs_nw[i] = pol1.koefs[i] + pol2.koefs[i];
				}
			}
			else {
				if (pol1.degree > pol2.degree) { 
					mx = pol1.degree;
					mn = pol2.degree;
				}
				else {
					mn = pol1.degree;
					mx = pol2.degree;
				}
				koefs_nw = new double[mx];
				for (int i = 0; i < mn; i++) { 
					koefs_nw[i] = pol1.koefs[i] + pol2.koefs[i];
				}
				if (pol1.degree > pol2.degree) {
					for (int i = mn; i < mx; i++) {
						koefs_nw[i] = pol1.koefs[i];
					}
				}
				else {
					for (int i = mn; i < mx; i++) {
						koefs_nw[i] = pol2.koefs[i];
					}
				}
			}
			return plm().copy(koefs_nw, mx);
		}
		friend plm operator-(plm& pol1, plm& pol2) {
			int mn, mx;
			double* koefs_nw;
			if (pol1.degree == pol2.degree) {
				mx = pol1.degree;
				for (int i = 1; i < mx; i++) {
					if (pol1.koefs[mx - i] - pol2.koefs[mx - i] == 0) {
						mx -= 1;
					}
					else {
						break;
					}
				}
				koefs_nw = new double[mx];
				for (int i = 0; i < mx; i++) {
					koefs_nw[i] = pol1.koefs[i] - pol2.koefs[i];
				}
			}
			else {
				if (pol1.degree > pol2.degree) {
					mx = pol1.degree;
					mn = pol2.degree;
				}
				else {
					mn = pol1.degree;
					mx = pol2.degree;
				}
				koefs_nw = new double[mx];
				for (int i = 0; i < mn; i++) {
					koefs_nw[i] = pol1.koefs[i] - pol2.koefs[i];
				}
				if (pol1.degree > pol2.degree) {
					for (int i = mn; i < mx; i++) {
						koefs_nw[i] = pol1.koefs[i];
					}
				}
				else {
					for (int i = mn; i < mx; i++) {
						koefs_nw[i] = pol2.koefs[i];
					}
				}
			}
			return plm().copy(koefs_nw, mx);
		}
		friend std::ostream& operator<<(std::ostream& out, plm& pol) {
			out << pol.koefs[0];
			for (int i = 1; i < pol.degree; i++) {
				if (pol.koefs[i] >= 0) {
					out << "+" << pol.koefs[i] << "*x^" << i;
				}
				else {
					out << pol.koefs[i] << "*x^" << i;
				}
			}
			return out;
		}
		friend bool operator==(plm& pol1, plm& pol2) {
			if (pol1.degree == pol2.degree) {
				for (int i = 0; i < pol1.degree; i++) {
					if (pol1.koefs[i] != pol2.koefs[i]) {
						return false;
					}
				}
				return true;
			}
			return false;
		}
		
		~plm();
	};
}

