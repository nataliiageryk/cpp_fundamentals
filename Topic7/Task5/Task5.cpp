#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
	int number;
	cout<<"Enter a number and I calculate factorial for this number (q for quit)\n";
	while(cin>>number)
	{
		cout<<factorial(number)<<" is a factorial for "<<number<<endl;
		cout<<"Next value (q for quit): ";
	}

	return 0;
}

int factorial(int n)
{
	int value;
	if(n == 0)
	{ value = 1; return value;}
	else
	{ value = n * factorial(n -1);}
	return value;
}