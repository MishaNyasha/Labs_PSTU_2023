#include <iostream>
using namespace std;
class Division
{
    int first;
    int second;
public:
    void Set(int A, int B)
    {
        first = A;
        second = B;
    }
    void Show()
    {
        cout << first << " / " << second << endl;
    }
    float ipart(int first, int second) 
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
};
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
    cout << div.ipart(first, second);
    return 0;
}
/*
    Test 1
Введите числитель: 92
Введите знаменатель: 3
92 / 3
30.6667

    Test 2
Введите числитель: 10
Введите знаменатель: 0
10 / 0
Знаменатель равен нулю, поэтому вот держи: 69

    Test 3
Введите числитель: 999 
Введите знаменатель: 2
999 / 2
499.5
*/