#pragma once
#include <iostream>
namespace amath {
	class complex
	{
	private:
		double r;
		double i;
	public:
		complex(double r, double i);
		complex(double r);
		complex();

		complex getCC(); // Complex conjuction
		//Unary
		complex& operator+=(complex cp) {
			r += cp.r;
			i += cp.i;
			return *this;
		}
		complex& operator-=(complex cp) {
			r -= cp.r;
			i -= cp.i;
			return *this;
		}
		complex& operator*=(complex cp) {
			complex  buf = *this * cp;
			this->r = buf.r;
			this->i = buf.i;
			return *this;
		}
		//binary
		friend complex operator+(complex one, complex two) {
			return complex(one.r + two.r, one.i + two.i);
		}
		friend complex operator-(complex one, complex two) {
			return complex(one.r - two.r, one.i - two.i);
		}
		friend complex operator*(complex one, complex two) {
			return complex(one.r * two.r - one.i * two.i, one.r * two.i + one.i * two.r);
		}
		friend complex operator/(complex one, complex two) {
			if (two.i == 0) {
				return complex(one.r / two.r,one.i / two.r);
			}
			else {
				return complex((one*two.getCC())/(two*two.getCC()));
			}
		}
		friend bool operator==(complex one, complex two) {
			if (int(one.r*100000000000000) == int(two.r * 100000000000000) && int(one.i * 100000000000000) == int(two.i * 10000000000000)) {       ///////////// Исправить
				return true;
			}
				return false;
		}
		
		friend std::ostream& operator<<(std::ostream& out, complex two) {
			out << two.r << "+i*" << two.i;
			return out;
		}
		complex& operator=(complex cd);
	};
	
}

