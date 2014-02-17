#include <iostream>

using namespace std;

int main()
{
	double earn_value = 0 , tax_value = 0;
	cout<<"Enter value you earning: ";
	
	while(cin>>earn_value && earn_value>0)
	{
		double remain = 0;
		tax_value = 0;
		if(earn_value - 5000 > 0)
		{ 
			remain = earn_value - 5000;
			if((remain - 10000) > 0)
			{
				tax_value += 10000 * 0.1;
				remain -= 10000;
				if(remain - 20000 > 0)
				{
					tax_value += 20000 * 0.15;
					remain -= 20000;
					tax_value += remain * 0.2;
				}
				else tax_value += remain * 0.15;
			}
			else tax_value += remain * 0.1;
		}
		else tax_value = 0;
		cout<<"Tax is "<<tax_value<<endl;
		cout<<"Enter next value: ";
	}
	cin.get();
	return 0;
}