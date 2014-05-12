#include "Port.h"
#include <iostream>
//class Port char * brand; char style[20]; int bottles;

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand,br);

	strncpy(style, st, SIZE-2);
	style[SIZE-1] = '\0';

	bottles = b;
}
	
Port::Port(const Port & p) // copy constructor
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand,p.brand);

	strncpy(style, p.style, SIZE-2);
	style[SIZE-1] = '\0';

	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	delete [] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand,p.brand);

	strncpy(style, p.style, SIZE-2);
	style[SIZE-1] = '\0';

	bottles = p.bottles;
	return *this;
}
	
Port & Port::operator+=(int b) // adds b to bottles
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b) // subtracts b from bottles, if available
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}
	
ostream & operator<<(ostream & os, const Port & p)
{
	cout << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

// VintagePort methods: char * nickname i.e., "The Noble" or "Old Velvet", etc. int year - vintage year
VintagePort::VintagePort() : Port()
{
	nickname = "none";
	year = -1;
}

VintagePort::VintagePort(const char * br, char * st, int b, const char * nn, int y) : Port(br,st,b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);

	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);

	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);

	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << (const Port &) vp << ", " << vp.nickname << ", " << vp.year << endl;
	return os;

}