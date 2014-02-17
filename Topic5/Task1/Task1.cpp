#include <iostream>

int main()
{
	int smaller_int, biger_int;

	std::cout<<"Please enter to integers. First - smaller, secod -biger. \nEnter first value: ";
	std::cin>>smaller_int;
	std::cout<<"Enter second value: ";
	std::cin>>biger_int;

	int sum_int = 0;

	for (int i = smaller_int ; i <= biger_int ; i++)
	{
		sum_int += i;
	}

	std::cout<<"Sum of integers between and including "<<smaller_int<<" and "<<biger_int<<" is : "<<sum_int;

	std::cin.get();
	std::cin.get();

	return 0;
}