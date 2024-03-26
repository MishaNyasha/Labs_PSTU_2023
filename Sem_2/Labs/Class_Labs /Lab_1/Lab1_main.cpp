#include <iostream>
#include "fraction.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    Division div;
    int first, second;
    cout << "¬ведите числитель: ";
    cin >> first;
    cout << "¬ведите знаменатель: ";
    cin >> second;
    div.Set(first, second);
    div.Show();
    cout << "–езультат делени€: " << div.ipart(first, second) << endl;
    return 0;
}
/*
    Test 1
¬ведите числитель: 92
¬ведите знаменатель: 3
92 / 3
30.6667

    Test 2
¬ведите числитель: 10
¬ведите знаменатель: 0
10 / 0
«наменатель равен нулю, поэтому вот держи: 69

    Test 3
¬ведите числитель: 999
¬ведите знаменатель: 2
999 / 2
499.5
*/