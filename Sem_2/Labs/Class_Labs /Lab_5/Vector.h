#pragma once 
#include "object.h" 
#include <string> 
#include <iostream> 
using namespace std;
class Vector
{
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void); 
	void Add(object*); 
	friend ostream& operator<<(ostream& out, const Vector&); 
private:
	object** beg;
	int size;
	int cur;
};