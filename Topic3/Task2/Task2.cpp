// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const char INCHES_IN_FOOT = 12;
const float INCHES_IN_METER = 0.0254;
const float KG_IN_POUNDS = 2.2;

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	int height_feet, height_inches, height_in_inches;
	float weight_in_pounds, weight_in_kg,  height_in_meters; 

	cout<<"Please, input you height in feet:____\b\b\b\b";
	cin>>height_feet;

	cout<<"Please, input you height in inches:____\b\b\b\b";
	cin>>height_inches;

	cout<<"Please, input you weight in pounds:____\b\b\b\b";
	cin>>weight_in_pounds;

	//calculate height in inches only
	height_in_inches = height_feet * INCHES_IN_FOOT + height_inches;
	cout<<"Height in enches : "<<height_in_inches<<endl;

	//calculating height in meters
	height_in_meters = height_in_inches * INCHES_IN_METER;
	cout<<"Height in meteres : "<<height_in_meters<<endl;

	//calculating weight in kilograms
	weight_in_kg = weight_in_pounds / KG_IN_POUNDS;
	cout<<"Weight in kilogrmas : "<<weight_in_kg<<endl;

	float index_BMI;
	index_BMI = weight_in_kg / ( height_in_meters * height_in_meters); 

	cout<<"Your BMI index = "<<index_BMI;

	cin.get();
	cin.get();


	return 0;
}

