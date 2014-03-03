#include "Stack.h"

Stack::Stack(int n) // creates stack with n elements
{
	if (n <= MAX)
	pitems = new Item[n];
	else 
		pitems = new Item[MAX];

	size = n;
	top = 0;
}

Stack::Stack(const Stack & st)
{
	size = st.size;
	pitems = new Item[size];
	top = st.top;
	
	for ( int i = 0; i < top; i++)
		pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

// push() returns false if stack already is full, true otherwise
bool Stack::push(const Item & item) // add item to stack
{
	if (isfull())
		return false;
	else
	{
		pitems[top] = item;
		top++;
		return true;
	}
}

// pop() returns false if stack already is empty, true otherwise
bool Stack::pop(Item & item) // pop top into item
{
	if (isempty())
		return false;
	else
	{
		item = pitems[--top];
		return true;
	}
}
Stack & Stack::operator=(const Stack & st)
{
	if (this == & st)
		return *this;
	size = st.size;
	delete [] pitems;
	pitems = new Item[size];
	top = st.top;
	
	for ( int i = 0; i < top; i++)
		pitems[i] = st.pitems[i];
	return *this;
}