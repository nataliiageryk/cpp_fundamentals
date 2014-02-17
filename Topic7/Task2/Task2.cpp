#include <iostream>
#include <string>
using namespace std;

int inputArr(int * scores, int max);
void showArr(const int * scores, int n);
double avgArr(const int * scores, int n);

const int MAX_SIZE = 10;

int main()
{
	int golfScores[MAX_SIZE], count = 0;
	count = inputArr(golfScores, MAX_SIZE);
	showArr(golfScores,count);
	cout<<"\nAverage value is: "<<avgArr(golfScores,count);
	cin.get();
	return 0;
}

int inputArr(int * scores, int max)
{
	cout<<"Please enter up to "<<max<<" values (use q to terminate)\n";
	int i;
	for (i = 0; i < max; i++)
	{
		cout<<"Value #"<<i+1<<": ";
		cin>>scores[i];
		while (!cin)
		{
			cin.clear();
			string temp;
			getline(cin,temp);
				if(temp == "q")
					{
						cout<<"You entered "<<i<<" values. Thank you!\n"; 
						return i;
				}
				else {
					cout<<"Bad input. Try again.\n";
					cin>>scores[i];
					continue;
				}
		}
		cin.get();
	}
		cout<<"You entered "<<i<<" numbers.\n";
		return i;
}

void showArr(const int * scores, int n)
{
	cout<<"Your scores: ";
	for(int i = 0; i < n; i++)
	{
		cout<<scores[i]<<" ";
	}
}

double avgArr(const int * scores, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{ 
		sum += scores[i];
	}
	return sum / n;
}