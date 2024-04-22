# Лабораторная работа  No10
# Сохранение данных в файле с использованием потоков. 

## (1) Задание
1.  Создать пользовательский класс с минимальной функциональностью. 
2.  Написать  функцию  для  создания  объектов  пользовательского  класса  (ввод исходной информации с клавиатуры) и сохранения их в потоке (файле).  
3.  Написать функцию для чтения и просмотра объектов из потока.  
4.  Написать функцию для удаления  объектов из потока в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций. 
5.  Написать  функцию  для  добавления  объектов  в  поток  в  соответствии  с  заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций. 
6.  Написать  функцию  для  изменения  объектов в  потоке  в  соответствии  с  заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций. 
7.  Для вызова функций в основной программе предусмотреть меню.
### Вариант 1
Создать класс Time для работы с временными интервалами. Интервал должен быть представлен в виде двух полей: минуты типа int и секунды типа int. при выводе минуты отделяются от секунд двоеточием. 
Реализовать: 
- сложение временных интервалов (учесть, что в минуте не может быть более 60 секунд) 
- сравнение временных интервалов (==) 
## (2) Реализация 
- приколюшная main функция:
```cpp
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
```
- Time.cpp
```cpp
#include "Time.h" 
Time::Time()
{
	sec = 0; min = 0;
}
Time::Time(int N, int A)
{
	sec = N; min = A;
}
Time::Time(const Time& p)
{
	sec = p.sec; min = p.min;
}
Time Time::operator =(const Time& p)
{
	if (&p == this) return *this;
	sec = p.sec;
	min = p.min;
	return*this;
}
Time::~Time()
{
}
ostream& operator<<(ostream& out, const Time& p)
{
	out << p.min << ":" << p.sec << "\n";
	return out;
}

istream& operator>>(istream& in, Time& p)
{
	cout << "min: "; in >> p.min;
	cout << "sec: "; in >> p.sec;
	cout << endl;
	return in;
}
fstream& operator>>(fstream& fin, Time& p)
{
	fin >> p.sec;
	fin >> p.min;
	return fin;
}
fstream& operator<<(fstream& fout, const Time& p)
{
	fout << p.sec << "\n" << p.min << "\n";
	return fout;
}
bool Time::operator==(const Time& t)
{
	if ((min == t.min) && (sec == t.sec)) return true;
	else return false;
}
```
- Time.h
```cpp
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time
{
public:
    Time();
    Time(int, int);
    Time(const Time&);
    Time operator =(const Time&);
    bool operator==(const Time&);
    friend ostream& operator <<(ostream& out, const Time& p);
    friend istream& operator>>(istream& in, Time& p);
    friend fstream& operator>>(fstream& fin, Time& p);
    friend fstream& operator <<(fstream& fout, const Time& p);
public:
    ~Time();
private:
    int sec;
    int min;
};
```
- file_work.h
```cpp
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
```

## (3) UML - диаграмма
<image src ="">
  
## (4) Тест
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_10/изображение_2024-04-22_155904931.png">

## (5) Ответы на вопросы
**1. Что такое поток?**

`Поток в C++ — это абстракция, которая представляет последовательность байтов или символов. Это может быть поток данных, который поступает из устройства ввода, такого как клавиатура, или поток данных, который направляется в устройство вывода, например, на экран или в файл.`

**2. Какие типы потоков существуют?**

`Существуют три основных типа потоков: ввода (istream), вывода (ostream) и двунаправленные потоки (iostream), которые поддерживают как ввод, так и вывод.`

**3. Какую библиотеку надо подключить при использовании стандартных потоков?**

`Для использования стандартных потоков ввода/вывода необходимо подключить библиотеку <iostream>.`

**4. Какую библиотеку надо подключить при использовании файловых потоков?**

`Для работы с файловыми потоками нужно подключить библиотеку <fstream>.`

**5. Какую библиотеку надо подключить при использовании строковых потоков?**

`Для использования строковых потоков необходимо подключить библиотеку <sstream>.`

**6. Какая операция используется при выводе в форматированный поток?**

`Для вывода в форматированный поток используется операция вставки <<.`

**7. Какая операция используется при вводе из форматированных потоков?**

`Для ввода из форматированных потоков используется операция извлечения >>.`

**8. Какие методы используются при выводе в форматированный поток?**

`Методы put(), write(), и перегруженный оператор <<, используются для вывода в форматированный поток.`

**9. Какие методы используется при вводе из форматированного потока?**

`Методы get(), read(), getline(), и перегруженный оператор >>, используются для ввода из форматированного потока.`

**10. Какие режимы для открытия файловых потоков существуют?**

`Режимы открытия файловых потоков: ios::in (чтение), ios::out (запись), ios::app (добавление в конец файла), ios::ate (перемещение указателя в конец файла при открытии), ios::trunc (обрезание файла при открытии), и ios::binary (бинарный режим).`

**11. Какой режим используется для добавления записей в файл?**

`Для добавления записей в файл используется режим ios::app.`

**12. Какой режим (комбинация режимов) используется в конструкторе ifstream file("f.txt")?**

