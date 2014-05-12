// functor.cpp -- using a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	auto outint = [](int n) {std::cout << n << " ";};
	int f100 = 100, f200 = 200;
	int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([&f100](int n){return n > f100;}); // use a anonymous lambda function
	etcetera.remove_if([&f200](int n){return n > f200;}); 
	cout <<"Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	std::cin.get();
	return 0;
}