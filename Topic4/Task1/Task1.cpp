// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string name, surname;
	char grade_letter;
	int age;

	cout<<"What is your first name? ";
	getline(cin,name);
	
	cout<<"\nWhat is your last name? ";
	getline(cin,surname);

	cout<<"\nWhat letter grade do you deserve? ";
	cin>>grade_letter;

	//change grade_letter by adding 1, that gives us the next character code 
	grade_letter+=1;
	cin.get();
	
	cout<<"\nWhat is your age? ";
	cin>>age;
	
	cin.get();

	cout<<"Name: "<<surname<<", "<<name<<endl;
	cout<<"Grade: "<<grade_letter<<endl;
	cout<<"Age: "<<age;

	cin.get();

	return 0;
}

