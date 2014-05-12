#include "Cd.h"
#include <cstdio>
#include <iostream>

Cd::Cd(char * s1, char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strcpy(performers,s1);

	label = new char[strlen(s2) + 1];
	strcpy(label,s2);

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers,d.performers);

	label = new char[strlen(d.label) + 1];
	strcpy(label,d.label);

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[1];
	performers[0] = '\0';

	label = new char[1];
	label[0] = '\0';

	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}

void Cd::Report() const
{
	using std::cout;
	using std::endl;
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;

	delete [] performers;
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers,d.performers);

	delete [] label;
	label = new char[strlen(d.label) + 1];
	strcpy(label,d.label);

	selections = d.selections;
	playtime = d.playtime;
}
	
Classic::Classic(char * prm, char * s1, char * s2, int n, double x) : Cd(s1,s2,n,x)
{
	primaryWork = new char[strlen(prm) + 1];
	strcpy(primaryWork,prm);
}

Classic::Classic(char * prm, Cd & cd1) : Cd(cd1)
{
	primaryWork = new char[strlen(prm) + 1];
	strcpy(primaryWork,prm);
}
	
Classic::Classic(const Classic & cl1) : Cd(cl1)
{
	primaryWork = new char[strlen(cl1.primaryWork) + 1];
	strcpy(primaryWork,cl1.primaryWork);
}

Classic::~Classic()
{
	delete [] primaryWork;
}

void Classic::Report() const
{
	using std::cout;
	using std::endl;
	Cd::Report();
	cout << "Primary work: " << primaryWork << endl;
}
	
Classic & Classic::operator=(const Classic & clas1)
{
	if(this == &clas1) 
		return * this;
	Cd::operator=(clas1);

	delete [] primaryWork;
	primaryWork = new char[strlen(clas1.primaryWork) + 1];
	strcpy(primaryWork,clas1.primaryWork);
}

Classic::Classic() : Cd()
{
	primaryWork = new char[1];
	primaryWork[0] = '\0';
}