# 1) Задание
Написать программу, в которой создаются динамические массивы и выполнить их обработку в соответствии со своим вариантом.
20 Вариант) Сформировать массив строк. Удалить из него строку, начинающуюся и заканчивающуюся на одну и ту же букву.
# 2) Код программы
```cpp
#include <iostream>
#include <cstring>
using namespace std;
void delete_strs (char** strs, int size)
{
    for(int i = 0; i < size; i++)
    {
       char* CSTR = strs[i];
       int lenght = strlen(CSTR);
       if(CSTR[0] == CSTR[lenght - 1])
       {
           delete [] CSTR;
           strs[i] = 0; 
       }
    }
}
int main()
{
    setlocale (LC_ALL, "ru");
    int size;
    cout << "введите размер массива: ";
    cin >> size;
    char** strs = new char*[size];
    
    for (int i = 0; i < size; i++)
    {
        int lenght = rand() % 10  + 1;
        strs[i] = new char[lenght + 1];
        for (int j = 0; j < lenght; j++)
        {
            strs[i][j] = 'a' + rand() % ('a' - 'd');
        }
        strs[i][lenght] = '\0';
    }
    
    cout << "изначальный массив:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << strs[i] << "  ";
    }
    
    delete_strs (strs, size);
    cout << "\nмассив без строк, где первая и последняя буква совпадают:" << endl;
    for (int i = 0; i < size; i++)
    {
        if(strs[i] != 0)
        {
            cout << strs[i] << "  ";
        }
    }
    
    for (int i =0; i < size; i++)
    {
        delete [] strs[i];
    }
    delete [] strs;
    return 0;
}
```
# 3) Блок-схема
 <image src ="10_ЗЕЛ_main.png">
    <image src ="10_ЗЕЛ_delete_strs.png">
      
# 4) Тесты
```cpp
/*
    Test 1
введите размер массива: 10
изначальный массив:
babc  baabcb  b  baab  ccaaccc  bbca  aca  bbba  accb  ccacbbcca  
массив без строк, где первая и последняя буква совпадают:
babc  bbca  bbba  accb  ccacbbcca 

    Test 2
введите размер массива: 15
изначальный массив:
babc  baabcb  b  baab  ccaaccc  bbca  aca  bbba  accb  ccacbbcca  cbb  acaccb  bcaaaacacc  cbaa  caaccbaac  
массив без строк, где первая и последняя буква совпадают:
babc  bbca  bbba  accb  ccacbbcca  cbb  acaccb  bcaaaacacc  cbaa  

    Test 3
введите размер массива: 20
изначальный массив:
babc  baabcb  b  baab  ccaaccc  bbca  aca  bbba  accb  ccacbbcca  cbb  acaccb  bcaaaacacc  cbaa  caaccbaac  bbbaacabc  caccaabcb  c  ac  cbaab  
массив без строк, где первая и последняя буква совпадают:
babc  bbca  bbba  accb  ccacbbcca  cbb  acaccb  bcaaaacacc  cbaa  bbbaacabc  caccaabcb  ac  cbaab  
*/
```
