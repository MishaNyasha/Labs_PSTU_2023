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
