#include "HeadTask1v1.h"
#include <iostream>
#include <string>

int main()
{
	BankAccount account1;
	account1.show();
	BankAccount account2("Natalia Geryk", "123456", 100000);
	account2.show();
	std::cout << "Depositing 10 000 to Natalia Geryk account.\n";
	account2.deposit(10000);
	account2.show();
	std::cout << "Withdrawing 10 000 from Natalia Geryk account.\n";
	account2.withdraw(10000);
	account2.show();
	std::cin.get();
}