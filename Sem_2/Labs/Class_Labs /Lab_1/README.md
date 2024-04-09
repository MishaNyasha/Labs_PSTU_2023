# Лабораторная работа  No1 
# Классы и объекты. Инкапсуляция. 

## (1) Задание
1.  Реализовать определение нового класса. Для демонстрации работы с объектами написать  главную  функцию.  Продемонстрировать  разные  способы  создания объектов и массивов объектов. 
2.  Структура-пара – структура с двумя полями, которые обычно имеют имена first и second. Требуется реализовать тип данных с помощью такой структуры. Во всех заданиях должны присутствовать : 
    1. метод  инициализации  Init  (метод  должен  контролировать  значения аргументов на корректность); 
    2. ввод с клавиатуры Read;
    3. вывод на экран Show.
3. Реализовать  внешнюю  функцию  make_тип(),  где  тип  –  тип  реализуемой структуры.  Функция  должна  получать  значения  для  полей  структуры  как параметры  функции  и  возвращать  структуру  как  результат.  При  передаче ошибочных параметров следует выводить сообщение и заканчивать работу.
## (2) Реализация 
- приколюшная main функция:
```cpp
#include <iostream>
#include "fraction.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    Division div;
    int first, second;
    cout << "Введите числитель: ";
    cin >> first;
    cout << "Введите знаменатель: ";
    cin >> second;
    div.Set(first, second);
    div.Show();
    cout << "Результат деления: " << div.ipart(first, second) << endl;
    return 0;
}
```
- fraction.cpp
```cpp
#include <iostream> 
#include "fraction.h"
using namespace std;
void Division::Set(int A, int B)
{
    first = A;
    second = B;
}
void Division::Show()
{
    cout << first << " / " << second << endl;
}
float Division::ipart(int first, int second)
{
    if (second == 0)
    {
        cout << "Знаменатель равен нулю, поэтому вот держи: ";
        return 69;
    }
    float Razdelenii;
    Razdelenii = (float)first / second;
    return Razdelenii;
}
```
- fraction.h
```cpp
#ifndef FRACTION_H
#define FRACTION_H

class Division
{
private:
    int first, second;
public:
    void Set(int, int);
    void Show();
    float ipart(int first, int second);
};

#endif
```
## (3) UML - диаграмма
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_1/UML_CL1.png">
  
## (4) Тесты
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_1/TEST_1CL.png">

## (5) Ответы на вопросы
Q _ Q
