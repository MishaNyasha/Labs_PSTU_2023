#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a, b, c, D, x1, x2;
	setlocale(LC_ALL, "Russian");
	cout << "Введите три циферки" << endl;
	cin >> a >> b >> c;
	D = b * b - 4 * a * c;
	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << "x1=" << x1 << "x2=" << x2;
	}
	else if (D == 0)
	{
		x1 = (-b) / (2 * a);
		cout << "x1=x2=" << x1;
	}
	else
	{
		cout << "корней нету";
	}
}
