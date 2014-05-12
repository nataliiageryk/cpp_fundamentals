#ifndef PERSON_H_
#define PERSON_H_
#include <string>
using std::string;

class Person
{
	string name;
	string last_name;
public:
	Person( const char * nm = "no_name", const char * lst_nm = "no_last_name") : name(nm), last_name(lst_nm) {}
	virtual void Show();
};

class Gunslinger : virtual public Person
{
	int notches;
	double draw_time;
public:
	Gunslinger() : Person() {}
	Gunslinger( int nt, double dr_time, const char * nm, const char * lst_nm) 
		: notches(nt), draw_time(dr_time), Person(nm,lst_nm) {}
	virtual void Show();
	double Draw();
};

class PokerPlayer : virtual public Person
{
	int card;
public:
	PokerPlayer() : Person() {}
	PokerPlayer(int c, const char * nm, const char * lst_nm) : card(c), Person(nm,lst_nm) {}
	//return random card(from 1 to 52)
	double Draw();
	int ShowCard() {return card;}
	void setCardRand() { card = Draw(); }
};

class BadDude : public PokerPlayer, public Gunslinger
{

public:
	BadDude(): Person(), PokerPlayer(), Gunslinger() {}
	BadDude(int cardtmp, int nt, double dr_time, const char * nm, const char * lst_nm) 
		: Person(nm,lst_nm), Gunslinger(nt, dr_time,0,0), PokerPlayer(cardtmp,0,0) {} 
	double Gdraw() {return Gunslinger::Draw();}
	double Cdraw() {return PokerPlayer::Draw();}
	virtual void Show();
};
#endif // !PERSON_H_
