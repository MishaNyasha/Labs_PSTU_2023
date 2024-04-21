# Лабораторная работа  No9 
# Обработка исключительных ситуаций. 

## (1) Задание
1.  Реализовать класс, перегрузить для него операции, указанные в варианте. 
2.  Определить исключительные ситуации.  
3.  Предусмотреть генерацию исключительных ситуаций.
## Вариант 1
Класс- контейнер ВЕКТОР с элементами типа int. 
Реализовать операции: 
[] – доступа по индексу; 
() – определение размера вектора; 
+ число – добавляет константу ко всем элементам вектора; 
- n- удаляет n элементов из конца вектора.
## (2) Реализация 
### 1 Вариант реализации
- приколюшная main функция:
```cpp
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        int q;
        cout << "введите размер вектора x (до 30): ";
        cin >> q;
        Vector x(q);
        cout << "пустой вектор x: " << x << endl;
        cout << "заполните вектора x:\n";
        cin >> x;
        cout << "заполненный вектора x: " << x << endl;

        cout << "введите индекс = ";
        int i;
        cin >> i;
        cout << x[i] << endl;

        Vector y(5);
        cout << "пустой вектор y:" << y << endl;
        cout << "заполните вектор y: \n";
        cin >> y;
        cout << "заполненный вектора y: " << y << endl;

        cout << "операция добавления константы '3' ко всем элементам вектора y : ";
        const int k = 3;
        y = y + k;
        cout << endl << y;

        cout << "операция удаления '2' элементов из конца вектора y: ";
        --y;
        --y;
        cout << endl << y;
    }
    catch (int errorcode)
    {
        if (errorcode == 1)
            cout << "error: vector length more than maxsize" << endl;
        else if (errorcode == 2)
            cout << "error: negative index" << endl;
        else if (errorcode == 4)
            cout << "error: vector length would exceed maxsize" << endl;
        else if (errorcode == 5)
            cout << "error: vector is empty, cannot remove element" << endl;
    }
    return 0;
}
```
- Vector.cpp
```cpp
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
```
- Vector.h
```cpp
#pragma once 
#include <iostream> 
using namespace std;
const int MAX_SIZE = 30; 
class Vector
{
	int size; 
	int* beg; 
public:
	Vector() { size = 0; beg = 0; } 
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector& v);
	~Vector(); 
	const Vector& operator=(const Vector& v);
	int operator[](int i);
	Vector operator+(const int k);
	Vector operator--();
	Vector operator++();
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
};
```
### 2 Вариант реализации
- приколюшная main функция:
```cpp
#include "Vector.h" 
#include "Error.h" 
#include <iostream> 
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
	try
	{
        int q;
        cout << "введите размер вектора x (до 30): ";
        cin >> q;
        Vector x(q);
        cout << "пустой вектор x: " << x << endl;
        cout << "заполните вектора x:\n";
        cin >> x;
        cout << "заполненный вектора x: " << x << endl;

        cout << "введите индекс = ";
        int i;
        cin >> i;
        cout << x[i] << endl;

        Vector y(5);
        cout << "пустой вектор y:" << y << endl;
        cout << "заполните вектор y: \n";
        cin >> y;
        cout << "заполненный вектора y: " << y << endl;

        cout << "операция добавления константы '3' ко всем элементам вектора y : ";
        const int k = 3;
        y = y + k;
        cout << endl << y;

        cout << "операция удаления '2' элементов из конца вектора y: ";
        --y;
        --y;
        cout << endl << y;
	}

	catch (error e)
	{
		e.what();
	}

	return 0;
}
```
- Vector.cpp
```cpp
#include "Vector.h"
#include "Error.h" 
#include <iostream> 
using namespace std;

Vector::Vector(int s)
{
    if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++)
        beg[i] = 0;
}
Vector::Vector(const Vector& v)
{
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}
Vector::~Vector()
{
    if (beg != 0) delete[]beg;
}
Vector::Vector(int s, int* mas)
{
    if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = mas[i];
}
const Vector& Vector::operator =(const Vector& v)
{
    if (this == &v)return *this;
    if (beg != 0) delete[]beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
    return*this;
}

ostream& operator<<(ostream& out, const Vector& v)
{
    if (v.size == 0) out << "Empty\n";
    else
    {
        for (int i = 0; i < v.size; i++)
            out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}
istream& operator >>(istream& in, Vector& v)
{
    for (int i = 0; i < v.size; i++)
    {
        cout << ">";
        in >> v.beg[i];
    }
    return in;
}
int Vector::operator [](int i)
{
    if (i < 0) throw error("index <0");
    if (i >= size) throw error("index>size");
    return beg[i];
}
Vector Vector::operator+(const int k)
{
    Vector temp(size);
    for (int i = 0; i < size; ++i)
        temp.beg[i] = beg[i] + k;
    return temp;
}

Vector Vector::operator --()
{
    if (size == 0) throw error("Vector is empty");
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
```
- Vector.h
```cpp
#pragma once 
#include <iostream> 
using namespace std;
const int MAX_SIZE = 30;
class Vector
{
	int size;
	int* beg;
public:
	Vector() { size = 0; beg = 0; }
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector& v);
	~Vector();
	const Vector& operator=(const Vector& v);
	int operator[](int i);
	Vector operator+(const int k);
	Vector operator--();
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
};
```
- error.h
```cpp
#pragma once 
#include <string> 
#include <iostream> 
using namespace std;
class error
{
	string str;
public: 
	error(string s) { str = s; }
	void what() { cout << str << endl; }
};
```

## (3) UML - диаграмма
<image src ="">
  
## (4) Тесты
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_9/Method_1/изображение_2024-04-21_215231461.png">
