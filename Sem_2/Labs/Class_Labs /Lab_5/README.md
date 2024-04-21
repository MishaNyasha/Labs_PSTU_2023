# Лабораторная работа  No4
# Простое наследование. Принцип подстановки. 

## (1) Задание
1.  Определить абстрактный класс.  
2.  Определить иерархию классов, в основе которой будет находиться абстрактный класс (см. лабораторную работу No4). 
3.  Определить класс Вектор, элементами которого будут указатели на объекты иерархии классов. 
4.  Перегрузить для класса Вектор операцию вывода объектов с помощью потоков. 
5.  В основной функции продемонстрировать перегруженные операции и полиморфизм Вектора.
## Вариант 1
Базовый класс: 
ПАРА_ЧИСЕЛ (PAIR) 
Первое_число (first) - int 
Второе_число (second) – int 
Определить методы изменения полей и сравнения пар (пара p1 больше пары р2, если (p1.first>p2.first) || (p1.first==p2.first &&p1.second>p2.second). 
Создать производный класс ДРОБЬ (FRACTION), с полями Целая_часть_числа и Дробная_часть_числа. Определить полный набор методов сравнения. 
## (2) Реализация 
- приколюшная main функция:
```cpp
#include "Object.h" 
#include "Pair.h" 
#include "Fraction.h" 
#include "Vector.h"
#include <string> 
#include <iostream> 
using namespace std;
void main()
{
	system("chcp 1251 > Null");
	cout << "Первая часть задания ну типа:\n";
	Pair a;
	cin >> a;
	cout << "\nЗначения для А:";
	object* p = &a;
	p->Show();
	
	cout << "\nВведите значения для B:";
	Pair b;
	cin >> b;

	if (a > b)
	{
		cout << "\nA больше B" << endl;
	}
	else
	{
		cout << "\nB больше A" << endl;
	}
	cout << "Вторая часть задания ну типа:\n";
	Fraction g;
	cin >> g;
	p = &g;
	p->Show();

	Vector v(5);
	Pair c;
	cin >> c;
	Fraction d;
	cin >> d;
	object* m = &c;
	v.Add(m);
	m = &d;
	v.Add(m);
	cout << v;
}
```
- Pair.cpp
```cpp
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
```
- Pair.h
```cpp
#pragma once 
#include "object.h" 
#include <string> 
#include <iostream> 
using namespace std;
class Pair :
	public object
{
public:
	Pair(void);
public:
	virtual ~Pair(void);
	void Show();
	Pair(int, int);
	Pair(const Pair&);
	int Get_first() { return first; }
	int Get_second() { return second; }
	void Set_first(int);
	void Set_second(int);
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);
	bool operator>(const Pair& p);
protected:
	int first;
	int second;
};
```
- Fraction.cpp
```cpp
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
```
- Fraction.h
```cpp
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
```
- Vector.cpp
```cpp
#include "Vector.h"
Vector::Vector(void)
{
    beg = 0;
    size = 0;
    cur = 0;
}
Vector::~Vector(void)
{
    if (beg != 0)delete[] beg;
    beg = 0;
}
Vector::Vector(int n)
{
    beg = new object * [n];
    cur = 0;
    size = n;
}
void Vector::Add(object* p)
{
    if (cur < size)
    {
        beg[cur] = p;
        cur++;
    }
}
ostream& operator<<(ostream& out, const Vector& v)
{
    if (v.size == 0) out << "Empty" << endl;
    object** p = v.beg;
    for (int i = 0; i < v.cur; i++)
    {
        (*p)->Show();
        p++;
    }

    return out;
}
```
- Vector.h
```cpp
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
```
- object.cpp
```cpp
#include "object.h"

object::object(void)
{
}

object::~object(void)
{
}
```
- object.h
```cpp
#pragma once 
class object
{
public:
	object(void);
public:
	~object(void);
	virtual void Show() = 0;
};
```

## (3) UML - диаграмма
<image src ="">
  
## (4) Тест
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_5/изображение_2024-04-21_164258936.png">

## (5) Ответы на вопросы
Q _ Q
