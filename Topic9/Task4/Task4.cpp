#include <iostream>
#include "Task4.h"
using namespace SALES;
using std::cin;

int main()
{
	Sales s1, s2;
	//initiating s1 in interacrive mode
	setSales(s1);
	showSales(s1);
	double Arr[4] = {12, 23, 15, 0};
	setSales(s2, Arr, 2);
	showSales(s2);
	setSales(s2, Arr, 3);
	showSales(s2);
	setSales(s2, Arr);
	showSales(s2);
	cin.get();
	

	return 0;
}
