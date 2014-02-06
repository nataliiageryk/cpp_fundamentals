// Task10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	array<float, 3> user_value; 
	float avg_user_value;
	cout<<"Please, input three values:";
	(cin>>user_value[0]).get();
	(cin>>user_value[1]).get();
	(cin>>user_value[2]).get();
	//calculate average value
	avg_user_value = (user_value[0] + user_value[1] + user_value[2]) / 3;
	cout<<"Inputed values : "<<user_value[0]<<", "<<user_value[1]<<", "<<user_value[2]<<".\n";
	cout<<"Average value : "<<avg_user_value;
	cin.get();
	return 0;
}