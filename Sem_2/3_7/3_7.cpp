#include <iostream>
using namespace std;
int main()
{
    const int n = 100;
    int a[n];
    int max, min;
    cout << endl;
    max = 0;
    min = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101 - 50;
        if (a[i] > max) 
        { 
            max = a[i]; 
        }
        if (a[i] < min)
        {
            min = a[i];
        }
        cout << a[i] << "  ";
    }
    cout << endl << "max = " << max << endl << "min = " << min;
    return 0;
}