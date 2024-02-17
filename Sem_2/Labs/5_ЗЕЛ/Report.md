# 1) Задание
Найти минимальный из неповторяющихся элементов
двумерного массива.
# 2) Код программы
```cpp
﻿#include <iostream>
using namespace std;
void showMatrix(int m[5][5], int nRow, int nCol)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "ru");
    int matrix[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (rand() % 102);
        }
    }
    showMatrix(matrix, 5, 5);
    int min = 9999;
    bool flag = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                flag = 0;
            }
            else if (matrix[i][j] == min)
            {
                matrix[i][j] = 9999;
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << min << " - Минимальное неповторяющиеся";
    }
    return 0;
}
```
# 3) Блок-схема
<image src ="5_ЗЕЛ_main.png">

<image src ="5_ЗЕЛ_showMatrix.png">

# 4) Тесты
```cpp
/*
    1 Test

41  67  34  0  69
24  78  58  62  64
5  45  81  27  61
91  95  42  27  36
91  4  2  53  92

0 - Минимальное неповторяющиеся

    2 Test
83  86  77  15  93
35  86  92  49  21
62  27  90  59  63
26  40  26  72  36
11  68  67  29  82 

11 - Минимальное неповторяющиеся

    3 Test
41  5  10  82  95
16  54  84  34  86
95  95  25  99  67
83  37  8  33  30
57  18  26  51  88

5 - Минимальное неповторяющиеся
*/
```
