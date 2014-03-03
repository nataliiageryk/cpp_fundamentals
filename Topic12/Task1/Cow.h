#ifndef COW_H_
#define COW_H_

class Cow {
	static const int SIZE = 20;
	char name[SIZE];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const; // display all cow data
};

#endif