#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
private:
enum {Lbs_per_stn = 14}; // pounds per stone
enum Mode {STN, PND};
int stone; // whole stones
double pds_left; // fractional pounds
double pounds; // entire weight in pounds
Mode mode;
public:
Stonewt(double lbs); // constructor for double pounds
Stonewt(int stn, double lbs); // constructor for stone, lbs
Stonewt(); // default constructor
~Stonewt();
bool operator<(const Stonewt & st) const;
bool operator>(const Stonewt & st) const;
bool operator<=(const Stonewt & st) const;
bool operator>=(const Stonewt & st) const;
bool operator==(const Stonewt & st) const;
bool operator!=(const Stonewt & st) const;
friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};
#endif