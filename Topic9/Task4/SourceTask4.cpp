#include "Task4.h"
#include <iostream>

namespace SALES
{
	
	using std::cin;
	using std::cout;
	using std::endl;

	void setSales(Sales & s, const double ar[], int n)
	{
		for (int i = 0; i < QUARTERS; i++)
		{
			if ( n > i)
			{
				s.sales[i] = ar[i];
			}
			else
				for (int j = i; j < QUARTERS; j++)
				{
					s.sales[j] = 0; 
					i = QUARTERS;
				}
		}
		setCalcul(s);
	}

	void setSales(Sales & s)
	{
		cout << "Enter value for up to 4 quarters (0 to terminate input).\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cin >> s.sales[i];
			//handling invalid input
			while(!cin)
			{
				cin.clear();
				while (cin.get() != '\n')
				{continue;}
				cout << "Bad input. Try again"; 
			}
			cin.get();
			//set all remaining sales value to 0 if input was terminated
			if (s.sales[i] == 0)
				for (int j = i + 1; j < QUARTERS; j++)
				{
					s.sales[j] = 0; 
					i = QUARTERS;
				}
		}
		setCalcul(s);
	}
	
	void showSales(const Sales & s)
	{
		cout << "Sales for 4 quarters: \n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << s.sales[i] << "  ";
		}
		cout << endl;
		cout << "Max value: " << s.max <<endl;
		cout << "Min value: " << s.min << endl;
		cout << "Average: " << s.average << endl;
	}

	void setCalcul(Sales & s)
	{
		int count = 0;
		double sum = 0;

		//minimum array member difining;
		s.max = s.sales[0];
		s.min = s.sales[0];
		for (int i = 0; i < QUARTERS; i++)
		{
			if (s.sales[i] != 0)
			{
				count++;
				sum += s.sales[i];

				if (s.min > s.sales[i])
					s.min = s.sales[i];
				if (s.max < s.sales[i])
					s.max = s.sales[i];
			}
		}
		//average
		if (count != 0)
		s.average = sum / count;
		else s.average = 0;
	}
}