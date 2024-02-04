#include <iostream>
using namespace std;
int main()
{
	const int n = 10;
	int max, a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101 - 50;
		if (a[i] > a[i - 1])
		{
			max = a[i];
		}
		cout << a[i] << "  ";
	}
	cout << endl << max;
	return 0;
}