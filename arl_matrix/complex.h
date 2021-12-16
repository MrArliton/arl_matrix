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
		friend std::ostream& operator<<(std::ostream& out, complex two) {
			out << two.r << "+i*" << two.i << "\n";
			return out;
		}
		void operator=(complex cd);
	};
	
}

