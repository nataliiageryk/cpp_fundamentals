#include <iostream>
using std::cout;
using std::ostream;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = int (lbs) / Lbs_per_stn; // integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = PND;
}
// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn +lbs;
	mode = STN;
}
Stonewt::Stonewt() // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	mode = PND;
}
Stonewt::~Stonewt() // destructor
{
}

bool Stonewt::operator<(const Stonewt & st) const
{
	if ( pounds < st.pounds)
		return true;
	else return false;
}
bool Stonewt::operator>(const Stonewt & st) const
{
	if ( pounds > st.pounds)
		return true;
	else return false;
}

bool Stonewt::operator<=(const Stonewt & st) const
{
	if ( pounds <= st.pounds)
		return true;
	else return false;
}

bool Stonewt::operator>=(const Stonewt & st) const
{
	if ( pounds >= st.pounds)
		return true;
	else return false;
}

bool Stonewt::operator==(const Stonewt & st) const
{
	if ( pounds == st.pounds)
		return true;
	else return false;
}

bool Stonewt::operator!=(const Stonewt & st) const
{
	return (pounds != st.pounds);
}

ostream & operator<<(ostream & os, const Stonewt & st)
{
	if ( st.mode == Stonewt::STN )
	{
		cout << st.stone << " stone, " << st.pds_left << " pounds\n";
	}
	else if ( st.mode == Stonewt::PND )
	{
		cout << st.pounds << " pounds\n";
	}

	return os;
}
