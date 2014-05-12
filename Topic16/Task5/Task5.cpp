#include <iostream>
#include <valarray>
#include <set>
#include <algorithm>

template <class T>
int reduce(T ar[], int n);

int main()
{
	char tmp[40];
	std::cout << "Enter a line: ";
	std::cin.getline(tmp,40);
	int len = strlen(tmp);
	int newlen = reduce(tmp, len);
	tmp[newlen] =0;
	std::cout << tmp << std::endl;
	std::cin.get();
}

template <class T>
int reduce(T ar[], int n)
{
	std::sort(ar,ar+n);
	char * end = std::unique(ar,ar+n);
	std::cout << (char**)ar;
	std::cout << (char**)end;
	int len = end - ar;
	std::cout << len;
	return len;
}