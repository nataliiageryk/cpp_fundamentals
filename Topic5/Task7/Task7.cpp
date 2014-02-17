#include <iostream>
#include <string>

using namespace std;

struct car_struc{
	string maker;
	int year;
};

int main(){
	cout<<"How many cars you would like to catalog: ";
	int number;
	(cin>>number).get();
	car_struc *cars_catalog = new car_struc[number];
	for(int i = 0; i < number ; i++)
	{
		cout<<"Car #"<<(i+1)<<":\n";
		cout<<"Please enter the make:\t";
		getline(cin,cars_catalog[i].maker);
		cout<<"Please enter the year made:\t";
		(cin>>cars_catalog[i].year).get();
	}

	cout<<"Here is your collection:\n";

	for (int i = 0; i < number; i++)
	{
		cout<<cars_catalog[i].year<<"\t"<<cars_catalog[i].maker<<endl;
	}

	cin.get();
	
	return 0;
}