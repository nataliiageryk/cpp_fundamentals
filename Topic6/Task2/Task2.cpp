#include <iostream>

using namespace std;
const int SIZE = 10;

int main()
{
	double value[SIZE];
	int count = 0;
	double average = 0, more_avg_count = 0;

	cout<<"Enter up to 10 values!\n";
	cout<<"Value #"<<count+1<<": ";
	double sum = 0;
	while(count < SIZE && cin>>value[count])
	{
		cin.get();
		sum+=value[count];
		count++;
		if(count < SIZE)
		cout<<"Value #"<<count+1<<": ";
	}

	if (!cin)
	{
		cin.clear();
		char ch;
		while (cin.get(ch) && ch != '\n')
		{}
	}

	if(count > 0)
	{
		//calculate average	
		average = sum / count;

		//calculate number of larger than average values
		for (int i = 0 ; i < count; i++)
		{
			if(value[i] > average)
				more_avg_count ++;
		}

		//print results
		cout<<average<<" is average of "<<count<<" entered values\n";
		cout<<more_avg_count<<" of inputed values are biger than average.\n";

	} 
	else cout<<"You did not enter any values.";
	
	cin.get();
	return 0;
}