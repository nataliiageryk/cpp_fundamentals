#include <iostream>
#include <string>
#include <cstdio>
#include "Task2.h"

using std::cout;
using std::endl;
using std::string;

Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strncpy(fname,fn,LIMIT-1);
	fname[LIMIT - 1] = '/0';
}

void Person::Show() const	//firstname, lastname format
{
	cout << "Firstname: " << fname << endl;
	cout << "Lastname: " << lname << endl;
}

void Person::FormalShow() const	//lastname, firstname format
{
	cout << "Lastname: " << lname << endl;
	cout << "Firstname: " << fname << endl;
}
