#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru_RU");
    const int n = 5;
    bool flag = 1;
    int a[n] = { 1,2,3,4,5 };
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "Массив упорядочен по возрастанию" << endl;
    }
    else
    {
        cout << "Массив НЕ упорядочен по возрастанию" << endl;
    }
    return 0;
}