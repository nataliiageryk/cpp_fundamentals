#include "HeadTask1v1.h"
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

BankAccount::BankAccount(string nm, string accNmb, double blnc)
{
	name = nm;
	accountNumber = accNmb;
	balance = blnc;
}

BankAccount::~BankAccount()
{}

void BankAccount::show() const
{
	ios_base::fmtflags origin = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(2);
	cout << "Name: " << name <<endl;
	cout << "Account number: " << accountNumber <<endl;
	cout << "Balance: " << balance << endl;
	cout.setf(origin, ios_base::floatfield);
	cout.precision(prec);
}

void BankAccount::deposit(double dep)
{
	if (dep < 0)
		cout << "Cannot deposite negative sum. Depositing abborted.\n";
	else {	balance += dep;	}
}

void BankAccount::withdraw(double minus)
{
	if (minus < 0)
		cout << "Cannot operate with negative value. Withdrawing abborted.\n";
	else if (balance < minus)
		cout << "Cannot withdraw more than available value. Withdrawing abborted.\n";
	else {	balance -= minus;	}
}

BankAccount::BankAccount(const char * nm, string accNmb, double blnc)
{
	name = nm;
	accountNumber = accNmb;
	balance = blnc;
}