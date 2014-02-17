#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char * str;
	int ct;
};

void set(stringy &, const char *);
void show(const stringy &, int n = 1);
void show(const char *, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done");
	cin.get();
	return 0;
}

void set(stringy & setStr, const char * input)
{
	int len = strlen(input);
	cout << "Len = " << len <<endl;
	setStr.str = new char[len + 1];
	setStr.str[len] = 0;
	strncpy(setStr.str, input, len);
	setStr.ct = len;
}

void show(const stringy & str, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << str.str << endl;
	}
}

void show(const char * charStr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << charStr << endl;
	}
}