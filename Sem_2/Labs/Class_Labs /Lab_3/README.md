# Лабораторная работа  No3 
# Классы и объекты. Перегрузка операций. 

## (1) Задание
1.  Определить пользовательский класс.  
2.  Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.  
3.  Определить в классе деструктор. 
4.  Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы). 
5.  Перегрузить операцию присваивания. 
6.  Перегрузить операции ввода и вывода объектов с помощью потоков. 
7.  Перегрузить операции указанные в варианте. 
8.  Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.
## Вариант 1
Создать класс Time для работы с временными интервалами. Интервал должен быть представлен в виде двух полей: минуты типа int и секунды типа int. при выводе минуты отделяются от секунд двоеточием. Реализовать: 
  -  сложение временных интервалов (учесть, что в минуте не может быть более 60 секунд) 
  -  сравнение временных интервалов (==) 
## (2) Реализация 
- приколюшная main функция:
```cpp
#include "Time.h" 
#include <iostream> 
using namespace std;
int main()
{
	system("chcp 1251 > Null");
	Time a;
	Time b;
	Time c;
	cout << "Введите значения первой временной точки:" << endl;
	cin >> a;
	cout << "Введите значения второй временной точки:" << endl;
	cin >> b;
	c = a + b;
	cout << "Первый временной интервал: " << a << endl;
	cout << "Вторая временной интервал: " << b << endl;
	cout << "Сумма временных интервалов : " << c << endl;
	if (a.get_min() == b.get_min() && a.get_sec() == b.get_sec())
	{
		cout << "Временные интервалы равны" << endl;
	}
	else
	{
		cout << "! Временные интервалы не равны !" << endl;
	}
	return 0;
}
```
- Time.cpp
```cpp
#include "Time.h" 
#include <iostream> 
using namespace std;
Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time& Time::operator++()
{
	int temp = min * 60 + sec;
	temp++;
	min = temp / 60;
	sec = temp % 60;
	return *this;
}
Time Time::operator ++(int)
{
	int temp = min * 60 + sec;
	temp++;
	Time t(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t;
}
Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "Минуты:  "; in >> t.min;
	cout << "Секунды: "; in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{

	return (out << t.min << " : " << t.sec);
}
```
- Time.h
```cpp
#pragma once

#include <iostream> 
using namespace std;

class Time
{
	int min, sec;
public:
	Time() 
	{
		min = 0; sec = 0; 
	};
	Time(int m, int s) 
	{ 
		min = m; sec = s; 
	}
	Time(const Time& t) 
	{ 
		min = t.min; sec = t.sec; 
	}
	~Time() {};

	int get_min()
	{ 
		return min; 
	}
	int get_sec() 
	{
		return sec; 
	}
	void set_min(int m) 
	{ 
		min = m; 
	}
	void set_sec(int s) 
	{
		sec = s; 
	}
	Time& operator=(const Time&);
	Time& operator++();
	Time operator++(int); 
	Time operator+(const Time&);
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};
```
## (3) UML - диаграмма
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_3/UML_3CL.png">
  
## (4) Тест
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_3/изображение_2024-04-21_151118146.png">

## (5) Ответы на вопросы
Q _ Q
