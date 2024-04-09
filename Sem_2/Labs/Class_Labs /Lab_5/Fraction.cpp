#include "Fraction.h" 
Fraction::Fraction(void) :Pair()
{
	whole_part = 0;
	not_whole_part = 0;
}
Fraction::~Fraction(void)
{
}
Fraction::Fraction(int C, int P) : Pair(C, P)
{
	whole_part = C;
	not_whole_part = P;
}
Fraction::Fraction(const Fraction& L)
{
	whole_part = L.whole_part;
	not_whole_part = L.not_whole_part;
}
void Fraction::Set_whole_part(int C)
{
	whole_part = C;
}
void Fraction::Set_not_whole_part(int P)
{
	not_whole_part = P;
}
Fraction& Fraction::operator=(const Fraction& l)
{
	if (&l == this)return *this;
	whole_part = l.whole_part;
	not_whole_part = l.not_whole_part;
	return *this;
}
istream& operator>>(istream& in, Fraction& l)
{
	cout << "\nwhole_part:"; in >> l.whole_part;
	cout << "not_whole_part:"; in >> l.not_whole_part;
	return in;
}
ostream& operator<<(ostream& out, const Fraction& l)
{
	out << "\nWHOLE_PART : " << l.whole_part;
	out << "\nNOT_WHOLE_PART : " << l.not_whole_part;
	out << "\n";
	return out;
}
void Fraction::Show()
{
	cout << "\nWHOLE_PART : " << whole_part;
	cout << "\nNOT_WHOLE_PART : " << not_whole_part;
	cout << "\n";
}