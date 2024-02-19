# 1) Задание
Написать перегруженные функции и основную программу, которая их вызывает.
а) по номеру года выдает его название по старояпонскому календарю;
б) по названию месяца выдает знак Зодиака.
# 2) Код программы
```cpp
#include <iostream>
#include <string>
using namespace std;
void foo(int A)
{
    switch (A)
    {
        case 1: cout << "Крыса";
        break;
        case 2: cout << "Корова";
        break;
        case 3: cout << "Тигр";
        break;
        case 4: cout << "Заец";
        break;
        case 5: cout << "Дракон";
        break;
        case 6: cout << "Змея";
        break;
        case 7: cout << "Лошадь";
        break;
        case 8: cout << "Овца";
        break;
        case 9: cout << "Обезьяна";
        break;
        case 10: cout << "Курица";
        break;
        case 11: cout << "Собака";
        break;
        case 12: cout << "Свинья";
        break;
        default: cout << "error";
    }
}
void foo(string str)
{
    if (str == "январь")
    {
        cout << "1";
    }
    else if (str == "февраль")
    {
         cout << "2";
    }
    else if (str == "Март")
    {
         cout << "3";
    }
    else if (str == "Апрель")
    {
         cout << "4";
    }
    else if (str == "Май")
    {
         cout << "5";
    }
    else if (str == "Июнб")
    {
         cout << "6";
    }
    else if (str == "Июлб")
    {
         cout << "7";
    }
    else if (str == "Август")
    {
         cout << "8";
    }
    else if (str == "Сентябрь")
    {
         cout << "9";
    }
    else if (str == "Октябрь")
    {
         cout << "10";
    }
    else if (str == "Ноябрь")
    {
         cout << "11";
    }
    else if (str == "Декабрь")
    {
         cout << "12";
    }
    else 
    {
        cout << "Нету такого";
    }
}
int main()
{
    int A;
    cout << "Введите номер год по старо-японскому календарю: ";
    cin >> A;
    foo(A);
    string str;
    cout << endl << "Введите название любого месяца: ";
    cin >> str;
    foo(str);
    return 0;
}
```
# 3) Блок-схема
<image src ="7.1_ЗЕЛ_main.png"> 
<image src ="7.1_ЗЕЛ_foo1.png"> <image src ="7.1_ЗЕЛ_foo2.png">
  
# 4) Тесты
```cpp
/*
    Test 1
Введите номер год по старо-японскому календарю: 5
Дракон
Введите название любого месяца: Декабрь
12

    Test 2
Введите номер год по старо-японскоскому календарю: 4
Заец
Введите название любого месяца: Зима
Нету такого
    
    Test 3
Введите номер год по старо-японскому календарю: 8
Овца
Введите название любого месяца: Сентябрь
9
*/
```
