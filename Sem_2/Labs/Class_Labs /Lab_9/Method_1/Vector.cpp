#include "Vector.h"
Vector::Vector(int s) 
{ 
if(s>MAX_SIZE) throw 1; 
  size=s; 
  beg=new int [s]; 
  for(int i=0;i<size;i++) 
    beg[i]=0; 
} 
Vector::Vector(const Vector &v) 
{ 
  size=v.size; 
  beg=new int [size]; 
  for(int i=0;i<size;i++) 
    beg[i]=v.beg[i]; 
} 
Vector::~Vector() 
{ 
  if (beg!=0) delete[]beg; 
} 
Vector::Vector(int s,int *mas) 
{ 
if(s>MAX_SIZE) throw 1; 
  size=s; 
  beg=new int[size]; 
  for(int i=0;i<size;i++) 
    beg[i]=mas[i]; 
} 
const Vector& Vector::operator =(const Vector &v) 
{ 
  if(this==&v)return *this; 
  if(beg!=0) delete []beg; 
  size=v.size; 
  beg=new int [size]; 
  for(int i=0;i<size;i++) 
    beg[i]=v.beg[i]; 
  return*this; 
} 
 
ostream& operator<<(ostream&out, const Vector&v) 
{ 
  if(v.size==0) out<<"Empty\n"; 
  else 
  { 
  for (int i=0;i<v.size;i++) 
    out<<v.beg[i]<<" "; 
  out<<endl; 
  } 
  return out; 
} 
istream& operator >>(istream&in, Vector&v) 
{ 
  for(int i=0;i<v.size;i++) 
  { 
    cout<<">"; 
    in>>v.beg[i]; 
  } 
  return in; 
} 
int Vector::operator[](int i)
{
    if (i < 0) throw 2;
    if (i >= size) throw 1;
    return beg[i];
}

Vector Vector::operator+(const int k)
{
	Vector temp(size);
	for (int i = 0; i < size; ++i)
		temp.beg[i] = beg[i] + k;
	return temp;
}
Vector Vector::operator ++()
{
	if (size == 0) throw 5;
	if (size >= MAX_SIZE) throw 4;
	Vector temp(size, beg);
	delete[]beg;
	size++;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];
	return*this;
}
Vector Vector::operator --()
{
	if (size == 0) throw 5;
	if (size == 1)
	{
		size = 0;
		delete[]beg;
		beg = 0;
		return *this;
	};
	Vector temp(size, beg);
	delete[]beg;
	size--;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];
	return*this;
}
