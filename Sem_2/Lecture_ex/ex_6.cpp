// Задача 6: ЗАполнить квадратный двумерный массив. Элементы, которые одновременно выше главной и побочной диагонали равны 0, остальные 1.

#include <iostream>

using namespace std;

int main()
{
    const int n = 9;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 1;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < (n-i-1); j++)
        {
            a[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    

    return 0;
}