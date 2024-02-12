#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    bool flag = 1;
    char S[255];
    gets(S);
    for (int i = 0; i <= (strlen(S)-1); i++)
    {
        if (S[i] == S[(strlen(S))-1-i]) {flag = 1;}
        else {flag = 0;}
    }
    if (flag) {cout << "Выражение является пaлиндромом";}
    else {cout << "Выражение не является пaлиндромом";}
    return 0;
}
/*
    Test 1
Kirill durak
Выражение не является пaлиндромом

    Test 2
ArgentinaManitnegrA                            
Выражение является пaлиндромом
    
    Test 3
Arbuz u zubrA
Выражение являетcя пaлиндромом
*/