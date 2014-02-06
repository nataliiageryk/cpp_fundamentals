// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const char INCH_IN_FOOT = 12;

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	cout<<"Hello :) Please, input your height in inches :____\b\b\b\b";

	int height_in_inches;
	cin>>height_in_inches;

	cout<<"Your heigt is "<<height_in_inches/INCH_IN_FOOT<<" feet and "<<height_in_inches%INCH_IN_FOOT<<" inches\n";
	cin.get();
	cin.get();
	return 0;
}

