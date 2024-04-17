# Лабораторная работа  No2 
# Классы и объекты. Использование конструкторов. 

## (1) Задание
1.  Определить пользовательский класс.  
2.  Определить в классе следующие конструкторы: без параметров, с параметрами, 
копирования.  
3.  Определить в классе деструктор. 
4.  Определить в классе компоненты-функции для просмотра и установки полей 
данных (селекторы и модификаторы). 
5.  Написать демонстрационную программу, в которой продемонстрировать все три 
случая вызова конструктора-копирования, вызов конструктора с параметрами и 
конструктора без параметров.
### Вариант 1
Пользовательский класс СТУДЕНТ 
ФИО – string 
Группа – string  
Средний балл – float
## (2) Реализация 
- приколюшная main функция:
```cpp
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
Student make_Student()
{
	string s, i;
	float d;
	cout << "Введите ФИО: ";
	cin >> s;
	cout << "Введите группу: ";
	cin >> i;
	cout << "Укажите средний балл: ";
	cin >> d;
	Student t(s, i, d);
	return t;
}
void print_Student(Student t)
{
	t.show();
}
void main()
{
	system("chcp 1251 > Null");
	Student t1;
	t1.show();
	Student t2("КБД", "ИВТ-23-1б", 23.5);
	t2.show();
	Student t3 = t2;
	t3.set_full_name("ИИИ");
	t3.set_group("5Б");
	t3.set_GPA(3.333);
	print_Student(t3);
	t1 = make_Student();
	t1.show();
}
```
- Student.cpp
```cpp
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
Student::Student()
{
	full_name = "";
	group = "";
	GPA = 0;
	cout << "Конструктор без параметров для объекта: " << this << "\n";
}
Student::Student(string N, string K, float S)
{
	full_name = N;
	group = K;
	GPA = S;
	cout << "Конструктор с параметрами для объекта: " << this << "\n";
}
Student::Student(const Student &t)
{
	full_name = t.full_name;
	group = t.group;
	GPA = t.GPA;
	cout << "Конструктор копирования для объекта: " << this << "\n";
}
Student::~Student()
{
	cout << "Деструктор для объекта: " << this << "\n";
}
string Student::get_full_name()
{
	return full_name;
}
string Student::get_group()
{
	return group;
}
float Student::get_GPA() const
{
	return GPA;
}
void Student::set_full_name(string N)
{
	full_name = N;
}
void Student::set_group(string K)
{
	group = K;
}
void Student::set_GPA(float S)
{
	GPA = S;
}
void Student::show() const
{
	cout << "ФИО: " << full_name
		 << "\nгруппа: " << group
	     << "\nсредний балл: " << GPA << "\n\n";
}
```
- Student.h
```cpp
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student
{
	string full_name, group;
	float GPA;
public:
	Student();
	Student(string, string, float);
	Student(const Student&);
	~Student();
	string get_full_name();
	void set_full_name(string);
	string get_group();
	void set_group(string);
	float get_GPA();
	void set_GPA(float);
	void show();
};
```
## (3) UML - диаграмма
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_2/UML_CL2.png">
  
## (4) Тесты
```cpp
/*
			Test 1
Конструктор без параметров для объекта: 00000087FCBDF710
ФИО:
группа:
средний балл: 0

Конструктор с параметрами для объекта: 00000087FCBDF790
ФИО: КБД
группа: ИВТ-23-1б
средний балл: 23.5

Конструктор копирования для объекта: 00000087FCBDF810
Конструктор копирования для объекта: 00000087FCBDFC48
ФИО: ИИИ
группа: 5Б
средний балл: 3.333

Деструктор для объекта: 00000087FCBDFC48
Введите ФИО: ВВП
Введите группу: БОГ
Укажите средний балл: 777
Конструктор с параметрами для объекта: 00000087FCBDFCE0
Деструктор для объекта: 00000087FCBDFCE0
ФИО: ВВП
группа: БОГ
средний балл: 777

Деструктор для объекта: 00000087FCBDF810
Деструктор для объекта: 00000087FCBDF790
Деструктор для объекта: 00000087FCBDF710



			Test 2
Конструктор без параметров для объекта: 000000E5E7FEF000
ФИО:
группа:
средний балл: 0

Конструктор с параметрами для объекта: 000000E5E7FEF080
ФИО: КБД
группа: ИВТ-23-1б
средний балл: 23.5

Конструктор копирования для объекта: 000000E5E7FEF100
Конструктор копирования для объекта: 000000E5E7FEF538
ФИО: ИИИ
группа: 5Б
средний балл: 3.333

Деструктор для объекта: 000000E5E7FEF538
Введите ФИО: АКА
Введите группу: Творческая
Укажите средний балл: 26
Конструктор с параметрами для объекта: 000000E5E7FEF5D0
Деструктор для объекта: 000000E5E7FEF5D0
ФИО: АКА
группа: Творческая
средний балл: 26

Деструктор для объекта: 000000E5E7FEF100
Деструктор для объекта: 000000E5E7FEF080
Деструктор для объекта: 000000E5E7FEF000


			Test 3
Конструктор без параметров для объекта: 000000B2529DF210
ФИО:
группа:
средний балл: 0

Конструктор с параметрами для объекта: 000000B2529DF290
ФИО: КБД
группа: ИВТ-23-1б
средний балл: 23.5

Конструктор копирования для объекта: 000000B2529DF310
Конструктор копирования для объекта: 000000B2529DF748
ФИО: ИИИ
группа: 5Б
средний балл: 3.333

Деструктор для объекта: 000000B2529DF748
Введите ФИО: ФИО
Введите группу: Рок
Укажите средний балл: 666
Конструктор с параметрами для объекта: 000000B2529DF7E0
Деструктор для объекта: 000000B2529DF7E0
ФИО: ФИО
группа: Рок
средний балл: 666

Деструктор для объекта: 000000B2529DF310
Деструктор для объекта: 000000B2529DF290
Деструктор для объекта: 000000B2529DF210
*/
```

## (5) Ответы на вопросы
Q _ Q
