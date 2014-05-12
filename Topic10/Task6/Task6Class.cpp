#include "HeaderTask6.h"
#include <iostream>

using std::cout;
using std ::endl;

Move::Move(double a = 0, double b = 0) //set x and y to a and b
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << " x = " << x << ", y = " << y << endl;
}

Move Move::add(const Move & m) const
{
	Move sum;
	sum.x = x + m.x;
	sum.y = y + m.y;
	return sum;
}

void Move::reset(double a = 0, double b = 0) //reset x and y to a and b
{
	x = a;
	y = b;
}


Move::~Move()
{
}
