// Задача 3: Найти максимальный элемент, его индексы, а также количество максимальных элементов

#include <iostream>

using namespace std;

int main()
{
    const int n = 7, m =8;
    int a [m][n], s, max;
    int imax = 0;
    int jmax = 0;
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            cout << a[i][j] << "  "; 
        }
        cout << endl;
    }
    for (int i =0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[imax][jmax]<a[i][j])
            {
                imax = i;
                jmax = j;
                max = a[imax][jmax];
                s=0;
            }
            else
            {
                if(a[i][j]==a[imax][jmax])
                {
                s++;
                }
            }
        }
    }
    cout << "max element " << a[imax][jmax] << endl;
    cout << "index pervogo elementa " << imax << "  " << jmax << endl << "kolichestvo max: " << s;
    return 0;
}


