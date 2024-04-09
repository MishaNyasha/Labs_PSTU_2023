#include <iostream> 
#include "PAIR.h"
#include "FRACTION.h" 
using namespace std;
int main()
{
    system("chcp 1251 > Null");
    cout << "Часть задания свазянная с PAIR\n";
    PAIR a(25, 100);
    a.update(250, 1000);
    cout << a << endl;
    cout << "Введите первое и второе число для A\n";
    cin >> a;
    cout << a;
    cout << "Введите первое и второе число для B\n";
    PAIR b(25, 300);
    cin >> b;
    cout << b;
    if (a > b) 
    {
        cout << "A больше B" << endl;
    }
    else 
    {
        cout << "B больше A" << endl;
    }
    cout << "\nЧасть задания свазянная с FRACTION\n";
    FRACTION t(25, 0.5);
    cout << t;
    cin >> t;
    cout << t;
    return 0;
}
