#include <iostream>
#include <string>

using namespace std;

double calculateHarmonicMean( int x, int y);

int main()
{
	int val1, val2;
	double harmonic;
	cout<<"Enter two numbers\n";
	cin>>val1>>val2;
	while ( val1 != 0 && val2 != 0)
	{
		if(cin)
		{
		harmonic = calculateHarmonicMean(val1, val2);
		cout<<harmonic<<" is a harmonic value for "<<val1<<" and "<<val2<<".\n";
		cout<<"Enter another to numbers (q for quit)\n";
		}
		else 
			{
				cin.clear();
				string temp;
				getline(cin, temp);
				if (temp == "q")
					{break;}
				else {cout<<"Bad input. Try again.\n";}
		}
		cin>>val1>>val2;
	}
	cout<<"Good bye!\n";
	return 0;
}

double calculateHarmonicMean(int x, int y)
{
	double result;
	result = (2.0 * x * y) / (x + y);
	return result;
}