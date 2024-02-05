// задача 1: составить таблицу умножению

#include <iostream>

using namespace std;

int main()
{
    int product [10] [10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            product [i] [j] = i * j;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << product [i] [j] << "   ";
        }
        cout << endl;
    }

    return 0;
}
