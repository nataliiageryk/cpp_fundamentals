#include "Cpmv.h"
#include <iostream>

using std::cout;
using std::endl;

Cpmv::Cpmv()
{
	cout << "I am a default constructor";
	pi = new Info;
	pi->qcode = "";
	pi->zcode = "";
}
 
Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
	pi = mv.pi;
	mv.pi = nullptr;
	mv.pi->qcode = "";
	mv.pi->zcode = "";
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	if(this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	if(this == &mv)
		return * this;
	pi = mv.pi;
	mv.pi = nullptr;
	mv.pi->qcode = mv.pi->zcode = "";
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	Cpmv tmp;
	tmp.pi = new Info;
	tmp.pi->qcode = pi->qcode + obj.pi->qcode;
	tmp.pi->zcode = pi->zcode + obj.pi->zcode;
	return tmp;
}

void Cpmv::Display() const
{
	cout << "Q code: " << pi->qcode;
	cout << "Z code: " << pi->zcode << endl;
}