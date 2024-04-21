# Лабораторная работа  No4
# Простое наследование. Принцип подстановки. 

## (1) Задание
1.  Определить пользовательский класс.  
2.  Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.  
3.  Определить в классе деструктор. 
4.  Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы). 
5.  Перегрузить операцию присваивания. 
6.  Перегрузить операции ввода и вывода объектов с помощью потоков. 
7.  Определить производный класс. 
8.  Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций. 
9.  Реализовать функции, получающие и возвращающие объект базового класса. Продемонстрировать принцип подстановки.
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
#include <iostream> 
#include "PAIR.h"
#include "FRACTION.h" 
using namespace std;
int main()
{
    system("chcp 1251 > Null");
    cout << "Часть задания свазянная с PAIR\n";
    PAIR a(25, 100);
    a.update(250, 1000);
    cout << a << endl;
    cout << "Введите первое и второе число для A\n";
    cin >> a;
    cout << a;
    cout << "Введите первое и второе число для B\n";
    PAIR b(25, 300);
    cin >> b;
    cout << b;
    if (a > b) 
    {
        cout << "A больше B" << endl;
    }
    else 
    {
        cout << "B больше A" << endl;
    }
    cout << "\nЧасть задания свазянная с FRACTION\n";
    FRACTION t(25, 0.5);
    cout << t;
    cin >> t;
    cout << t;
    return 0;
}
```
- Pair.cpp
```cpp
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
```
- Pair.h
```cpp
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
```
- FRACTION.cpp
```cpp
#include "FRACTION.h" 
FRACTION::FRACTION() : PAIR()
{
	whole_part = 0;
	not_a_whole_part = 0;
}
FRACTION::~FRACTION()
{
}
FRACTION::FRACTION(int C, float P) : PAIR(C, P)
{
	whole_part = C;
	not_a_whole_part = P;
}
FRACTION::FRACTION(const FRACTION& L) : PAIR(L)
{
	whole_part = L.whole_part;
	not_a_whole_part = L.not_a_whole_part;
}

void FRACTION::Set_whole_part(int G)
{
	whole_part = G;
}
void FRACTION::Set_not_a_whole_part(float F)
{
	not_a_whole_part = F;
}
FRACTION& FRACTION::operator=(const FRACTION& l)
{
	if (&l == this) return *this;
	PAIR::operator=(l);
	whole_part = l.whole_part;
	not_a_whole_part = l.not_a_whole_part;
	return *this;
}
istream& operator>>(istream& in, FRACTION& l)
{
	cout << "\nwhole_part:"; in >> l.whole_part;
	cout << "not_a_whole_part:"; in >> l.not_a_whole_part;
	return in;
}
ostream& operator<<(ostream& out, const FRACTION& l)
{
	out << "\nWHOLE_PART : " << l.whole_part;
	out << "\nNOT_A_WHOLE_PART : " << l.not_a_whole_part;
	out << "\n";
	return out;
}
bool FRACTION::operator>(const FRACTION& f)
{
	return whole_part > f.whole_part;
}
bool FRACTION::operator==(const FRACTION& f)
{
	return whole_part == f.whole_part;
}
bool FRACTION::operator<(const FRACTION& f)
{
	return whole_part < f.whole_part;
}
```
- FRACTION.h
```cpp
#pragma once 
#include "PAIR.h" 
class FRACTION : public PAIR
{
public:
    FRACTION(); 
    ~FRACTION(); 
    FRACTION(int, float); 
    FRACTION(const FRACTION&); 
    int Get_whole_part()
    { 
        return whole_part;
    }
    float Get_not_a_whole_part()
    {
        return not_a_whole_part;
    } 
    void Set_whole_part(int);
    void Set_not_a_whole_part(float);
    FRACTION& operator=(const FRACTION&); 
    friend istream& operator>>(istream& in, FRACTION& l); 
    friend ostream& operator<<(ostream& out, const FRACTION& l); 
    bool operator>(const FRACTION& f);
    bool operator==(const FRACTION& f);
    bool operator<(const FRACTION& f);
protected:
    int whole_part; 
    float not_a_whole_part;
};
```

## (3) UML - диаграмма
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_4/UML_4CL.png">
  
## (4) Тест
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_4/изображение_2024-04-21_151533769.png">

## (5) Ответы на вопросы
Q _ Q
