#include <iostream>
#include <string>
using namespace std;
const int CHAR_NUM = 256;
void calcCharTable(string str, int size, int charTable[CHAR_NUM])
{
    for (int i = 0; i < CHAR_NUM; i++)
    {
        charTable[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        charTable[(int)str[i]] = i;
    }
}
void boyerMooreSearch(string str, string pat)
{
    int str_size = str.size();
    int pat_size = pat.size();

    int shift_table[CHAR_NUM];

    calcCharTable(str, pat_size, shift_table);

    int shift = 0;

    while(shift <= (str_size - pat_size))
    {
        int j = pat_size - 1;
        while(j >= 0 && pat[j] == str[shift+j])
        { 
            j--; 
        }
        if (j < 0)
        {
            cout << "Паттерн найден по индексу " << shift << endl;
            if (shift+pat_size < str_size)
            {
                shift += pat_size - shift_table[(int)str[shift+pat_size]];
            }
            else shift++;
        }
        else
        {
            shift += max(1, j - shift_table[(int)str[shift+j]]);
        }
    }
}
int* calcPrefixFunc(string pat, int size)//
{
    int* lps = new int[size];
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < size)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len;
            len++;
            i++;
        }
        else
        {
            if(len != 0) { len = lps[len-1]; }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void knuthMorrisPrattSearch(string str, string pat)
{
    int str_size = str.size();
    int pat_size = pat.size();
    int* lps = calcPrefixFunc(pat, pat_size);
    int str_idx = 0;
    int pat_idx = 0;
    while( (str_size - str_idx) >= (pat_size - pat_idx) )
    {
        if(pat[pat_idx] == str[str_idx])
        {
            pat_idx++;
            str_idx++;
        }
        if(pat_idx == pat_size)
        {
            cout << "Паттерн найден по индексу " << str_idx - pat_idx << endl;
            pat_idx = lps[pat_idx-1];
        }
        else if (str_idx < str_size && pat[pat_idx] != str[str_idx])
        {
            if (pat_idx != 0) 
            { 
                pat_idx = lps[pat_idx-1]; 
            }
            else 
            { 
                str_idx++; 
            }
        }
    }
}
int main()
{
    system("chcp 1251 > NuLL");
    string str, pat;
    cout << "Введите сначала строку и затем элемент, индексы которого надо найти\n";
    cin >> str >> pat;
    cout << "Выберите какой способ хотите:\n"
            "1 - поиск Бойера-Мура\n"
            "2 - Поиск Кнута-Морриса-Пратта\n"
            "Ваш выбор: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        boyerMooreSearch(str, pat);
        break;
    case 2:
        knuthMorrisPrattSearch(str, pat);
        break;
    default: 
        cout << "error";
    }
    return 0;
}
/*
    Test 1
Введите сначала строку и затем элемент, индексы которого надо найти
sssssssssssssssssssssrs
r
Выберите какой способ хотите:
1 - поиск Бойера-Мура
2 - Поиск Кнута-Морриса-Пратта
Ваш выбор: 2
Паттерн найден по индексу 21

    Test 2 
Введите сначала строку и затем элемент, индексы которого надо найти
lesson
lesson
Выберите какой способ хотите:
1 - поиск Бойера-Мура
2 - Поиск Кнута-Морриса-Пратта
Ваш выбор: 1
Паттерн найден по индексу 0

    Test 3 
Введите сначала строку и затем элемент, индексы которого надо найти
randomrandomrandomdomdom
dom
Выберите какой способ хотите:
1 - поиск Бойера-Мура
2 - Поиск Кнута-Морриса-Пратта
Ваш выбор: 2
Паттерн найден по индексу 3
Паттерн найден по индексу 9
Паттерн найден по индексу 15
Паттерн найден по индексу 18
Паттерн найден по индексу 21
*/
