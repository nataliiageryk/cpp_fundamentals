#include <iostream>
using namespace std;
double calculate(double a, double b, double (* ptr)(double, double));
double add(double a, double b);
double mult(double a, double b);

int main()
{
	double num1, num2;
	cout << "Enter two values.\n";
	
	while (!(cin >> num1 >> num2))
	{
		cin.clear();
		while (cin.get() != '\n')
		{continue;}
		cout << "Bad input. Try again.\n";
	}
	cin.get();
	cout << num1 <<" + "<< num2 <<" = "<< calculate(num1, num2, add) << endl;
	cout << num1 <<" * "<< num2 <<" = "<< calculate(num1, num2, mult) << endl;
	cout << "Done!" << endl;
	cin.get();
}

double calculate(double a, double b, double (* ptr)(double, double))
{
	return ptr(a,b);
}

double add(double a, double b)
{
	return a + b;
}

double mult(double a, double b)
{
	return a * b;
}
