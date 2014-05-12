#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "../Task6/Queue2.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	//setting things up
	std::srand(std::time(0)); // random initializing of rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs); // line queue holds up to qs people
	cout << "Enter the number of simulation hours: ";
	int hours; // hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles
	double perhour = MIN_PER_HR / 2; // average # of arrival per hour
	double min_per_cust; // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;
	Item temp; // new customer data
	long turnaways; // turned away by full queue
	long customers; // joined the queue
	long served; // served during the simulation
	long sum_line; // cumulative line length
	int wait_time; // time until autoteller is free
	long line_wait; // cumulative time in line
	double avg_wait_time = 0;
	// running the simulation
	while ( (avg_wait_time > 1) ? ((avg_wait_time - 1) > 0.1) : ((1 - avg_wait_time) > 0.1))
	{
		min_per_cust = MIN_PER_HR / perhour;
		cout << perhour << endl;
		customers = 0;
		turnaways = 0;
		served = 0;
		line_wait = 0;
		wait_time = 0;
		sum_line = 0;
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust)) // have newcomer
			{
				if (line.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle); // cycle = time of arrival
					line.enqueue(temp); // add newcomer to line
				}
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue (temp); // attend next customer
				wait_time = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
		avg_wait_time = (double)line_wait / served;
		if (avg_wait_time > 1 && (avg_wait_time - 1) > 0.2) 
			perhour -= (perhour / 2);
		else if ((1 - avg_wait_time) > 0.2)
			perhour += (perhour / 2);
	}
	// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << " turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double) line_wait / served << " minutes\n";
		cout << "number of customers per hour: " << perhour << endl;
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	cin.get();
	cin.get();
	return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}