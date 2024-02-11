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