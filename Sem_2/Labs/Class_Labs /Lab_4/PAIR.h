#pragma once
#include <string> 
#include <iostream> 
using namespace std;
class PAIR
{
public:
	PAIR(void);
public:
	virtual ~PAIR(void);
	PAIR(int, int);
	PAIR(const PAIR&);
	int Get_first() { return first; }
	int Get_second() { return second; }
	void Set_first(int);
	void Set_second(int);
	PAIR& operator=(const PAIR&);
	friend istream& operator>>(istream& in, PAIR& c);
	friend ostream& operator<<(ostream& out, const PAIR& c);
	bool operator>(const PAIR& p);
	void update(int first, int second);
protected:
	int first;
	int second;
};