#ifndef HEADTASK1V1_H_
#define HEADTASK1V1_H_

#include <string>
using std::string;

class BankAccount
{
private:
	std::string name;
	std::string accountNumber;
	double balance;
public:
	BankAccount(string nm = "no name", string accNmb = "xxx", double blnc = 0);
	BankAccount(const char * nm, string accNmb = 0, double blnc = 0);
	~BankAccount();
	void show() const;
	void deposit(double dep);
	void withdraw(double minus);
};

#endif // !TASK1_H_