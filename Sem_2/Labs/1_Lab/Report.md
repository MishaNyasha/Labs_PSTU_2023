# 1) Задание
Заполнить двумерный массив: если сумма номера строки и номера столбца - нечётное число, то такой элемент = 0.
Все остальные элементы заполняются от 1 до 9 по порядку.
# 2) Код программы

```cpp
#include <iostream>
using namespace std;
int main()
{
    int tmp = 1; 
    const int n = 10;
    int a[n][n];
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i+j)%2 == 1)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = tmp;
                tmp++;
                if (tmp == 10)
                {
                    tmp = 1;
                }
                
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```
# 3) Блок-схема
<image src ="1_Lab.png">

# 4) Тесты

```cpp

```
