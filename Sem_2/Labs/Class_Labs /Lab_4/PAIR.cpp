#include "PAIR.h" 
PAIR::PAIR(void)
{
	first = 0;
	second = 0;
}
PAIR::~PAIR(void)
{
}
PAIR::PAIR(int C, int P)
{
	first = C;
	second = P;
}
PAIR::PAIR(const PAIR& pair)
{
	first = pair.first;
	second = pair.second;
}
void PAIR::Set_first(int C)
{
	first = C;
}
void PAIR::Set_second(int P)
{
	second = P;
}
PAIR& PAIR::operator=(const PAIR& c)
{
	if (&c == this)return *this;
	first = c.first;
	second = c.second;
	return *this;
}
istream& operator>>(istream& in, PAIR& c)
{
	cout << "\nfirst:"; in >> c.first;
	cout << "second:"; in >> c.second;
	return in;
}
ostream& operator<<(ostream& out, const PAIR& c)
{
	out << "\nFIRST : " << c.first;
	out << "\nSECOND : " << c.second;
	out << "\n";
	return out;
}
bool PAIR::operator>(const PAIR& p)
{
	return (first > p.first) || (first == p.first && second > p.second);
}
void PAIR::update(int f, int s) {
	first = f;
	second = s;
}
