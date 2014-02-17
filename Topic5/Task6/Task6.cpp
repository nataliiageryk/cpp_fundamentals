#include <iostream>
#include <string>

using namespace std;
const int MONTH_IN_YEAR = 12;
const int YEARS = 3;

int main(){
	const string monthes_of_year[MONTH_IN_YEAR] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Augest", "Sept", "Octob", "Novemb", "Decemb"};
	int sales_for_month[YEARS][MONTH_IN_YEAR]={0};
	int sum[YEARS]={0};

	for(int year = 0; year < YEARS ; year++)
	{
		cout<<"Input sales statistic for year#"<<year+1<<endl;
		for(int i = 0 ; i < MONTH_IN_YEAR ; i++)
		{
			cout<<"Input number of saled books for "<<monthes_of_year[i]<<":\t";
			cin>>sales_for_month[year][i];
			sum[year] += sales_for_month[year][i];
		}
		cout<<"\n\n";
	}

	for(int year = 0; year < YEARS ; year++)
	{
		cout<<"Total sales for year#"<<year+1<<": "<<sum[year]<<endl;
	}

	cin.get();
	cin.get();

	return 0;
}