#include <iostream>
#include <string>

using namespace std;

struct contributors{
	string name;
	double contribution;
};

int main()
{
	int number;
	cout<<"Enter the number of contributors: \n";
	cin>>number;

	contributors *contrb = new contributors[number];
	for(int i = 0; i < number; i++)
	{
		cout<<"Enter the name of contributor #"<<i+1<<endl;
		getline(cin,contrb[i].name);
		cout<<"Enter the value of contribution for contributor #"<<i+1<<endl;
		while( !(cin>>contrb[i].contribution)  && contrb[i].contribution < 0)
		{
			cout<<"Wrong input. Try again.";
		}

	}

	delete [] contrb;
	return 0;
}