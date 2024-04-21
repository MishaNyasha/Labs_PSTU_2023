#include "Vector.h" 
#include "Error.h" 
#include <iostream> 
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
	try
	{
        int q;
        cout << "введите размер вектора x (до 30): ";
        cin >> q;
        Vector x(q);
        cout << "пустой вектор x: " << x << endl;
        cout << "заполните вектора x:\n";
        cin >> x;
        cout << "заполненный вектора x: " << x << endl;

        cout << "введите индекс = ";
        int i;
        cin >> i;
        cout << x[i] << endl;

        Vector y(5);
        cout << "пустой вектор y:" << y << endl;
        cout << "заполните вектор y: \n";
        cin >> y;
        cout << "заполненный вектора y: " << y << endl;

        cout << "операция добавления константы '3' ко всем элементам вектора y : ";
        const int k = 3;
        y = y + k;
        cout << endl << y;

        cout << "операция удаления '2' элементов из конца вектора y: ";
        --y;
        --y;
        cout << endl << y;
	}

	catch (error e)
	{
		e.what();
	}

	return 0;
}
