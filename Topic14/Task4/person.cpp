#include "person.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

void Person::Show()
{
	cout << "Name: " << name << ", Surname: " << last_name << endl;
}

void Gunslinger::Show()
{
	Person::Show();
	cout << "Notches: " << notches << ", Draw Time: " << draw_time << endl;
}

double Gunslinger::Draw()
{
	return draw_time;
}

double PokerPlayer::Draw()
{
	return double(rand()%52 + 1);
}

void BadDude::Show()
{
	Gunslinger::Show();
	this->ShowCard();
	cout << "CardNumber: " << this->ShowCard() << endl;
}