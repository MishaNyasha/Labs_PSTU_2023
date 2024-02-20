# 1) Задание
Расположить 8 ферзей на шахматной доске так, чтобы они не били друг друга.
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
const int n = 8;
int board[n][n];
int N = 1;
void show()
{
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cout << ((board[a][b]) ? "[Q] " : "[ ] ");
        }
        cout << endl << endl;;
    }
}
bool check(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        if (board[i][b] == 1)
        {
            return false;
        }
    }
    for (int i = 1; i <= a && b - i >= 0; i++)
    {
        if (board[a - i][b - i] == 1)
        {
            return false;
        }
    }
    for (int i = 1; i <= a && b + i < n; i++)
    {
        if (board[a - i][b + i] == 1)
        {
            return false;
        }
    }
    return true;
}
void set(int a)
{
    if (a == n)
    {
        show();
        cout << "   №" << N++ << endl << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(a, i))
        {
            board[a][i] = 1;
            set(a + 1);
            board[a][i] = 0;
        }
    }
    return;
}
int main()
{
    set(0);
    return 0;
}
```
# 3) Блок-схема
<image src ="8queens_main.png">
  <image src ="8queens_check.png">
    <image src ="8queens_set.png">
      <image src ="8queens_show.png">
        
# 4) Тесты
```cpp
/*
    Test 1
    
[ ] [ ] [ ] [Q] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [Q] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [ ] [ ] [Q] 

[ ] [ ] [Q] [ ] [ ] [ ] [ ] [ ] 

[Q] [ ] [ ] [ ] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [ ] [Q] [ ] 

[ ] [ ] [ ] [ ] [Q] [ ] [ ] [ ] 

[ ] [Q] [ ] [ ] [ ] [ ] [ ] [ ] 


    Test 2
    
[ ] [ ] [ ] [Q] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [ ] [Q] [ ] 

[Q] [ ] [ ] [ ] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [ ] [ ] [Q] 

[ ] [ ] [ ] [ ] [Q] [ ] [ ] [ ] 

[ ] [Q] [ ] [ ] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [Q] [ ] [ ] 

[ ] [ ] [Q] [ ] [ ] [ ] [ ] [ ] 


    Test 3
    
[ ] [ ] [ ] [ ] [ ] [ ] [ ] [Q] 

[ ] [ ] [Q] [ ] [ ] [ ] [ ] [ ] 

[Q] [ ] [ ] [ ] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [Q] [ ] [ ] 

[ ] [Q] [ ] [ ] [ ] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [Q] [ ] [ ] [ ] 

[ ] [ ] [ ] [ ] [ ] [ ] [Q] [ ] 

[ ] [ ] [ ] [Q] [ ] [ ] [ ] [ ] 
*/
```
