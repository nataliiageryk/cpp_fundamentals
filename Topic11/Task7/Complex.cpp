#include "Complex.h"

Complex::Complex()
{
	real = imag = 0;
}

Complex::Complex(double a, double b)
{
	real = a;
	imag = b;
}
Complex::~Complex()
{}

Complex Complex::operator+(const Complex & c)
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex & c)
{
	Complex tmp;
	tmp.real = real - c.real;
	tmp.imag = imag - c.imag;
	return tmp;
}

Complex Complex::operator*(const Complex & c)
{
	Complex tmp;
	tmp.real = real * c.real - imag * c.imag;
	tmp.imag = real * c.imag + imag * c.real;
	return tmp;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << "(" << c.real << "," << c.imag << "i)\n";
	return os;
}

Complex operator~(const Complex & c)
{
	Complex tmp;
	tmp.real = c.real;
	tmp.imag = -c.imag;
	return tmp;
}

Complex operator*(double n, const Complex & c)
{
	Complex tmp;
	tmp.real = c.real * n;
	tmp.imag = c.imag * n;
	return tmp;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
	is >> c.real;
	is >> c.imag;
	return is;
}