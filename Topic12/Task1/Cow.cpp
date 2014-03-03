#include "Cow.h"
#include <iostream>

Cow::Cow()
{
	name[0] = '\0'; 
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	strncpy(name,nm,SIZE-1);
	name[SIZE-1] = '\0'; 

	int len = strlen(ho);
	hobby = new char[len+1];
	strcpy(hobby,ho);
	hobby[len] = '\0';
	
	weight = wt;
}

Cow::Cow(const Cow & c)
{
	strncpy(name,c.name, SIZE);
		
	int len = strlen(c.hobby);
	hobby = new char[len+1];
	strcpy(hobby,c.hobby);
	hobby[len] = '\0';

	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	if (&c == this)
		return *this;
	strncpy(name,c.name,SIZE);
	
	delete [] hobby;
	int len = strlen(c.hobby+1);
	hobby = new char[len];
	strcpy(hobby,c.hobby);
	hobby[len] = '\0';
	
	weight = c.weight;
	return *this;
}
	
void Cow::ShowCow() const // display all cow data
{
	using std::cout;
	using std::endl;
	cout << "Name: " << name << ", hobby: " << hobby << ", weight: " << weight << endl;
}