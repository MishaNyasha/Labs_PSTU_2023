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
	cout << "������ ����� ������� �� ����:\n";
	Pair a;
	cin >> a;
	cout << "\n�������� ��� �:";
	object* p = &a;
	p->Show();
	
	cout << "\n������� �������� ��� B:";
	Pair b;
	cin >> b;

	if (a > b)
	{
		cout << "\nA ������ B" << endl;
	}
	else
	{
		cout << "\nB ������ A" << endl;
	}
	cout << "������ ����� ������� �� ����:\n";
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