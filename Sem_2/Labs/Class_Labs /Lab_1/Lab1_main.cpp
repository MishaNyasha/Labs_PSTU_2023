#include <iostream>
#include "fraction.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    Division div;
    int first, second;
    cout << "������� ���������: ";
    cin >> first;
    cout << "������� �����������: ";
    cin >> second;
    div.Set(first, second);
    div.Show();
    cout << "��������� �������: " << div.ipart(first, second) << endl;
    return 0;
}
/*
    Test 1
������� ���������: 92
������� �����������: 3
92 / 3
30.6667

    Test 2
������� ���������: 10
������� �����������: 0
10 / 0
����������� ����� ����, ������� ��� �����: 69

    Test 3
������� ���������: 999
������� �����������: 2
999 / 2
499.5
*/