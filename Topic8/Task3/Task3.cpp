#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void StrToUpper(string &);

int main()
{
	string input;
	cout << "Enter a string (q to quit): ";
	while (getline(cin,input) && input != "q")
	{
		input = StrToUpper(input);
		cout << input << endl;
		cout << "Enter a string (q to quit): ";
	}
	cout << "Bye!"
	return 0;
}

void StrToUpper (string & str)
{
	int len = str.length();
	for ( int i = 0; i < len; i++)
	{
		if (isalpha(str[i]))
			str[i] = toupper(str[i]);
		else continue;
	}
}