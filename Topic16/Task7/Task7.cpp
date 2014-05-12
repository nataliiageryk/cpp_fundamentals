#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

std::vector<int> Lotto(int range, int num);
void display(const int & val);

int main()
{
	std::cout << "Enter the number of values on the lotto card: ";
	int number;
	std::cin >> number;
	std::cout << "Enter the range value for number in lotto card: ";
	int range;
	std::cin >> range;
	while (std::cin)
	{
		std::vector<int> new_card = Lotto(range,number);
		std::cout << "Here is lotto card combination: \n";
		for_each(new_card.begin(), new_card.end(), display);
		std::cout << std::endl;
		std::cout << "Enter the number of values on the lotto card (q to exit): ";
		std::cin >> number;
		std::cout << "Enter the range value for number in lotto card: ";
		std::cin >> range;
	}
	std::cin.get();
	return 0;
}

std::vector<int> Lotto(int range, int num)
{
	if(range < num)
	{
		std::cout << "Range cannot be less than number of values on the card";
		std::cout << " Setting range = num = " << num;
		range = num;
	}
	std::vector<int> card(range);
	std::iota( card.begin(), card.end(), 1);
	std::random_shuffle(card.begin(), card.end());
	card.erase(card.begin() + num, card.end());
	return card;
}

void display(const int & val)
{
	std::cout << val << " ";
}