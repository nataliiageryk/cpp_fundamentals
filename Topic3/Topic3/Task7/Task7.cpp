// Task7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const float MILES_ON_100KM = 62.14;
const float LITERS_IN_GALLON = 3.875;


int _tmain(int argc, _TCHAR* argv[])
{
	float liter_per_100km, miles_on_gallon;

	cout<<"Please, input automobile gassoling consumption (liters per 100 kilometers) : ";
	cin>>liter_per_100km;

	float gallons__per_100km = liter_per_100km / LITERS_IN_GALLON ;
	float miles_per_galon = MILES_ON_100KM / gallons__per_100km ;

	cout<<"Automobile gassoling consumption (miles per gallon) : "<<miles_per_galon;

	cin.get();
	cin.get();
	return 0;
}

