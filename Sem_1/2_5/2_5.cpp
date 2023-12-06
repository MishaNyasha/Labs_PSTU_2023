#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int star = 1;
	int space = N - 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < space; j++)
		{
			cout << "  ";
		}
		space--;
		for (int j = 0; j < star; j++)
		{
			cout << " *";
		}
		star += 1;
		cout << endl;
	}

	return 0;
}
