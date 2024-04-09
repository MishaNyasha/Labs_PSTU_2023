#include "Pair.h" 
Pair::Pair(void)
{
	first = 0;
	second = 0;
}
Pair::~Pair(void)
{
}
Pair::Pair(int C, int P)
{
	first = C;
	second = P;
}
Pair::Pair(const Pair& pair)
{
	first = pair.first;
	second = pair.second;
}
void Pair::Set_first(int C)
{
	first = C;
}
void Pair::Set_second(int P)
{
	second = P;
}
Pair& Pair::operator=(const Pair& c)
{
	if (&c == this)return *this;
	second = c.second;
	first = c.first;
	return *this;
}
istream& operator>>(istream& in, Pair& c)
{
	cout << "\nfirst:"; in >> c.first;
	cout << "second:"; in >> c.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& c)
{
	out << "\nFIRST : " << c.first;
	out << "SECOND : " << c.second;
	out << "\n";
	return out;
}
void Pair::Show()
{
	cout << "\nFIRST : " << first;
	cout << "\nSECOND : " << second;
	cout << "\n";
}

bool Pair::operator>(const Pair& p)
{
	return (first > p.first) || (first == p.first && second > p.second);
}