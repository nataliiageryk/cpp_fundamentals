#include <iostream>
#include "Task2.h"

int main() {
	Person one;
	Person two("Smythercraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	one.FormalShow();
	two.Show();
	two.FormalShow();
	three.Show();
	three.FormalShow();
	std::cin.get();
	return 0;
}