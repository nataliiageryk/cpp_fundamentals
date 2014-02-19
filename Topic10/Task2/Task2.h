#ifndef TASK2_H_
#define TASK2_H_
#include <string>
using std::string;

class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() {lname = ""; fname[0] = '\0'; }
	Person(const string & ln, const char * fn = "Hayyou");
	void Show() const;			//firstname, lastname format
	void FormalShow() const;	//lastname, firstname format
};
#endif // !TASK2_H_
