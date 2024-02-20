# 1) Задание
Посчитать сумму ряда при помощи рекурсии (19 вариант)
# 2) Код программы
```cpp
#include <iostream>
#include <cmath>
using namespace std;
double factorial (int a)
{
    int k = 1;
	for (int i = 1; i <= a; i++)
	{
		k *= i;
	}
	return k;
}

double foo(int a, int n, int x)
{
    if (a == n+1)
	{
		return 0;
	}
    double el = (pow((2 * x),n)/factorial(a)) + foo(a+1, n, x);
    return el;
}

int main()
{
    int a = 0;
	int n, x;
	cin >> n >> x;
	cout << foo(a, n, x) << endl;
	return 0;
}
```
# 3) Блок-схема
<image src ="sum_of_series_terms_main.png">
  <image src ="sum_of_series_terms_factorial.png">
    <image src ="sum_of_series_terms_foo.png">
# 4) Тесты
```cpp
/*

	Test 1
4/n
2/n
693.333

	Test 2
6/n
3/n
126814

	Test 3
4/n
8/n
177493

*/
```
