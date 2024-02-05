//задача 7: Заполнить двумернный массив. Все элементы выше главно диагонали равны 0, но все элементы на гл. диагонали и ниже заполняются одинаковыми цифрами.
#include <iostream>

using namespace std;

int main()
{
    const int n = 9;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // весь массив это 0
        {
            a[i][j] = 0;
        }
    }
    
    
    int m = 1, t;
    for (int i = n; i > -1; i--)
    {
        t = m;
        for (int j = n; j >= i; j--)  // все элементы  главной диагонали и ниже
        {
            a[j][i] = t;
            t--;
        }
        m++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) //вывод массива
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}