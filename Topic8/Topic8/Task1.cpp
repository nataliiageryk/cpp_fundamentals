#include <iostream>

using namespace std;
int NumOfCalls = 0;

void PrintString(const char * str, int n = 0);
int main ()
{
	const char * input = "This is test string";
	cout << "NumOfCalls var has a value "<< NumOfCalls << " before function call\n";
	cout << "Call print function with omited numeric parameter:\n";
	PrintString(input);
	cout<< "New value of NumOfCalls is " << NumOfCalls <<endl;
	cout << "Call print function with omited numeric parameter again:\n";
	PrintString(input);
	cout<< "New value of NumOfCalls is " << NumOfCalls <<endl;
	cout << "Call print function with numeric parameter = 100:\n";
	PrintString(input, 100);
	cout<< "New value of NumOfCalls is " << NumOfCalls <<endl;
	cout << "Done!";
	cin.get();
	return 0;
}

void PrintString(const char * str, int n)
{
	//static int NumOfCalls = 0; static var can be successfully used her. But NumOFCalls cannot be used in main in such case
	NumOfCalls++;
	if (n == 0)
		cout << str << endl;
	else
	{
		for (int i = 0; i < NumOfCalls; i++)
			cout << str << endl;
	}
}