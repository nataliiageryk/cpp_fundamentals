#include "ABC.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
// baseABC methods
baseABC::baseABC(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
baseABC::baseABC(const baseABC & rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
baseABC::~baseABC()
{
	delete [] label;
}

baseABC & baseABC::operator=(const baseABC & rs)
{
	if (this == &rs)
		return *this;
	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseABC & rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

// baseDMA methods

baseDMA::~baseDMA()
{
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	baseABC::operator=(rs);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << (const baseABC &)rs;
	return os;
}

void baseDMA::View() const
{
	cout << *this;
	cout << endl;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: baseABC(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseABC & rs) : baseABC(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	os << (const baseABC &) ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

void lacksDMA::View() const
{
	cout << *this;
	cout << endl;
}


// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
	: baseABC(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

	hasDMA::hasDMA(const char * s, const baseDMA & rs)
	: baseABC(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
	: baseABC(hs) // invoke base class copy constructor
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;
	baseABC::operator=(hs); // copy base portion
	delete [] style; // prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	os << (const baseABC &) hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}

void hasDMA::View() const
{
	cout << *this;
	cout << endl;
}
