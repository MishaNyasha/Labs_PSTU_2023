#include "Time.h" 
Time::Time()
{
	sec = 0; min = 0;
}
Time::Time(int N, int A)
{
	sec = N; min = A;
}
Time::Time(const Time& p)
{
	sec = p.sec; min = p.min;
}
Time Time::operator =(const Time& p)
{
	if (&p == this) return *this;
	sec = p.sec;
	min = p.min;
	return*this;
}
Time::~Time()
{
}
ostream& operator<<(ostream& out, const Time& p)
{
	out << p.min << ":" << p.sec << "\n";
	return out;
}

istream& operator>>(istream& in, Time& p)
{
	cout << "min: "; in >> p.min;
	cout << "sec: "; in >> p.sec;
	cout << endl;
	return in;
}
fstream& operator>>(fstream& fin, Time& p)
{
	fin >> p.sec;
	fin >> p.min;
	return fin;
}
fstream& operator<<(fstream& fout, const Time& p)
{
	fout << p.sec << "\n" << p.min << "\n";
	return fout;
}
bool Time::operator==(const Time& t)
{
	if ((min == t.min) && (sec == t.sec)) return true;
	else return false;
}
