#include <iostream>
using namespace std;
int main()
{
    const int n = 5;
    bool flag = true;
    int a[n] = { 1, 2, 3, 4, 5 };
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] < a[i - 1]) { flag = false; }
    }
    if (flag)
    {
        cout << "Массив упорядочен" << endl;
    }
    else
    {
        cout << "Массив не упорядочен" << endl;
    }
    return 0;
}