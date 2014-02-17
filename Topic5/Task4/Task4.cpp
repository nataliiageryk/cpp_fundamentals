#include <iostream>

using namespace std;

struct bank_count{
		double initial_invest;
		double percent;
		double current_balance;
		int time_invest;
		};

int main()
{
	bank_count Daphne={100, 0.1, 100, 0};
	bank_count Cleo={100, 0.05, 100, 0};

	do{
		Daphne.time_invest++;
		Cleo.time_invest++;
		Daphne.current_balance += Daphne.initial_invest * Daphne.percent;
		Cleo.current_balance += Cleo.current_balance * Cleo.percent;
		cout<<"Daphne: "<<Daphne.current_balance<<endl;
		cout<<"Cleo: "<<Cleo.current_balance<<endl;
	}while (Cleo.current_balance < Daphne.current_balance);

	cout<<"After "<<Cleo.time_invest<<" years Dapnba balance is "<<Daphne.current_balance<<" and Cleo balance is "<<Cleo.current_balance;

	cin.get();
	
	return 0;
}