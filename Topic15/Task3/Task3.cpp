#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_base.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try { // start of try block
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (exc_base & be) // start of catch block
		{
			be.report();
			cout << be.what();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		} // end of catch block
		catch(std::exception & he)
		{
			cout << he.what();
			break;
		}
	}
	cout << "Bye!\n";
	cin.get();
	cin.get();
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	return std::sqrt(a * b);
}