#include "Time.h" 
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;
int make_file(const char* f_sec)
{
    fstream stream(f_sec, ios::out | ios::trunc); 
    if (!stream)return -1; 
    int n;
    Time p;
    cout << "N?"; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p; 
        stream << p << "\n"; 
    }
    stream.close(); 
    return n;
}
int print_file(const char* f_sec)
{
    fstream stream(f_sec, ios::in); 
    if (!stream)return -1; 
    Time p; int i = 0;
    while (stream >> p)
    {
        cout << p << "\n";
        i++;
    }
    stream.close();
    return i;
}
int del_file(const char* f_sec, int k)
{
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);
    if (!stream)return -1;
    int i = 0; Time p;
    while (stream >> p)
    {
        if (stream.eof())break;
        i++;
        if (i != k) temp << p;
    } 
    stream.close(); temp.close();
    remove(f_sec); 
    rename("temp", f_sec); 
    return i;  
}
int add_file(const char* f_sec, int k, Time pp)
{
    fstream temp("temp", ios::out); 
    fstream stream(f_sec, ios::in); 
    if (!stream)return -1;
    Time p; int i = 0, l = 0;
    while (stream >> p)
    {
        if (stream.eof())break;
        i++;
        if (i == k)
        {
            temp << pp;
            l++;
        }
        temp << p;
    }
    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);
    return l;
}
int add_end(const char* f_sec, Time pp)
{
    fstream stream(f_sec, ios::app);
    if (!stream)return -1;
    stream << pp; 
    return 1;
}
int change_file(const char* f_sec, int k, Time pp)
{
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);
    if (!stream)return -1;
    Time p; int i = 0, l = 0;
    char x;
    while (stream >> p)
    {
        if (stream.eof())break;
        i++;
        if (i == k)
        {
            cout << p << " - is changing... Continue[y/n]?\n";
            cin >> x;
            if (x == 'n' || x == 'N')break;
            temp << pp;
            l++;
        }
        else temp << p;
    }
    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);
    return l;
}
int compare_times(const char* file_name1, int k1, const char* file_name2, int k2)
{
    fstream stream1(file_name1, ios::in);
    fstream stream2(file_name2, ios::in);
    if (!stream1 || !stream2)
    {
        cout << "Error opening files" << endl;
        return -1;
    }
    Time p1, p2;
    int i = 0;
    bool found1 = false, found2 = false;

    stream1.seekg(0, ios::beg);
    stream2.seekg(0, ios::beg);
    while (stream1 >> p1)
    {
        i++;
        if (i == k1)
        {
            found1 = true;
            break;
        }
    }
    i = 0;
    while (stream2 >> p2)
    {
        i++;
        if (i == k2)
        {
            found2 = true;
            break;
        }
    }
    stream1.close();
    stream2.close();
    if (!found1 || !found2)
    {
        cout << "Record not found in one of the files" << endl;
        return -1;
    }
    if (p1 == p2)
    {
        cout << "Times are equal" << endl;
    }
    else
    {
        cout << "Times are not equal" << endl;
    }
    return 0;
}
