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
**1. Для чего используется механизм наследования?**

`Механизм наследования используется для создания новых классов на основе существующих. Он позволяет классам наследовать свойства и методы других классов, что способствует повторному использованию кода.`

**2. Каким образом наследуются компоненты класса, описанные со спецификатором public?**

`Компоненты класса, описанные со спецификатором public, наследуются также с модификатором public в производном классе. Это означает, что они остаются доступными извне.`

**3. Каким образом наследуются компоненты класса, описанные со спецификатором private?**

`Компоненты класса, описанные со спецификатором private, не наследуются в производном классе. Они остаются закрытыми и недоступными извне.`

**4. Каким образом наследуются компоненты класса, описанные со спецификатором protected?**

`Компоненты класса, описанные со спецификатором protected, наследуются с модификатором protected в производном классе. Они доступны внутри производного класса и его потомков.`

**5. Каким образом описывается производный класс?**

`Производный класс описывается путем создания нового класса, который наследует свойства и методы от базового класса. Синтаксис: class Derived : public Base { ... }.`

**6. Наследуются ли конструкторы?**

`Конструкторы наследуются, но они не вызываются автоматически. В производном классе можно явно вызвать конструктор базового класса.`

**7. Наследуются ли деструкторы?**

`Деструкторы также наследуются, но также не вызываются автоматически. Важно убедиться, что деструктор базового класса объявлен как виртуальный.`

**8. В каком порядке конструируются объекты производных классов?**

`Объекты производных классов конструируются в следующем порядке:`

`1. Вызывается конструктор базового класса.`

`2. Выполняются инициализации производного класса.`

`3. Вызывается конструктор производного класса.`

**9. В каком порядке уничтожаются объекты производных классов?**

`1. Вызывается деструктор производного класса.`

`2. Выполняются действия деструктора базового класса.`

**10. Что представляют собой виртуальные функции и механизм позднего связывания?**

`Виртуальные функции позволяют проводить динамическое связывание. Они определяются в базовом классе и могут быть переопределены в производных классах. Механизм позднего связывания обеспечивает вызов правильной функции во время выполнения.`

**11. Могут ли быть виртуальными конструкторы? Деструкторы?**

`Конструкторы не могут быть виртуальными, но деструкторы могут. Виртуальные деструкторы обеспечивают корректное удаление объектов при использовании указателей на базовый класс.`

**12. Наследуется ли спецификатор virtual?**

`Спецификатор virtual не наследуется, но его использование в производном классе позволяет переопределить функцию как виртуальную.`

**13. Какое отношение устанавливает между классами открытое наследование?**

`Открытое наследование устанавливает отношение “является” между базовым и производным классами.`

**14. Какое отношение устанавливает между классами закрытое наследование?**

`Закрытое наследование устанавливает отношение “реализует” между базовым и производным классами.`

**15. В чем заключается принцип подстановки?**

`Принцип подстановки заключается в том, что объект производного класса может использоваться везде, где используется объект базового класса.`

**16. Имеется иерархия классов:**
```cpp
class Student
{
	int age;
public:
	string name;
	...
};
class Employee : public Student
{
protected:
	string post;
	...
};
class Teacher : public Employee
{
	protected: int stage;
	...
};

Teacher x;
```
**Какие компонентные данные будет иметь объект х?**

`Объект x принадлежит классу Teacher, который наследует свойства от класса Employee, а тот, в свою очередь, наследует свойства от класса Student.`

`Поэтому объект x будет иметь следующие компонентные данные:`

`public     name (наследовано от класса Student).`

`protected  post (наследовано от класса Employee).`

`protected  stage (собственное свойство класса Teacher).`

**17. Для классов Student, Employee и Teacher написать конструкторы без параметров.**

```cpp
class Student
{
public:
    Student()
	{
		age = 0;
		name = " ";
	}
};
class Employee : public Student
{
public:
    Employee() : Student()
	{
		post = " ";
	}
};
class Teacher : public Employee
{
public:
    Teacher() : Employee()
	{
		stage = 0;
	}
};
```

**18. Для классов Student, Employee и Teacher написать конструкторы с параметрами.**

```cpp
class Student
{
public:
    Student(int a, string n)
	{
		age = a;
		name = n;
	}
};
class Employee : public Student
{
public:
    Employee(string n, string p) : Student(a, n)
	{
		post = p;
	}
};
class Teacher : public Employee
{
public:
    Teacher(string n, string p, int s) : Employee(n, p)
	{
		stage = s;
	}
};
```

**19. Для классов Student, Employee и Teacher написать конструкторы копирования.**

```cpp
class Student
{
public:
    Student(const Student& S)
	{
		age = S.age;
		name = S.name;
	}
};
class Employee : public Student
{
public:
    Employee(const Employee& E)
	{
		name = E.name;
		post = E.post;
	}
};
class Teacher : public Employee
{
public:
    Teacher(const Teacher& T)
	{
		name = T.name;
		post = T.post;
		stage = T.stage;
	}
};
```

**20. Для классов Student, Employee и Teacher определить операцию присваивания.**

```cpp
Student operator=(const Student& S)
{
	if (&S==this) return *this;
	age = S.age;
	name = S.name;
	return *this;
}
Employee operator=(const Employee& E)
{
	if (&S==this) return *this;
	name = E.name;
	post = E.post;
	return *this;
}
Teacher operator=(const Teacher& T)
{
	if (&S==this) return *this;
	name = T.name;
	post = T.post;
	stage = T.stage;
	return *this;
}
```