`В конструкторе ifstream file("f.txt") используется режим ios::in.`

**13. Какой режим (комбинация режимов) используется в конструкторе fstream file("f.txt")?**

`В конструкторе fstream file("f.txt") используются режимы ios::in | ios::out.`

**14. Какой режим (комбинация режимов) используется в конструкторе ofstream file("f.txt")?**

`В конструкторе ofstream file("f.txt") используется режим ios::out.`

**15. Каким образом открывается поток в режиме ios::out|ios::app?**

`Поток открывается с использованием конструктора или метода open() с указанием режимов ios::out | ios::app, что позволяет записывать данные в конец файла, не удаляя его текущее содержимое.`

**16. Каким образом открывается поток в режиме ios::out |ios::trunc?**

`Поток открывается с использованием конструктора или метода open() с указанием режимов ios::out | ios::trunc, что приводит к обрезанию файла и записи данных с начала файла.`

**17. Каким образом открывается поток в режиме ios::out |ios::in|ios::trunc?**

`Поток открывается с использованием конструктора или метода open() с указанием режимов ios::out | ios::in | ios::trunc, что позволяет читать и писать в файл, при этом файл обрезается при открытии.`

**18. Каким образом можно открыть файл для чтения?**

`Файл для чтения можно открыть, используя конструктор ifstream или метод open() объекта ifstream с указанием пути к файлу.`

**19. Каким образом можно открыть файл для записи?**

`Файл для записи можно открыть, используя конструктор ofstream или метод open() объекта ofstream с указанием пути к файлу.`

**20. Привести примеры открытия файловых потоков в различных режимах.**

```cpp
std::ofstream out("file.txt"); // Открытие для записи, режим ios::out
std::ifstream in("file.txt"); // Открытие для чтения, режим ios::in
std::fstream fs("file.txt", std::ios::in | std::ios::out); // Открытие для чтения и записи
std::ofstream out_app("file.txt", std::ios::app); // Открытие для добавления в конец файла
```
`Также можно создать множество других комбинаций режимов, добавлять к ним ios::trunc, соединять вместе, применять к разным объектам, открывать через open() и т.д.`

**21. Привести примеры чтения объектов из потока.**

```cpp
int number;
std::ifstream in("file.txt");
in >> number; // Чтение числа из файла
```
`Перегружая >>, мы можем читать из файла и объекты класса, так же, как и в примере с числом, но только при учете того, что объекты классов перед этим были занесены в файл определенным образом, например, через перегруженный <<.`

**22. Привести примеры записи объектов в поток.**

```cpp
int number = 42;
std::ofstream out("file.txt");
out << number; // Запись числа в файл
```
`Перегружая <<, мы можем писать в файл и объекты класса, так же, как и в примере с числом, важно также перегрузить >>, чтобы в будущем правильно считать объекты классов из файла.`

**23. Сформулировать алгоритм удаления записей из файла.**

```txt
1. Создать временный файл для записи.
2. Открыть исходный файл для чтения.
3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
4. Инициализировать счетчик прочитанных записей.
5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
	- Если достигнут конец файла, прервать чтение.
	- Увеличить счетчик прочитанных записей.
	- Если номер текущей записи не равен заданному номеру k, записать её во временный файл.
6. Закрыть исходный и временный файлы.
7. Удалить исходный файл.
8. Переименовать временный файл в исходный.
9. Вернуть количество прочитанных записей.

Данная функция принимает название файла (полный путь), номер элемента который нужно удалить.
```

**24. Сформулировать алгоритм добавления записей в файл.**

```txt
1. Создать временный файл для записи.
2. Открыть исходный файл для чтения.
3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
4. Инициализировать счетчики прочитанных и добавленных записей.
5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
	- Если достигнут конец файла, прервать чтение.
	- Увеличить счетчик прочитанных записей.
	- Если номер текущей записи равен заданному номеру k, записать новую запись во временный файл и увеличить счетчик добавленных записей, иначе - записать текущую запись во временный файл.
6. Закрыть исходный и временный файлы.
7. Удалить исходный файл.
8. Переименовать временный файл в исходный.
9. Вернуть количество добавленных записей.

Данная функция принимает название файла (полный путь), номер элемента, куда нужно вставить запись и запись, которую нужно вставить.
```

**25. Сформулировать алгоритм изменения записей в файле.**

```txt
1. Создать временный файл для записи.
2. Открыть исходный файл для чтения.
3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
4. Инициализировать счетчики прочитанных и измененных записей.
5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
	- Если достигнут конец файла, прервать чтение.
	- Увеличить счетчик прочитанных записей.
	- Если номер текущей записи равен заданному номеру k, записать измененную запись во временный файл и увеличить счетчик измененных записей, иначе - записать текущую запись во временный файл.
6. Закрыть исходный и временный файлы.
7. Удалить исходный файл.
8. Переименовать временный файл в исходный.
9. Вернуть количество измененных записей.

Данная функция принимает название файла (полный путь), номер элемента, который нужно изменить и запись, на которую нужно изменить запись с указанным номером.
```
