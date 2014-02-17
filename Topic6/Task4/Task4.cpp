#include <iostream>

using namespace std;
const int strsize = 30;
void showMenu();
struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

void disp_bop_name(bop *, int);
void disp_bop_title(bop *, int);
void disp_bop_bopname(bop *, int);
void disp_bop_pref(bop *, int);

int main()
{
	const int SIZE = 5;
	bop bop_employee[SIZE] = {
		{"Wimp Macho", "Senior Programmer","Wimpy",0},
		{"Raki Rhodes","Junior Programmer","RR",1},
		{"Celia Laiter", "Middle Programmer","MIPS",2},
		{"Hoppy Hipman","Analyst Trainee","HA",1},
		{"Pat Hand","Analyst","LOOPY",2}};
	showMenu();
	cout<<"Enter your choice: ";
	char choice;
	cin>>choice;

	while(choice != 'q' &&  choice != 'Q')
	{
		switch (choice)
		{
		case 'a': 
		case 'A': disp_bop_name(bop_employee, SIZE); break;
		case 'b': 
		case 'B': disp_bop_title(bop_employee, SIZE); break;
		case 'c': 
		case 'C': disp_bop_bopname(bop_employee, SIZE); break;
		case 'd': 
		case 'D': disp_bop_pref(bop_employee, SIZE); break;
		default : cout<<"Please choose from menu\n", showMenu(); break;
		}
		cout<<"Next choice: ";
		cin>>choice;
	}
	cout<<"Good bye!";
	cin.get();
	return 0;
}

void showMenu()
{
	cout<<"Benevolent Order of Programmers Report\n";
	cout<<"a.  display by name \t\tb.  display by title\n";
	cout<<"c.  display by bopname\t\td.  display by preference\n";
	cout<<"q.  quit\n";
}

void disp_bop_name(bop * disp, int n)
{
	for (int i = 0; i < n ; i++)
	{
		cout<<disp[i].fullname<<endl;
	}
}
void disp_bop_title(bop * disp, int n)
{
	for (int i = 0; i < n ; i++)
	{
		cout<<disp[i].title<<endl;
	}
}
void disp_bop_bopname(bop * disp, int n)
{
	for (int i = 0; i < n ; i++)
	{
		cout<<disp[i].bopname<<endl;
	}
}
void disp_bop_pref(bop * disp, int n)
{
	for (int i = 0; i < n ; i++)
	{
		switch (disp[i].preference)
		{
		case 0: disp_bop_name(&disp[i],1); break;
		case 1: disp_bop_title(&disp[i],1); break;
		case 2: disp_bop_bopname(&disp[i],1); break;
		default : disp_bop_name(&disp[i],1); break;
		}
	}
}