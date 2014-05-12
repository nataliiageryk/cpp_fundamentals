#include "winepi.h"
#include <iostream>
#include <valarray>
#include <string>
#include <utility>
typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;
using std::cout;
using std::cin;
using std::endl;

// initialize label to l, number of years to y,
// vintage years to yr[], bottles to bot[]
Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), numberOfYears(y), PairArray(ArrayInt(yr,y),ArrayInt(bot,y))
{	
}

// initialize label to l, number of years to y,
// create array objects of length y
Wine::Wine(const char * l , int y) : label(l), numberOfYears(y), PairArray(ArrayInt(y),ArrayInt(y))
{
}

Wine::~Wine()
{
}

//ask user to enter numberOfYears pairs of years - bottles
void Wine::GetBottles()
{
	cout << "Enter " << this->Label() << " data for " << numberOfYears << " year(s): " << endl;
	if ( numberOfYears > 0)
	{
		const int SIZE = numberOfYears;
		ArrayInt tmpYear(numberOfYears);
		ArrayInt tmpBottle(numberOfYears);
		for (int i = 0 ; i < numberOfYears; i++)
		{
			cout << "Enter year: ";
			cin >> tmpYear[i];
			cout << "Enter bottles for that year: ";
			cin >> tmpBottle[i];
		}
		PairArray tmp(tmpYear,tmpBottle);
		this->first = ArrayInt(tmpYear);
		this->second = ArrayInt(tmpBottle);
		//PairArray(*this) = tmp;
	}
	else
	cout << "No elements to set\n";
}
	
void Wine::Show() const
{
	cout << "Wine: " << label << endl;
	cout << "\tYear" << "\tBottles\n";
		if (numberOfYears > 0)
		{
			for (int i = 0 ; i < numberOfYears; i++)
				cout << "\t" << this->first[i] << "\t" << this->second[i] << endl; 
		}
		else 
			cout << "Nothing to show!\n";
}
	
//return wine name
const std::string & Wine::Label() const
{
	return label;
}
	
//return total number of bottles
int Wine::Sum() const
{
	int sum = 0;
	if (numberOfYears > 0)
		for (int i = 0 ; i < numberOfYears; i++)
		{
			//ArrayInt add((PairArray*)this->second,numberOfYears);
			sum += this->second[i];
		}
	return sum;
}