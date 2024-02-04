#include <iostream>
using namespace std;
int main()
{
    const int n = 100;
    int a[n], max = a[0], maxes = 1;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << "  ";
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        else if (a[i] == max)
        {
            maxes++;
        }
    }
    cout << "max = " << max << endl<< "maxes = " << maxes;
    return 0;
}