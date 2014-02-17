#include <iostream>
#include <string>
using namespace std;

int FillArray(double * Arr, int max);
void ShowArray(double * Arr, int number);
void ReverseArray(double * Arr, int number);

const int ARR_SIZE = 20;
int main()
{
	double values[ARR_SIZE];
	int count;
	count = FillArray(values, ARR_SIZE);
	ShowArray(values, count);
	cout<<"\nLet's reverse array. And see how does it looks like.\n";
	ReverseArray(values, count);
	ShowArray(values,count);
	cout<<"\nReversing array but first and last element. See the result.\n";
	ReverseArray(values + 1, count - 2);
	ShowArray(values,count);
	cin.get();
	return 0;
}

void ShowArray(double * Arr, int max)
{
	cout<<"Array: ";
	for(int i = 0; i < max; i++)
	{
		cout<<Arr[i]<<" ";
	}
}

void ReverseArray(double * Arr, int number)
{
	double tmp;
	for (int i = 0, j = number - 1; i < j; i++, j--)
	{
		tmp = Arr[i];
		Arr[i] = Arr[j];
		Arr[j] = tmp;
	}
}

int FillArray(double * arr, int max)
{
	cout<<"Please enter up to "<<max<<" values (use non-numeric to terminate)\n";
	int i;
	for (i = 0; i < max; i++)
	{
	cout<<"Value #"<<i+1<<": ";
		cin>>arr[i];
		if (!cin)
		{
			cin.clear();
			string temp;
			getline(cin,temp);
			cout<<"You entered "<<i<<" values. Thank you!\n"; 
			return i;
		}
	}
		cin.get();
		cout<<"You entered "<<i<<" numbers.\n";
		return i;
}