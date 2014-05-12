#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <valarray>
#include <string>
#include <utility>
typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	std::string label;
	int numberOfYears;
	PairArray bottlForYear;

public:
	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char * l, int y, const int yr[], const int bot[]);
	// initialize label to l, number of years to y,
	// create array objects of length y
	Wine(const char * l = "NULL" , int y = 0);
	~Wine();
	//ask user to enter numberOfYears pairs of years - bottles
	void GetBottles();
	void Show() const;
	//return wine name
	const std::string & Label() const;
	//return total number of bottles
	int Sum() const;
};
#endif // !WINEC_H_