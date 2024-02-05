// Задача 2: Найти сумму элементов строк двумерного массива
#include <iostream>

using namespace std;

int main()
{
    const int n = 7, m =8;
    int a [m][n];
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 101 -50;
            cout << a[i][j] << "  "; 
        }
        cout << endl;
    }
    cout << "\nSumma vsex elementov kajdoi stroki:\n";
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        cout << sum << "  ";
    }

    return 0;
}
