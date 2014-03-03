#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	Stack stack(5);
	Item arr[5] = {5,9,6,10,11};
	stack.push(arr[0]);
	Stack second = Stack(stack);
	Item tmp;
	stack.pop(tmp);
	cout << tmp << endl;
	cout << "Is stack empty? - " << std::boolalpha << bool(stack.isempty())<<endl;
	cout << "Is second empty? - " << std::boolalpha << (bool) second.isempty()<<endl;
	second.push(arr[1]);
	second.push(arr[2]);
	second.push(arr[3]);
	second.push(arr[4]);
	cout << std::boolalpha << "Is second full? - " << (bool) second.isfull()<<endl;
	second.pop(tmp);
	cout << tmp;
	cin.get();
	return 0;
}