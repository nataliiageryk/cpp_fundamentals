#include <iostream>
#include <string>

using namespace std;
const int MONTH_IN_YEAR = 12;
int main()
{
	const string monthes_of_year[MONTH_IN_YEAR] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Augest", "Sept", "Octob", "Novemb", "Decemb"};
	int sales_for_month[MONTH_IN_YEAR]={0};

	int sum = 0;

	for(int i = 0 ; i < MONTH_IN_YEAR ; i++)
	{
		cout<<"Input number of saled books for "<<monthes_of_year[i]<<":\t";
		cin>>sales_for_month[i];
		sum += sales_for_month[i];
	}

	cout<<"Totla sales for the year: "<<sum;

	cin.get();
	cin.get();

	return 0;
}