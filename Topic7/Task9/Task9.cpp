#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student *pa, int n);
void display1(student st);
void display2(student *ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size : ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student * ptr_stu = new student [class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout <<"Done\n";
	cin.get();
	return 0;
}

int getinfo(student *pa, int n)
{
	cout << "Enter info about class students.\n";
	int count;
	for ( count = 0; count < n; count++)
	{
		cout << "Student #"<< count + 1 << ": \n";
		cout << "Student fullname: ";
		cin >> pa[count].fullname;
		if (pa[count].fullname == "")
		{ 
			cout<<"Input terminated. You entered info about "<< count - 1 <<" students.\n"; 
			return count - 1; 
		}
		cout << "Student hobby: ";
		cin >> pa[count].hobby;
		cout << "Student oop level: ";
		cin >> pa[count].ooplevel;
		while(!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
			{continue;}
			cout << "Bad input. Try again. \n";
			cin >> pa[count].ooplevel;
		}
	}
	cin.get();
	return count;
}

void display1(student st)
{
	cout << "Student fullname: " << st.fullname<<endl;
	cout << "Hobby: " << st.hobby<<endl;
	cout << "OOP level: " << st.ooplevel<<endl;
}

void display2(student *ps)
{
	cout << "Student fullname: " << ps->fullname<<endl;
	cout << "Hobby: " << ps->hobby<<endl;
	cout << "OOP level: " << ps->ooplevel<<endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Student #" << n + 1 << endl;
		cout << "Fullname: " << pa[i].fullname<<endl;
		cout << "Hobby: " << pa[i].hobby<<endl;
		cout << "OOP level: " << pa[i].ooplevel<<endl;
	}
}
