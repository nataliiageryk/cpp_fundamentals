#include "exc_base.h"
#include <iostream>

using std::cout;
using std::endl;

void exc_base::reportAB() const
{
	cout << "a: " << a << "b: " << b << endl;
}

void exc_base::report()
{
	cout << "exc_base::report()\n";
	reportAB();
}

void bad_hmean::report()
{
	cout << "bad_hmean::report()\n";
	reportAB();
}

void bad_gmean::report()
{
	cout << "exc_base::report()\n";
	reportAB();
}