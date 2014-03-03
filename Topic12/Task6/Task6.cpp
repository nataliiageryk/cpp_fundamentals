#include "Queue2.h"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?
using namespace std;
int main()
{
	std::srand(std::time(0)); // random initializing of rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs); // lines queue holds up to qs people
	Queue line2(qs);
	cout << "Enter the number of simulation hours: ";
	int hours; // hours of simulation
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours; // # of cycles
	double perhour = MIN_PER_HR / 2; // average # of arrival per hour
	double min_per_cust; // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;
	Item temp; // new customer data
	long turnaways; // turned away by full queue
	long customers; // joined the queue
	long served; // served during the simulation
	long sum_line; // cumulative line length
	int line1_wait_time; // time until autoteller is free
	int line2_wait_time;
	long line1_wait; // cumulative time in line
	long line2_wait;
	double avg_wait_time = 0;
	// running the simulation
	while ( (avg_wait_time > 1) ? ((avg_wait_time - 1) > 0.1) : ((1 - avg_wait_time) > 0.1))
	{
		min_per_cust = MIN_PER_HR / perhour;
		cout << perhour << endl;
		customers = 0;
		turnaways = 0;
		served = 0;
		line1_wait = 0;
		line2_wait = 0;
		line1_wait_time = 0;
		line2_wait_time = 0;
		sum_line = 0;
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust)) // have newcomer
			{
				if (line1.isfull() && line2.isfull())
					turnaways++;
				else
					customers++;
					temp.set(cycle); // cycle = time of arrival
					if (line1.queuecount() < line2.queuecount())
						line1.enqueue(temp); //add newcomer to line1
					else line2.enqueue(temp); // add newcomer to line2
			}
		
			if (line1_wait_time <= 0 && !line1.isempty())
			{
				line1.dequeue (temp); // attend next customer
				line1_wait_time = temp.ptime(); // for wait_time minutes
				line1_wait += cycle - temp.when();
				served++;
			}
			if (line2_wait_time <= 0 && !line2.isempty())
			{
				line2.dequeue (temp); // attend next customer
				line2_wait_time = temp.ptime(); // for wait_time minutes
				line1_wait += cycle - temp.when();
				served++;
			}
			if (line1_wait_time > 0)
				line1_wait_time--;
			if (line2_wait_time > 0)
				line2_wait_time--;
		}
		avg_wait_time = ((double)line1_wait + (double)line2_wait)/ served;
		if (avg_wait_time > 1 && (avg_wait_time - 1) > 0.2) 
			perhour -= (perhour / 2);
		else if ((1 - avg_wait_time) > 0.2)
			perhour += (perhour / 2);
	}
	cout << "customers accepted: " << customers << endl;
	cout << " customers served: " << served << endl;
	cout << " turnaways: " << turnaways << endl;
	cout << " average wait time: "
		<< (double) (line1_wait + line2_wait) / served << " minutes\n";
		cout << "number of customers per hour: " << perhour << endl;
 cin.get();
 cin.get();
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}