#include "emp.h"
#include <fstream>

using namespace std;

const char * file = "some.txt";
const int SIZE = 10;
int count = 0;

int menu();
void addInfo(abstr_emp ** ar, int n);
void showAll(abstr_emp ** ar, int n);
abstr_emp * createObj(abstr_emp * ar, int type);
 
int main()
{
	fstream finout (file, ios_base::in |ios_base::out | ios_base::app);
	abstr_emp * empArr[SIZE];
	if(!file)
	{
		cout << "File cannot be opened\n";
		return 1;
	}
		if(finout.peek() == std::ifstream::traits_type::eof())
	{
		::count = 0;
		addInfo(empArr, SIZE);
		showAll(empArr,::count);	
		finout.clear();
		cout << "number of entries:" << ::count;
		for ( int i = 0; i < ::count; i++)
		{
			finout << *empArr[i];
			finout.flush(); 
		}
	}
	else
	{
		for(int i = 0; i < SIZE; i++)
		{
			int type;
			finout >> type;
			finout.get();
			if(finout.eof())
				break;
			empArr[i] = createObj(empArr[i], type);
			finout >> *empArr[i];
			::count++;
		}	
		showAll(empArr,::count);
		if (finout.bad())
			finout.clear();
		if (::count < SIZE)
			addInfo(empArr + ::count, SIZE - ::count);
		cout << "Here is new info: \n" << ::count << endl;
		showAll(empArr,::count);	
		finout.flush();
		finout.ignore();
		finout.clear();

		for ( int i = 0; i < ::count; i++)
		{
			finout << *empArr[i];
			finout.flush(); 
		}
	}
	
	cin.get();
	cin.get();
	finout.close();
}

int menu()
{
	int type;
	cout << "Choose a type:\n";
	cout << "0 - for Employee\t1 - for Manager\n2 - for Fink\t\t3 - for Highfink\n";
	cin >> type;
	while(!cin || type > 3)
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "Bad input. Enter a number from 0 to 3\n";
		cout << "0 - for Employee\t1 - for Manager\n2 - for Fink\t\t3 - for Highfink\n";
		cin >> type;
	}
	return type;
}

void addInfo(abstr_emp ** ar, int n)
{
	cout << "Please input info about employee!\n";
	int type;
	for (int i = 0; i < n; i++)
	{
		type = menu();
		ar[i] = createObj(ar[i], type);
		ar[i]->SetAll();
		::count++;
		char ch;
		do
		{
		cout << "Enter a - to add more info, q - to stop adding\n";
		cin.get(ch);
		}		while(ch != 'a' && ch !='q');
		if(ch == 'q')
			break;
		}
}

void showAll(abstr_emp ** ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		ar[i]->ShowAll();
	}
}

abstr_emp * createObj(abstr_emp * ar, int type)
{
switch (type)
		{
		case 0: ar = new employee; break;
		case 1: ar = new manager; break;
		case 2: ar = new fink; break;
		case 3: ar= new highfink; break;
		}
return ar;
}