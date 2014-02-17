#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int sum = 0, entry;
	
	do	{
		cout<<"Please enter int number. Use 0 to terminate.\n";
		cin>>entry;
		sum += entry;
		cout<<"Currently sum valuer is "<<sum<<endl;
	}while (entry!=0 && cin);

	return 0;
}