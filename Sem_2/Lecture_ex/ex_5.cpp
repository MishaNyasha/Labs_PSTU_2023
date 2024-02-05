// Задача 5: Запольнить двумерный квадратрный массив так чтобы получился ромб из единичек

#include <iostream>

using namespace std;

int main()
{
    
    const int n = 9;
    int mid = (n/2);
    int x = mid, y = mid;
    int a[n][n] = {0};
    a[0][mid] = 1;
    for (int i = 1; i < n; i++ )
    {
        if (i <= mid)
        {
            x--;
            y++;
        }
        else
        {
            x++;
            y--;
        }
        a[i][y] = 1;
        a[i][x] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


