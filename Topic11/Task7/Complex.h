#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
class Complex
{
public:
	Complex();
	Complex(double a, double b);
	~Complex();
	Complex operator+(const Complex & c);
	Complex operator-(const Complex & c);
	Complex operator*(const Complex & c);
	friend std::ostream & operator<<(std::ostream & os, const Complex & c);
	friend std::istream & operator>>(std::istream & os, Complex & c);
	friend Complex operator~(const Complex & c);
	friend Complex operator*(double n, const Complex & c);
private:
	double real;
	double imag;
};

#endif // !COMPLEX_H_
