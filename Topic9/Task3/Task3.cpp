#include <iostream>
#include <istream>

using std::cin;
using std::cout;
using std::endl;

const int SIZE = 2;
const int ARR_SIZE = 20;

struct chaff{
	char dross[ARR_SIZE];
	int slag;
};

void setChaff(chaff *, int n = 1);
char * statArrAlloc(const int n);
char * dynamicAlloc(const int n);

int main()
{
	int option = 1;
	cout << "Press 1 to use static array. 2 for new operation. \n";
	while (!(cin >> option) || (option != 1 && option !=2))
	{
		cin.clear();
		while (cin.get() != '\n')
		{}
		cout << "Bad input. Try again. 1 - for static array, 2 - for new op-tion.\n";
	}
	cin.get();

	char * buffer = 0;
	if (option == 1)
		buffer = statArrAlloc(SIZE); 
	else 
		buffer = dynamicAlloc(SIZE);
	
	chaff * chaffArr = new (buffer) chaff[SIZE];
	setChaff(chaffArr, SIZE);
	cin.get();
	return 0;
}

void setChaff(chaff * inp, int n)
{
	for (int i = 0; i < n; i++)
	{


		if (n > 1)
			cout << "Structure #" << i + 1 << ": \n";
		
		//dross input 
		cout << "Enter dross: ";
		
		//using temporary variable
		char tmp[ARR_SIZE];
		cin.get(tmp, ARR_SIZE);

		//reading remaining symbols
		while (cin.get() != '\n')
			{continue;}

		//setting chaff dross member 
		strncpy(inp->dross, tmp, ARR_SIZE - 1);
		inp->dross[ARR_SIZE-1] = 0;

		//input slag
		cout << "Enter slag: ";
		
		//bad input handling
		while (!(cin >> inp->slag))
		{
			cin.clear();
			while (cin.get() != '\n')
				{continue;}
			cout << "Bad input. Try again.\n";
		}

	cin.get();
	}
}

char * statArrAlloc(const int n)
{
	//const int s = n * sizeof(chaff);
	
	char buffer [SIZE * sizeof(chaff) + (SIZE + ARR_SIZE) * sizeof(int)];
	return buffer;
}

char * dynamicAlloc(const int n)
{
	char * buffer = new char[sizeof(chaff)*n + (n + ARR_SIZE) * sizeof(int)];
	return buffer;
}