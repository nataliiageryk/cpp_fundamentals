#ifndef HEADERTASK6_H_1
#define HEADERTASK6_H_

class Move
{
public:
	Move(double a = 0, double b = 0); //set x and y to a and b
	~Move();
	void showmove() const;
	Move add(const Move & m) const;
	void reset(double a = 0, double b = 0); //reset x and y to a and b

private:
	double x;
	double y;
};
#endif // !HEADERTASK6_H_1

