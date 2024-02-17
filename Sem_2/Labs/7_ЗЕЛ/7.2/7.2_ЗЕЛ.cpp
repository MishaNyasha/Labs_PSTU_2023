#include <iostream>
using namespace std;
bool foo(int x, int y, int z)
{
    return((x+y)>=z)&&((x+z)>=y)&&((y+z)>=x);
}
int triangle (int N, ...)
{
    int count = 0;
    
    int *n = &N + 1;
    
    for (int i =0; i<N-2; i++)
    {
        int x =  n[i];
        int y = n[i+1];
        int z = n[i+2];
        if(foo)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int test1 = triangle(3, 3, 2, 4);
    int test2 = triangle(9, 5, 6, 9, 1, 6, 8, 5, 4, 2);
    int test3 = triangle(11, 5, 2, 7, 12, 24, 15, 11, 7, 3, 5, 4);
    cout << "test 1 = " << test1 << endl;
    cout << "test 2 = " << test2 << endl;
    cout << "test 3 = " << test3 << endl;
    return 0;
}
/*
test 1 = 1
test 2 = 7
test 3 = 9
*/