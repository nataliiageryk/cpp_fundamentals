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
		cin>>contrb[i].name; //cannot work with getline(cin,contrb[i].name)
		cout<<"Enter the value of contribution for contributor #"<<i+1<<endl;
		cin>>contrb[i].contribution;
		while( !(cin) || contrb[i].contribution < 0)
		{
			cin.clear();
			string * str = new string;
			getline(cin,*str);
			delete str;
			cout<<"Wrong input. Try again.\n";
			cin>>contrb[i].contribution;
		}
	}
	cout<<fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout<<"Grand Patrons: \n";
	int grand_count=0;
		for(int i = 0; i < number; i++)
		{
			if(contrb[i].contribution >= 10000)
			{
				cout<<contrb[i].name<<":\t"<<contrb[i].contribution<<endl;
				grand_count++;
			}
		}
		if(grand_count == 0)
			cout<<"none\n";
		cout<<"Patrons: \n";
		int patrons_count=0;
		for(int i = 0; i < number; i++)
		{
			if(contrb[i].contribution < 10000)
			{
				cout<<contrb[i].name<<":\t"<<contrb[i].contribution<<endl;
				patrons_count++;
			}
		}
		if(patrons_count == 0)
			cout<<"none\n";

	cin.get();
	cin.get();
	delete [] contrb;
	return 0;
}