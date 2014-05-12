//https://ideone.com/Kr67gI
#include <iostream>

using namespace std;

template <typename T, typename... Args>
long double sum(T a, Args... args);
template <typename T>
long double sum(T a);

template <typename T, typename... Args>
long double sum(T a, Args... args)
{
	long double sm = 0;
	sm += a + sum(args...);
	return sm;
}

template <typename T>
long double sum(T a)
{
	return a;
}

int main()
{
	using namespace std;
	// list of double deduced from list contents
	auto q = sum(15.4, 10.7, 9.0);
	cout << q << endl;
	// list of int deduced from list contents
	cout << sum(20, 30, 19, 17, 45, 38) << endl;
	// forced list of double
	auto ad = sum<double>('A', 70, 65.33);
	cout << ad << endl;
	return 0;
}