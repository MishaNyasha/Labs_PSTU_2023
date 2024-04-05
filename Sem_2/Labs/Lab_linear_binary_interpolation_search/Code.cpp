#include <iostream>
#include <cstdlib>
using namespace std;
void BubbleSort(int* array, int N)
{
    int temp;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N - 1; j++)  
	{
            if(array[j] > array[j + 1]) 
	    {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "отсортированный массив: ";
    for(int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }
    return;
}
int* create_arr(const int N, int arr[])
{
    cout << "Созданный массив: ";
    for(int i = 0; i < N; i++)
    {
        arr[i] = 1 + rand() % 10;
        cout << arr[i] << " ";
    }
    cout << "\n";
    return arr;
}
int create_key()
{
    int key;
    cout << "Введите ключ: ";
    cin >> key;
    return key; 
}
void linear_search(const int N, int arr[], int key)
{
    int ans[N];
    int h = 0;
    for (int i = 0; i < N; i++) 
    {
        if (arr[i] == key) 
        { 
            ans[h++] = i;
        }
    }
    if (h != 0) 
    {
        for (int i = 0; i < h; i++) 
        {
            cout << "Ключ " << key << " находится в ячейке " << ans[i] << endl;
        }
    }
    else 
    {
        cout << "Ключа " << key << " в массиве нету";
    }
}
void binary_search(int arr[], int N, int key) 
{
	int low = 0;
	int high = N - 1;
	while (low <= high) 
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
		{
            		cout << "Ключ найден на позиции: " << mid + 1 << endl;			
            		break;
		}
		else if (arr[mid] < key) 
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}
}
void interpolation_search(const int N, int arr[], int key) 
{
	if (arr[0] == key) 
	{ 
	    cout << "Ключ найден на позиции: 1" << endl; 
	    return;
	}
	int low = 0;
	int high = N - 1;
	int mid;
	int key_place = - 1;
	while (arr[low] < key && arr[high] >= key)
	{
		mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
		if (arr[mid] == key) 
		{ 
		    key_place = mid + 1; break; 
		}
		else if (arr[mid] < key) 
		{ 
		    low = mid + 1; 
		}
		else if (arr[mid] > key) 
		{ 
		    high = mid - 1; 
		}
	}
	if (key_place != -1) 
	{
    	cout << "Ключ " << key << " находится в ячейке " << key_place << endl;
	}
	else 
	{
		cout << "Ключа " << key << " нету в массиве";
	}
}
int main() 
{
    system("chcp 1251 > Null");
    int n;
    bool m;
    cout << "Введите размер массива: ";
    cin >> n;
    const int N = n;
    int arr[N];
    create_arr(N, arr);
     int key = create_key();
    cout << "Выберите способ поиска:\n"
            "0 - Линейный поиск\n"
            "1 - Бинарный или интерполяционный\n"
            "Ваш выбор: ";
    cin >> m;
    if(m)
    {   
        bool d;
        BubbleSort(arr, N);
        cout << "Выберите способ поиска:\n"
                "0 - Бинарный поиск\n"
                "1 - Интерполяционный\n"
                "Ваш выбор: ";
        cin >> d;
        if(d)
        {
            cout << "Выбран интерполяционный поиск:\n";
            interpolation_search(N, arr, key);
        }
        else
        {
            cout << "Выбран бинарный поиск:\n";
            binary_search(arr, N, key);
        }
    }
    else
    {
        cout << "Выбран линейный поиск:\n";
        linear_search(N, arr, key);
    }
    return 0;
}
/*
    Test 1
Введите размер массива: 15
Созданный массив: 4 7 8 6 4 6 7 3 10 2 3 8 1 10 4 
Введите ключ: 4
Выберите способ поиска:
0 - Линейный поиск
1 - Бинарный или интерполяционный
Ваш выбор: 0
Выбран линейный поиск:
Ключ 4 находится в ячейке 0
Ключ 4 находится в ячейке 4
Ключ 4 находится в ячейке 14

    Test 2
Введите размер массива: 15
Созданный массив: 4 7 8 6 4 6 7 3 10 2 3 8 1 10 4 
Введите ключ: 7
Выберите способ поиска:
0 - Линейный поиск
1 - Бинарный или интерполяционный
Ваш выбор: 1
отсортированный массив: 1 2 3 3 4 4 4 6 6 7 7 8 8 10 10 Выберите способ поиска:
0 - Бинарный поиск
1 - Интерполяционный
Ваш выбор: 0
Выбран бинарный поиск:
Ключ найден на позиции: 10

    Test 3
Введите размер массива: 14
Созданный массив: 4 7 8 6 4 6 7 3 10 2 3 8 1 10 
Введите ключ: 10
Выберите способ поиска:
0 - Линейный поиск
1 - Бинарный или интерполяционный
Ваш выбор: 1
отсортированный массив: 1 2 3 3 4 4 6 6 7 7 8 8 10 10 Выберите способ поиска:
0 - Бинарный поиск
1 - интерполяционный
Ваш выбор: 1
Выбран интерполяционный поиск:
Ключ 10 находится в ячейке 14
*/
