#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct contributors{
	string name;
	double contribution;
};

int main()
{
	int number;
	ifstream fin;
	fin.open("income.txt");
	fin >> number;
	while (fin.good() && fin.get() != '\n') {}

	contributors *contrb = new contributors[number];
	for (int i = 0; i < number; i++)
	{
		getline(fin, contrb[i].name);
		//cannot work with getline(cin,contrb[i].name)
		fin>>contrb[i].contribution;
		while (fin.good() && fin.get() != '\n') {}
	}
	cout << fixed;
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
	delete [] contrb;
	return 0;
}