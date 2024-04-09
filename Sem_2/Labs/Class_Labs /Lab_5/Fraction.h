#pragma once 
#include "Pair.h" 
class Fraction :
	public Pair
{
public:
	Fraction(void);
public:
	~Fraction(void);
	void Show();
	Fraction(int, int);
	Fraction(const Fraction&);
	int Get_whole_part() { return whole_part; }
	void Set_whole_part(int);
	int Get_not_whole_part() { return not_whole_part; }
	void Set_not_whole_part(int);
	Fraction& operator=(const Fraction&);
	friend istream& operator>>(istream& in, Fraction& l);
	friend ostream& operator<<(ostream& out, const Fraction& l);
protected:
	int whole_part;
	int not_whole_part;
};