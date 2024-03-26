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