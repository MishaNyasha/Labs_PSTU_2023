#include <iostream>
#include "Setn.h"
#include "Money.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU");

    Setn<int> a(5, 0);
    cout << "Введите элементы множества a: \n";
    cin >> a;
    cout << "a: " << a << endl;

    Setn<int> b(10, 0);
    cout << "b: " << b << endl;
    b = a;
    cout << "b: " << b << endl;

    cout << "Элемент 2: " << a[2] << endl;
    cout << "Размер множества b: " << b() << endl;

    Setn<int> s(5, 0);
    cout << "Введите элементы множества b: \n";
    cin >> b;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    s = a * b;
    cout << "s: " << s << endl;

    Money mon;
    cout << "Введите деньги: \n";
    cin >> mon;
    cout << mon << endl;

    Money mon1;
    cout << "Введите другие деньги: \n";
    cin >> mon1;
    cout << mon1 << endl;

    Money mon2;
    mon2 = mon * mon1;
    cout << "Результат умножения денег: " << mon2 << endl;

    Money t;
    cout << "Введите деньги: ";
    cin >> t;
    cout << t << endl;

    Setn<Money> Ar(5, t);
    cout << "Введите элементы множества Ar: ";
    cin >> Ar;
    cout << "Ar: " << Ar << endl;

    Setn<Money> B(10, t);
    cout << "B: " << B << endl;
    B = Ar;
    cout << "B: " << B << endl;

    cout << "Элемент 2 из Ar: " << Ar[2] << endl;
    cout << "Размер множества A: " << Ar() << endl;

    return 0;
}
/*
Введите элементы множества a :
Element 0 :
1
Element 1 :
2
Element 2 :
3
Element 3 :
4
Element 4 :
5
a : 1 2 3 4 5
b : 0 0 0 0 0 0 0 0 0 0
b : 1 2 3 4 5
Элемент 2 : 3
Размер множества b : 5
Введите элементы множества b :
Element 0 :
9
Element 1 :
8
Element 2 :
7
Element 3 :
6
Element 4 :
5
a : 1 2 3 4 5
b : 9 8 7 6 5
s : 5
Введите деньги :
rub: 14
kop : 50
14, 50
Введите другие деньги :
rub: 3
kop : 2
3, 02
Результат умножения денег : 42, 100
Введите деньги : rub: 15
kop : 25
15, 25
Введите элементы множества Ar : Element 0 :
rub : 15
kop : 25
Element 1 :
rub : 25
kop : 15
Element 2 :
rub : 35
kop : 35
Element 3 :
rub : 30
kop : 90
Element 4 :
rub : 12
kop : 12
Ar : 15, 25 25, 15 35, 35 30, 90 12, 12
B : 15, 25 15, 25 15, 25 15, 25 15, 25 15, 25 15, 25 15, 25 15, 25 15, 25
B : 15, 25 25, 15 35, 35 30, 90 12, 12
Элемент 2 из Ar : 35, 35
Размер множества A : 5
*/
