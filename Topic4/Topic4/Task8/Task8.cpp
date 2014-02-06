// Task8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct pizza
{
	string company_name;
	float diameter;
	float weight;
};

int _tmain(int argc, _TCHAR* argv[])
{
	pizza * pizza1= new pizza;

	cout<<"Let input some info about pizza!\n";
	cout<<"Input pizza diameter: ";
	(cin>>pizza1->diameter).get();

	cout<<"Please input pizza company name: ";
	getline(cin,(pizza1->company_name));

	cout<<"Input pizza weight: ";
	(cin>>pizza1->weight).get();

	cout<<"Pizza company name: "<<pizza1->company_name<<endl;
	cout<<"Pizza diameter: "<<pizza1->diameter<<endl;
	cout<<"Input pizza weight: "<<pizza1->weight;

	cin.get();
	return 0;
}