#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void remPunctuation (string &);
bool isPalindrome(const string &);

int main()
{
	string str;
	cout << "Enter a string: ";
	getline(cin,str);
	remPunctuation(str);
	cout << "String: " << str << endl;
	
	if (isPalindrome(str))
	{
		cout << "is palindrome";
	}
	else cout << "is NOT palindrome";
	cin.get();
	return 0;
}

void remPunctuation (string & init_str )
{
	init_str.erase( std::remove_if<>(init_str.begin(), init_str.end(),[](char x){return !isalpha(x);}), init_str.end());
}

bool isPalindrome(const string & str)
{
	for (int i = 0, j = str.length()-1; i < j; i++, j--)
		if(str[i] != str[j])
			return false;
	return true;
}