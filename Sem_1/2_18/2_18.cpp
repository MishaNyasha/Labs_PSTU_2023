#include <iostream>
using namespace std;
int main()
{
    int n;
    int m = 0;
    cin >> n;
    while (n)
    {
        m =n % 10;
        n /= 10;
    }
    cout << m << endl;
}