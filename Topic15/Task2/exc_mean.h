// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean(): std::logic_error("")
	{
	}
	const char * what() const;
};

inline const char * bad_hmean::what() const
{
	return "bad_hmean::show: invalid arguments: a = -b\n";
}

class bad_gmean : std::logic_error
{
public:
	bad_gmean(): std::logic_error("") {}
	const char * what() const;
};
inline const char * bad_gmean::what() const
{
	return "bad_gmean::show: arguments should be >= 0\n";
}