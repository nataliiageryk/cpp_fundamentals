#include <iostream>
using namespace std;

int main(){
	int rows_num;

	cout<<"Enter number of rows: ";
	cin>>rows_num;

	for (int j = 1 ; j <= rows_num ; j++)
	{
		for (int i = rows_num -j ; i > 0 ; i--)
		{
			cout<<".";
		}
		for (int k = 0 ; k < j; k++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

	cin.get();
	cin.get();
}