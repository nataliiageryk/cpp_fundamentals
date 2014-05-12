#ifndef CD_H_
#define CD_H_

class Cd
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	~Cd();
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char * primaryWork;
public:
	Classic(char * prm, char * s1, char * s2, int n, double x);
	Classic(char * prm, Cd & cd1);
	Classic();
	Classic(const Classic & cl1);
	~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic &);
};
#endif CD_H_