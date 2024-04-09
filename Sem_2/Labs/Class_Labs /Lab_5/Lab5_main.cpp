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
