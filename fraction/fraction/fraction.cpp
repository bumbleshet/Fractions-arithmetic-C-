// Programming assesment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Fraction {

public:
	Fraction(int n = 1, int d = 2) {
		numerator = n;
		denomenator = d;
	}

	Fraction operator+(const Fraction& f) {
		Fraction frac;
		int lcm = findLcm(f.denomenator, denomenator);
		frac.numerator =   ((lcm / denomenator)*numerator)+((lcm / f.denomenator)*f.numerator);
		frac.denomenator = lcm;

		return frac;
	}
	Fraction operator-(const Fraction& f) {
		Fraction frac;
		int lcm = findLcm(f.denomenator, denomenator);
		frac.numerator =  ((lcm / denomenator)*numerator)-((lcm / f.denomenator)*f.numerator);
		frac.denomenator = lcm;
		return frac;
	}
	Fraction operator/(const Fraction& f)const {
		Fraction frac;
		frac.numerator = f.numerator*denomenator;
		frac.denomenator = f.denomenator*numerator;
		return frac;
	}
	Fraction operator*(const Fraction& f)const {
		Fraction frac;
		frac.numerator = f.numerator*numerator;
		frac.denomenator = f.denomenator*denomenator;
		return frac;
	}
	void reduceFactors(Fraction& f) {
		do {
			if (f.numerator % 2 == 0 && f.denomenator % 2 == 0) {
				f.numerator = f.numerator / 2;
				f.denomenator = f.denomenator / 2;
			}

			else if (f.numerator % 3 == 0 && f.denomenator % 3 == 0) {
				f.numerator = f.numerator / 3;
				f.denomenator = f.denomenator / 3;
			}
			else
				break;
		} while (true);

	}

private:

	int numerator;
	int denomenator;
	friend int findLcm(int n1, int n2);
	friend ostream& operator<<(ostream& os, const Fraction& f);
	friend istream& operator>>(istream& is, Fraction& f);
};
istream& operator>>(istream& is, Fraction& f)
	{
		is >> f.numerator >> f.denomenator;
		return is;
	};
ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f.numerator << "/" << f.denomenator;
	return os;
}
int findLcm(int n1, int n2) {
	int max = (n1 > n2) ? n1 : n2; // evaluates if (n1>n2) is true then n1 else n2
	do {
		if (max % n1 == 0 && max % n2 == 0) {
			return max;
			break;
		}
		else
			++max;
	} while (true);
	return max;
}
int main()
{
	Fraction f1(10, 20);
	Fraction f2(11, 20);
	Fraction f3(3, 9);
	cout << f1 << endl;
	cout << f1*f2 << endl;
	cout << f1 + f2 << endl;
	cout << f1 - f2 << endl;
	cout << f1 / f2 << endl;
	f1.reduceFactors(f3);
	cout << f3 << endl;
	cout<<f2-f1;
	system("pause");
	return 0;
}

