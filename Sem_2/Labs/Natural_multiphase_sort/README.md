# 1) Задание
## Реализовать сортировку многофазную и естественную

# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int mas[255];
int storage;
void merge(int c[], int d[], int l, int m, int r);
void multiphasesort(int arr[], const int n)
{
    bool swapped = true;
    int gap = n;
    while (gap > 1 || swapped)
    {
        gap = (gap * 10) / 13; 
        if (gap < 1)
            gap = 1;

        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
void mergepass(int x[], int y[], int s, int n)
{
    int i = 0;
    while (i <= storage - 2 * s)
    {
        int r = ((i + 2 * s) < storage) ? mas[i + 2 * s] : n;

        merge(x, y, mas[i], mas[i + s] - 1, r - 1);
        i = i + 2 * s;
    }
    if (i + s < storage)
        merge(x, y, mas[i], mas[i + s] - 1, n - 1);
    else  if (i < storage)
    {
        for (int j = mas[i]; j <= n - 1; j++)
            y[j] = x[j];
    }
}
void mergesort(int a[], int n)
{
    int* b = new int[n];
    int s = 1;
    while (s < storage)
    {
        mergepass(a, b, s, n);  
        s += s; 
        mergepass(b, a, s, n);
        s += s;
    }
}
void merge(int c[], int d[], int l, int m, int r)
{   
    int i = l, j = m + 1, k = r;

    while ((i <= m) && (j <= r))
    {
        if (c[i] <= c[j])
            d[l++] = c[i++];   
        else
            d[l++] = c[j++];
    }
    if (i > m)
        for (int q = j; q <= r; q++)   
            d[l++] = c[q];
    else
        for (int p = i; p <= m; p++) 
            d[l++] = c[p];
}
void getbpoint(int a[], int b[], int n, int& m)
{
    int j = 0;
    b[j++] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            b[j++] = i + 1;
    }
    m = j;
}

void show_arr(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int* create_arr(int arr[], const int n)
{
    for (int i = 0; i < n; i++) 
    { 
        arr[i] = 1 + rand() % 100; 
    }
    cout << "Созданный массив: ";
    show_arr(arr, n);
    return arr;
}
int main()
{
    system("chcp 1251 > Null");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    const int n = size;
    int arr[n];
    create_arr(arr, n);
    bool choise;
    cout << "выберите способ сортировки:\n"
            "0 - естественная\n"
            "1 - многофазная\n"
            "ваш выбор: ";
    cin >> choise;
    if(choise)
    {
        multiphasesort(arr, n);
    }
    else
    {
        getbpoint(arr, mas, n, storage);
        mergesort(arr, n);
    }
    cout << "Отсортированный массив: ";
    show_arr(arr, n);
    return 0;
}
```
# 3) Блок-схема

## Многофазная сортировка
 <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/multiphasesort.png">
   
## Сортировка естественная
 <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/mergesort.png">
  <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/mergepass.png">
   <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/merge.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/getbpoint.png">
    
## Функции, создающая и показывающая массив
 <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/create_arr.png">
  <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/show_arr.png">
    
## Прикольная main - функция
 <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Natural_multiphase_sort/diagrams/main.png">
          
      
# 4) Тесты
```cpp
/*
    Test 1
Введите размер массива: 15
Созданный массив: 84 87 78 16 94 36 87 93 50 22 63 28 91 60 64 
выберите способ сортировки:
0 - естественная
1 - многофазная
ваш выбор: 0
Отсортированный массив: 16 22 28 36 50 60 63 64 78 84 87 87 91 93 94

    Test 2
Введите размер массива: 25
Созданный массив: 84 87 78 16 94 36 87 93 50 22 63 28 91 60 64 27 41 27 73 37 12 69 68 30 83 
выберите способ сортировки:
0 - естественная
1 - многофазная
ваш выбор: 1
Отсортированный массив: 12 16 22 27 27 28 30 36 37 41 50 60 63 64 68 69 73 78 83 84 87 87 91 93 94     
    
    Test 666
Введите размер массива: 200
Созданный массив: 84 87 78 16 94 36 87 93 50 22 63 28 91 60 64 27 41 27 73
37 12 69 68 30 83 31 63 24 68 36 30 3 23 59 70 68 94 57 12 43 30 74 22 20 
85 38 99 25 16 71 14 27 92 81 57 74 63 71 97 82 6 26 85 28 37 6 47 30 14 58
25 96 83 46 15 68 35 65 44 этот тест подделан 51 88 9 77 79 89 85 4 52 55 
100 33 61 77 69 40 13 27 87 95 40 96 71 35 79 68 2 98 3 18 93 53 57 2 81 87 
42 66 90 45 20 41 30 32 18 98 72 82 76 10 28 68 57 98 54 87 66 7 84 20 25 29
72 33 30 4 20 71 69 9 16 41 50 97 24 19 46 47 52 22 56 80 89 65 29 42 51 94
1 35 65 25 15 88 57 44 92 28 66 60 37 33 52 38 29 76 8 75 22 59 96 30 38 36 
94 19 29 44 12 29 30 
выберите способ сортировки:
0 - естественная
1 - многофазная
ваш выбор: 0
Отсортированный массив: 1 2 2 3 3 4 4 6 6 7 8 9 9 10 12 12 12 13 14 14 15 
15 16 16 16 18 18 19 19 20 20 20 20 22 22 22 22 23 24 24 25 25 25 25 26 27
27 27 27 28 28 28 28 29 29 29 29 29 30 30 30 30 30 30 30 30 31 32 33 33 33 
35 35 35 36 36 36 37 37 37 38 38 38 40 40 41 41 41 42 42 43 44 44 44 45 46 
46 47 47 50 50 51 51 52 52 52 53 54 55 56 57 57 57 57 57 58 59 59 60 60 61 
63 63 63 64 65 65 65 66 66 66 68 68 68 68 68 68 69 69 69 70 71 71 71 71 72 
72 73 74 74 75 76 76 77 77 78 79 79 80 81 81 82 82 83 83 84 84 85 85 85 87 
87 87 87 87 88 88 89 89 90 91 92 92 93 93 94 94 94 94 95 96 96 96 97 97 98 
98 98 99 100     
*/
```
