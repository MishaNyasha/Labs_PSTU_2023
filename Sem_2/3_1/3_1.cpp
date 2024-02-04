#include <iostream> 
using namespace std;
int main()
{
    int lb = 20, ub = 100;
    int arr[50];
    for (int i = 0; i < 50; i++)
    {
        arr[i] = (rand() % (ub - lb + 1)) + lb;
        cout << arr[i] << "  ";
    }
    cout << endl << endl << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[49 - i] << "  ";
    }
    return 0;
}
