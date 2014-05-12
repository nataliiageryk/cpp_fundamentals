// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>
#include <sstream>



class exc_base : public std::logic_error
{
private:
	double a;
	double b;
public:
	exc_base(double a_val, double b_val) : std::logic_error(""), a(a_val), b(b_val) {}
	double reportA() const { return a; }
	double reportB() const { return b; }
	void reportAB() const;
	virtual void report();
};

class bad_hmean : public exc_base
{
public:
	bad_hmean(double a, double b) : exc_base(a,b) {}
 	const char * what() const;
	virtual void report();
};

inline const char * bad_hmean::what() const
{
std::stringstream ss;
ss << "text" << 123 << 123.4;
ss.str().c_str()

	return "bad_hmean::show: invalid arguments: a = -b\n";
}

class bad_gmean : public exc_base
{
public:
	bad_gmean(double a, double b): exc_base(a,b) {}
	const char * what() const;
	virtual void report();
};
inline const char * bad_gmean::what() const
{
	return "bad_gmean::show: arguments should be >= 0\n";
}