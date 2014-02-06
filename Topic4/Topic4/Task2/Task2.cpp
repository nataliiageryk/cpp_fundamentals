// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	string name, dessert;

	cout<<"Enter your name:\n";
	getline(cin,name);

	cout<<"Enter your favourite dessert:\n";
	getline(cin,dessert);

	cout<<"I have some delicious "<<dessert;
	cout<<" for you "<<name<<"!\n";

	cin.get();
	return 0;
}