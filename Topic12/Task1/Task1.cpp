#include "Cow.h"
#include <iostream>
using std::cin;
int main()
{
	{
	Cow first;
	first.ShowCow();
	char arr[20] = "Somebody";
	Cow second(arr, "SomeHobby", 12);
	second.ShowCow();
	first = second;
	first.ShowCow();
	Cow third(second);
	third.ShowCow();
	
	cin.get();
	}
}