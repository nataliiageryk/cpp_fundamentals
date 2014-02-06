// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const char SECONDS_IN_MINUTE = 60;
const char MINUTES_IN_DEGREES = 60;

int _tmain(int argc, _TCHAR* argv[])
{
	float minutes_num, seconds_num, degrees_num;
	float degrees_fract;

	cout<<"Please, input number of degrees :\n";
	cin>>degrees_num;

	cout<<"Please, input number of minutes :\n";
	cin>>minutes_num;
	
	cout<<"Please, input number of seconds :\n";
	cin>>seconds_num;
	


	degrees_fract = degrees_num + ( minutes_num / MINUTES_IN_DEGREES ) + (seconds_num / SECONDS_IN_MINUTE) / MINUTES_IN_DEGREES ;

	cout<<degrees_num<<" degrees, "<<minutes_num<<" minutes, "<<seconds_num<<" seconds = "<<degrees_fract<<" degrees";

	cin.get();
	cin.get();
	return 0;
}

