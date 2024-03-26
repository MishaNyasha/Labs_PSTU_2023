# 1) Задание
## Реализовать сортировку Шелла

# 2) Код программы
```cpp
#include <iostream>
using namespace std;
void show_array(int arr[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int* creat_arr(const int SIZE)
{
    int* arr = new int[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}
void shellSort(int arr[], int n)
{
    for (int h = n/2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}
int menu()
{
    cout << "Введите размер массива, который надо отсортировать: ";
    int size;
    cin >> size;
    int* arr = creat_arr(size);
    cout << "Исходный массив: ";
    show_array(arr, size);
    shellSort(arr, size);
    cout << "массив: ";
    show_array(arr, size);
    bool choice;
    cout << "Повторить еще раз?\n1 - да\n2 - нет\nВаш выбор: ";
    cin >> choice;
    if (choice)
    {
        menu();
        delete[] arr;
    }
    delete[] arr;
    return 0;
}
int main()
{
    setlocale(LC_ALL, "ru_ru");
    menu();
    return 0;
}
```
# 3) Блок-схема
## Сама сортировка
 <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_shell_sort/diagrams/Shell_sort_shellSort.png">
   
## Меню
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_shell_sort/diagrams/Shell_sort_menu.png">
    
## Функции, создающая и показывающая массив
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_shell_sort/diagrams/Shell_sort_creat_arr.png">
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_shell_sort/diagrams/Shell_sort_show_array.png">
    
## Прикольная main - функция
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_shell_sort/diagrams/Shell_sort_main.png">
          
      
# 4) Тесты
```cpp
/*
    1 Test
    
Введите размер массива, который надо отсортировать: 10
Исходный массив: 83 86 77 15 93 35 86 92 49 21 
массив: 15 21 35 49 77 83 86 86 92 93 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 1
Введите размер массива, который надо отсортировать: 15
Исходный массив: 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 
массив: 11 26 26 27 29 36 40 59 62 63 67 68 72 82 90 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 2


    2 Test
    
Введите размер массива, который надо отсортировать: 11
Исходный массив: 83 86 77 15 93 35 86 92 49 21 62 
массив: 15 21 35 49 62 77 83 86 86 92 93 
Повтороть еще раз?
1 - да
2 - нет
Ваш выбор: 2


    3 Test
    
Введите размер массива, который надо отсортировать: 99
Исходный массив: 83 86 77 15 93 35 86 92 49 21 62 27 90 59
63 26 40 26 72 36 11 68 67 29 82 30 62 23 67 35 29 2 22 58
69 67 93 56 11 42 29 73 21 19 84 37 98 24 15 70 13 26 91 80
56 73 62 70 96 81 5 25 84 27 36 5 46 29 13 57 24 95 82 45 14
67 34 64 43 50 87 8 76 78 88 84 3 51 54 99 32 60 76 68 39 12 26 86 94 
массив: 2 3 5 5 8 11 11 12 13 13 14 15 15 19 21 21 22 23 24 24 25 26 26 26 26 
27 27 29 29 29 29 30 32 34 35 35 36 36 37 39 40 42 43 45 46 49 50 51 54 56 56 
57 58 59 60 62 62 62 63 64 67 67 67 67 68 68 69 70 70 72 73 73 76 76 77 78 80 
81 82 82 83 84 84 84 86 86 86 87 88 90 91 92 93 93 94 95 96 98 99 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 2
*/
```
