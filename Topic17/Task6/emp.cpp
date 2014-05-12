#include "emp.h"
#include <iostream>
#include <string>
using namespace std;
//class abstr_emp methods
abstr_emp::abstr_emp()
{ }

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
{
	fname = fn;
	lname = ln;
	job = j;
}
abstr_emp::~abstr_emp()
{}

void abstr_emp::Data() const
{
	cout << "First Name: " << fname << " ";
	cout << "Last Name: " << lname << " ";
	cout << "Job: " << job << " ";
}
void abstr_emp::clearLine()
{
	while ( cin.peek() != '\n' )
		cin.get();
	cin.get();
}

void abstr_emp::ShowAll() const // labels and shows all data
{
	Data(); 
	cout << endl;
}

void abstr_emp::SetAll() // prompts user for values
{
	GetData();
}

void abstr_emp::GetData()
{
	cout << "Enter employee info: \n";
	cout << "First Name: ";
	cin >> fname;
	clearLine();
	cout << "Last Name: ";
	cin >> lname;
	clearLine();
	cout << "Job: ";
	cin >> job;
	clearLine();
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	const int type = 0;
	os << type << ": ";
	os << e.fname << " ";
	os << e.lname << " ";
	os << e.job << " ";
	const employee * empPt;
	if (empPt = dynamic_cast<const employee* >(&e))
		operator<<(os,*empPt);
	return os;
}

std::istream &
operator>>(std::istream & is, abstr_emp & e)
{
	is >> e.fname;
	if (!cin)
		cin.clear();
	is >> e.lname;
	if (!cin)
		cin.clear();
	is >> e.job;
	if (!cin)
		cin.clear();
	return is;
}
//class employee methods
employee::employee() : abstr_emp()
{}

employee::employee(const std::string & fn, const std::string & ln,
				   const std::string & j) : abstr_emp(fn, ln, j)
{}
void employee::ShowAll() const
{
	abstr_emp::Data();
	Data();
	cout << endl;
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::Data() const
{
}

std::ostream & operator<<(std::ostream & os, const employee & e)
{
	
	//operator<<(os, (static_cast<const abstr_emp &>(e)));
	os << endl;
	cout << "I am here were you need";
	return os;
}
	
std::istream & operator>>(std::istream & is, employee & e)
{
	operator>>(is, (static_cast<abstr_emp &>(e)));
	while (cin.get() != '\n')
		continue;
	cout << "I am here were you need";
	return is;
}

//class manger methods
manager::manager()
{}

manager::manager(const std::string & fn, const std::string & ln,
				 const std::string & j, int ico) : abstr_emp(fn, ln, j)
{
	inchargeof = ico;
}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e)
{
	inchargeof = ico;
}

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::Data();
	Data();
	cout << endl;
}

void manager::Data() const
{
	cout << "In charge of: " << inchargeof << " ";
}

void manager::GetData()
{
	cout << "In charge of: ";
	cin >> inchargeof;
	while (!cin)
	{
		cin.clear();
		clearLine();
		cout << "Bad input. Enter integer value: ";
		cin >> inchargeof;
	}
	clearLine();
}

void manager::SetAll()
{
	abstr_emp::GetData();
	GetData();
}

//class fink methods
fink::fink() {}

fink::fink(const std::string & fn, const std::string & ln,
		   const std::string & j, const std::string & rpo) : abstr_emp(fn,ln,j)
{
	reportsto = rpo;
}

fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e)
{
	reportsto = rpo;
}

fink::fink(const fink & e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::Data() const
{
	cout << "Reports to: " << reportsto << " ";
}

void fink::GetData()
{
	cout << "Reports to: ";
	cin >> reportsto;
	clearLine();
}

void fink::ShowAll() const
{
	abstr_emp::Data();
	Data();
	cout << endl;
}

void fink::SetAll()
{
	abstr_emp::GetData();
	GetData();
}

//class highfink methods: public manager, public fink // management fink

highfink::highfink() {}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: abstr_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j,rpo)
{}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e), manager(e,ico), fink(e,rpo)
{}

highfink::highfink(const fink & f, int ico) :  abstr_emp(f), manager(f,ico), fink(f)
{}

highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(m,rpo)
{}

highfink::highfink(const highfink & h)
{}

void highfink::ShowAll() const
{
	abstr_emp::Data();
	manager::Data();
	fink::Data();
}
void highfink::SetAll()
{
	abstr_emp::GetData();
	manager::GetData();
	fink::GetData();
}

void highfink::Data() const
{}

void highfink::GetData()
{}