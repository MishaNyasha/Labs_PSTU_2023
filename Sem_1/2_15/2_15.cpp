#include <iostream>
using namespace std;
int main()
{
	int n, s, k;
	bool p = false;
	setlocale(LC_ALL, "Russian");
	cout << "введите число" << endl;
	cin >> n;
	cout << "введите цифру, которую надо проверить на наличие в числе" << endl;
	cin >> s;
	while (n > 0 && !p)
	{
		k = n % 10;
		if (k == s)
		{
			p = true;
			cout << "цифра есть в числе" << endl;
		}
		else
		{
			n /= 10;
		}
	}
	if (!p)
	{
		cout << "цифры нету в числе";
	}
}