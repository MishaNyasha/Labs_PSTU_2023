#include <iostream>
using namespace std;
int foo(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return foo(n - 1) + foo(n - 2);
}
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cout << foo(i) << " ";
	}
	return 0;
}
/*
    Test 1
8
0 1 1 2 3 5 8 13 

    Test 2
22
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 

    Test 3
10
0 1 1 2 3 5 8 13 21 34 
*/
