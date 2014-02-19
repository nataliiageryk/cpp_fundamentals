#include <iostream>
using namespace std;

template <typename T>
T maxn(T *, int n);

template <>
char * maxn<char *>(char ** t, int n);

int main()
{
	int intArray[6] = {1, 2, 6, 3, 2, 7};
	double doubArray[4] = {0, 4, 4, 0};
	char * str[4] = {"a","bb","ccc","dddd"};
	cout << "Max from int " << (maxn<>(intArray, 6)) << endl;
	cout << "Max from double " << maxn<>(doubArray, 4) << endl;
	cout << "Max from strings " << maxn<>(str,4);
	cin.get();
	return 0;
}

template <typename T>
T maxn<>(T * arrVal, int n)
{
	T max = arrVal[0];
	for (int i = 1; i < n; i++)
		if (max < arrVal[i])
			max = arrVal[i];
	return max;
}

template <> char * maxn<char *>(char ** t, int n)
{
	char * longest = t[0];
	for (int i = 1; i < n; i++)
	{
		if (strlen(longest) < strlen(t[i]))
			longest = t[i];
	}

	return longest;
}
