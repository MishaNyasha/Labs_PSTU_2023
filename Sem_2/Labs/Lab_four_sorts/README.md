# 1) Задание
## Реализовать четыре сортировки
- Блочную
- Слиянием
- Быструю
- Подсчётом
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
void bucketsort(int arr[], const int SIZE)
{
    const int bucket_num = 10;
    const int bucket_size = 10;
    int buckets[bucket_num][bucket_size];
    int bucketsizes[bucket_num] = { 0 };
    for (int i = 0; i < SIZE; i++)
    {
        int bucketindex = arr[i] / bucket_size;
        buckets[bucketindex][bucketsizes[bucketindex]] = arr[i];
        bucketsizes[bucketindex]++;
    }
    for (int i = 0; i < bucket_num; i++)
    {
        for (int j = 0; j < bucketsizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = tmp;
        }
    }
    int idx = 0;
    for (int i = 0; i < bucket_num; i++)
    {
        for (int j = 0; j < bucketsizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
}
void countsort(int arr[], const int SIZE)
{
    int *output= new int[SIZE];
    int* count;
    int max = arr[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > max) 
        {
            max = arr[i]; 
        }
    }
    count = new int[max + 1];
    for (int i = 0; i <= max; ++i) 
    { 
        count[i] = 0; 
    }
    for (int i = 0; i < SIZE; i++) 
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = SIZE - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < SIZE; i++) 
    {
        arr[i] = output[i];
    }
    delete[] count;
}
void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
    delete[] left;
    delete[] right;
}
void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
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
    cout << "1 - сортировка ведрами\n"
            "2 - сортировка подсчетом\n"
            "3 - сортировка слиянием\n"
            "4 - быстрая сортировка\n"
            "Введите цифру соответствующую выбранному методу сортировки: ";
    int n;
    cin >> n;
    if (n > 4 || n < 1)
    {
        cout << "Ура вы ошиблись!!!" <<endl;
        menu();
        delete[] arr;
        return 0;
    }
    switch(n)
    {
        case 1:
            bucketsort(arr, size);
            cout << "Ура это сортировка вёдрами!!!\nМассив: ";
            break;
        case 2:
            countsort(arr, size);
            cout << "Ура это сортировка подсчётом!!!\nМассив: ";
            break;
        case 3:
            mergesort(arr, 0, size - 1);
            cout << "Ура это сортировка слиянием!!!\nМассив: ";
            break;
        case 4:
            quicksort(arr, 0, size - 1);
            cout << "Ура это быстрая сортировка!!!\nМассив: ";
            break;
    }
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
## Блочная сортировка
 <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_bucketsort.png">
     
## Сортировка подсчетом
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_countsort.png">
    
## Сортировка слиянием
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_merge.png">
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_mergesort.png">
    
## Быстрая сортировка
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_partition.png">
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_quicksort.png">
    
## Меню
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_menu.png">
    
## Функции, создающая и показывающая массив
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_show_array.png">
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_creat_arr.png">
    
## Прикольная main - функция
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_four_sorts/diagrams/four_sorts_main.png">
          
      
# 4) Тесты
```cpp
/*
    1 Test
    
Введите размер массива, который надо отсортировать: 15
Исходный массив: 83 86 77 15 93 35 86 92 49 21 62 27 90 59 63 
1 - сортировка ведрами
2 - сортировка подсчетом
3 - сортировка слиянием
4 - быстрая сортировка
Введите цифру соответствующую выбранному методу сортировки: 1
Ура это сортировка вёдрами!!!
Массив: 15 21 27 35 49 59 62 63 77 83 86 86 90 92 93 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 2


    2 Test
    
Введите размер массива, который надо отсортировать: 15
Исходный массив: 83 86 77 15 93 35 86 92 49 21 62 27 90 59 63 
1 - сортировка ведрами
2 - сортировка подсчетом
3 - сортировка слиянием
4 - быстрая сортировка
Введите цифру соответствующую выбранному методу сортировки: 2
Ура это сортировка подсчётом!!!
Массив: 15 21 27 35 49 59 62 63 77 83 86 86 90 92 93 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 1
Введите размер массива, который надо отсортировать: 30
Исходный массив: 26 40 26 72 36 11 68 67 29 82 30 62 23 67 35 29 2 22 58 69 67 93 56 11 42 29 73 21 19 84 
1 - сортировка ведрами
2 - сортировка подсчетом
3 - сортировка слиянием
4 - быстрая сортировка
Введите цифру соответствующую выбранному методу сортировки: 3
Ура это сортировка слиянием!!!
Массив: 2 11 11 19 21 22 23 26 26 29 29 29 30 35 36 40 42 56 58 62 67 67 67 68 69 72 73 82 84 93 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 1
Введите размер массива, который надо отсортировать: 10
Исходный массив: 37 98 24 15 70 13 26 91 80 56 
1 - сортировка ведрами
2 - сортировка подсчетом
3 - сортировка слиянием
4 - быстрая сортировка
Введите цифру соответствующую выбранному методу сортировки: 4
Ура это быстрая сортировка!!!
Массив: 13 15 24 26 37 56 70 80 91 98 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 2

    
    3 Test
    
Введите размер массива, который надо отсортировать: 10
Исходный массив: 83 86 77 15 93 35 86 92 49 21 
1 - сортировка ведрами
2 - сортировка подсчетом
3 - сортировка слиянием
4 - быстрая сортировка
Введите цифру соответствующую выбранному методу сортировки: 5
Ура вы ошиблись!!!
Введите размер массива, который надо отсортировать: 15
Исходный массив: 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 
1 - сортировка ведрами
2 - сортировка подсчетом
3 - сортировка слиянием
4 - быстрая сортировка
Введите цифру соответствующую выбранному методу сортировки: 2
Ура это сортировка подсчётом!!!
Массив: 11 26 26 27 29 36 40 59 62 63 67 68 72 82 90 
Повторить еще раз?
1 - да
2 - нет
Ваш выбор: 2
*/
```
