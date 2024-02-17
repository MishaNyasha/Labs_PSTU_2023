#include <iostream>
#include <cmath>
using namespace std;
// 19 вариант: 
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
/*

	Test 1
4
2
693.333

	Test 2
6
3
126814

	Test 3
4
8
177493

*/