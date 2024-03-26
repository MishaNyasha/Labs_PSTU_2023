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
/*
Тесты не актуальны ._.
    Test 1
Ââåäèòå ÷èñëèòåëü: 92
Ââåäèòå çíàìåíàòåëü: 3
92 / 3
30.6667

    Test 2
Ââåäèòå ÷èñëèòåëü: 10
Ââåäèòå çíàìåíàòåëü: 0
10 / 0
Çíàìåíàòåëü ðàâåí íóëþ, ïîýòîìó âîò äåðæè: 69

    Test 3
Ââåäèòå ÷èñëèòåëü: 999
Ââåäèòå çíàìåíàòåëü: 2
999 / 2
499.5
*/
