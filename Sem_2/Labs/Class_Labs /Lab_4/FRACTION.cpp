#include "FRACTION.h" 
FRACTION::FRACTION() : PAIR()
{
	whole_part = 0;
	not_a_whole_part = 0;
}
FRACTION::~FRACTION()
{
}
FRACTION::FRACTION(int C, float P) : PAIR(C, P)
{
	whole_part = C;
	not_a_whole_part = P;
}
FRACTION::FRACTION(const FRACTION& L) : PAIR(L)
{
	whole_part = L.whole_part;
	not_a_whole_part = L.not_a_whole_part;
}

void FRACTION::Set_whole_part(int G)
{
	whole_part = G;
}
void FRACTION::Set_not_a_whole_part(float F)
{
	not_a_whole_part = F;
}
FRACTION& FRACTION::operator=(const FRACTION& l)
{
	if (&l == this) return *this;
	PAIR::operator=(l);
	whole_part = l.whole_part;
	not_a_whole_part = l.not_a_whole_part;
	return *this;
}
istream& operator>>(istream& in, FRACTION& l)
{
	cout << "\nwhole_part:"; in >> l.whole_part;
	cout << "not_a_whole_part:"; in >> l.not_a_whole_part;
	return in;
}
ostream& operator<<(ostream& out, const FRACTION& l)
{
	out << "\nWHOLE_PART : " << l.whole_part;
	out << "\nNOT_A_WHOLE_PART : " << l.not_a_whole_part;
	out << "\n";
	return out;
}
bool FRACTION::operator>(const FRACTION& f)
{
	return whole_part > f.whole_part;
}
bool FRACTION::operator==(const FRACTION& f)
{
	return whole_part == f.whole_part;
}
bool FRACTION::operator<(const FRACTION& f)
{
	return whole_part < f.whole_part;
}