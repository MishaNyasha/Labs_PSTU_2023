﻿#include <iostream>
using namespace std;
int main()
{
	int n, fact = 1;
	int* f = &fact;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		*f *= i;
	}
	cout << " factorial " << n << " raven " << fact << endl;
}