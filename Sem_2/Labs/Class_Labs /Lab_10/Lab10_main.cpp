#include "Time.h" 
#include <iostream> 
#include <fstream> 
#include <string> 
#include "file_work.h" 
using namespace std;
void main()
{
    Time p, p1, p2;
    int k, c;
    char file_name[30];
    int k1, k2;
    char file_name1[30], file_name2[30];
    do
    {
        cout << "\n1. make file";
        cout << "\n2. print file";
        cout << "\n3. delete record from file";
        cout << "\n4. add record to file";
        cout << "\n5. change record in file";
        cout << "\n6. compare";
        cout << "\n0. exit\n";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "file name: ";
            cin >> file_name;
            k = make_file(file_name);
            if (k < 0)
                cout << "can't make file";
            break;
        case 2:
            cout << "file name: ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0)
                cout << "empty file\n";
            if (k < 0)
                cout << "can't read file\n";
            break;
        case 3:
            cout << "file name: ";
            cin >> file_name;
            int nom;
            cout << "nom: ";
            cin >> nom;
            k = del_file(file_name, nom);
            if (k < 0)
                cout << "can't read file";
            break;
        case 4:
            cout << "file name: ";
            cin >> file_name;
            cout << "nom: ";
            cin >> nom;
            cout << "new time: ";
            cin >> p1;
            k = add_file(file_name, nom, p1);
            if (k < 0)
                cout << "can't read file";
            if (k == 0)
                k = add_end(file_name, p1);
            break;
        case 5:
            cout << "file name: ";
            cin >> file_name;
            cout << "nom: ";
            cin >> nom;
            cout << "new time:";
            cin >> p2;
            k = change_file(file_name, nom, p2);
            if (k < 0)
                cout << "\ncan't read file";
            if (k == 0)
                cout << "\nnot such record";
            break;
        case 6:
            cout << "Enter first file name: ";
            cin >> file_name1;
            cout << "Enter position in first file: ";
            cin >> k1;
            cout << "Enter second file name: ";
            cin >> file_name2;
            cout << "Enter position in second file: ";
            cin >> k2;
            compare_times(file_name1, k1, file_name2, k2);
            break;
        }
    } while (c != 0);
}
