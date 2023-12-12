#include <iostream>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    int Sum = 0;
    int znak = -1; 

    for (int i = 1; i <= N; i++) 
    {
        Sum += znak * i;
        znak *= -1; 
    }

    cout << Sum;
}