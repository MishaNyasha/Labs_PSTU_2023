# Лабораторная работа  No3 
# Классы и объекты. Перегрузка операций. 

## (1) Задание
# Задача 1.
1. Создать последовательный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
4. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
5. Найти в контейнере заданный элемент (использовать алгоритмы find(), find_if(), count(), count_if()).
6. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()).
7. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.
# Задача 2.
1. Создать адаптер контейнера.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
4. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
5. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы find(), find_if(), count(), count_if()).
6. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()).
7. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.
# Задача 3
1. Создать ассоциативный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
4. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
5. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы find(), find_if(), count(), count_if()).
6. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()).
7. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.
## Вариант 7
# Задача 1
1. Контейнер - вектор
2. Тип элементов Money (см. лабораторную работу №3).
# Задача 2
Адаптер контейнера - очередь.
# Задача 3
Ассоциативный контейнер - словарь.
# Задание 3                      
Найти минимальный элемент и добавить его в конец контейнера.
# Задание 4
Найти элемент с заданным ключом и удалить его из контейнера.
# Задание 5
К каждому элементу добавить сумму минимального и максимального элементов контейнера.

## (2) Реализация 
`money.h`
```cpp
#pragma once
#include <iostream>
using namespace std;
class Money
{
	long long int rubles;
	int kopecks;
public:
	Money()
	{
		rubles = 0;
		kopecks = 0;
	}
	Money(long long int r, int k)
	{
		rubles = r;
		kopecks = k;
	}
	Money(const Money& t)
	{
		rubles = t.rubles;
		kopecks = t.kopecks;
	}
	~Money() {};
	long long int getRubles()
	{
		return rubles;
	}
	int getKopecks()
	{
		return kopecks;
	}
	void setRubles(long long int r)
	{
		rubles = r;
	}
	void setKopecks(int k)
	{
		kopecks = k;
	}
	Money& operator=(const Money&);
	bool operator==(const Money&);
	bool operator<(const Money&);
	bool operator<=(const Money&);
	bool operator>(const Money&);
	bool operator>=(const Money&);
	Money& operator++(); // префиксная
	Money& operator--(); // префиксная
	Money operator++(int); //постфиксная
	Money operator--(int); //постфиксная
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money operator*(const Money&);
	Money operator/(const Money&);
	Money operator*(const double&);
	Money operator/(const double&);
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
	friend fstream& operator>>(fstream& fin, Money& t);
	friend fstream& operator<<(fstream& fout, const Money& t);
};
```

`money.cpp`
```cpp
#pragma once
#include "money.h"
#include <iostream>
#include <fstream>
using namespace std;
Money& Money::operator=(const Money& t)
{
	if (&t == this) return *this;
	rubles = t.rubles;
	kopecks = t.kopecks;
	return *this;
}
bool Money::operator==(const Money& t)
{
	if ((kopecks == t.kopecks) && (rubles == t.rubles)) return true;
	else return false;
}
bool Money::operator<(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 < allKopecks2) return true;
	else return false;
}
bool Money::operator<=(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 <= allKopecks2) return true;
	else return false;
}
bool Money::operator>(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 > allKopecks2) return true;
	else return false;
}
bool Money::operator>=(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 >= allKopecks2) return true;
	else return false;
}
Money& Money::operator++() // префиксная операция
{
	rubles++;
	return *this;
}
Money& Money::operator--() // префиксная операция
{
	rubles--;
	return *this;
}
Money Money::operator ++(int) // постфиксная операция
{
	long long int temp = rubles;
	temp++;
	Money t(temp, kopecks);
	return t;
}
Money Money::operator--(int) // постфиксная операция
{
	Money tmp = *this;
	tmp.rubles--;
	return tmp;
}
Money Money::operator+(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int  kop = kopecks;
	int kop2 = t.kopecks;
	int buf;
	Money summa;
	summa.rubles = rub + rub2;
	summa.kopecks = (kop + kop2) % 100;
	buf = (kop + kop2) / 100;
	summa.rubles += buf;
	return summa;
}
Money Money::operator-(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int kop = kopecks;
	int kop2 = t.kopecks;
	long long int allKopecks1 = rub * 100 + kop;
	long long int allKopecks2 = rub2 * 100 + kop2;
	Money sub;
	sub.kopecks = (allKopecks1 - allKopecks2) % 100;
	sub.rubles = (allKopecks1 - allKopecks2) / 100;
	return sub;
}
Money Money::operator*(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int  kop = kopecks;
	int kop2 = t.kopecks;
	long long int buf;
	long long int allKopecks1 = rub * 100 + kop;
	long long int allKopecks2 = rub2 * 100 + kop2;
	buf = allKopecks1 * allKopecks2;
	Money product;
	product.rubles = 0;
	product.kopecks = buf % 10000 / 100;
	product.rubles += buf/10000;
	return product;
}
Money Money::operator/(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int  kop = kopecks;
	int kop2 = t.kopecks;
	double buf;
	long double allKopecks1 = rub * 100 + kop;
	long double allKopecks2 = rub2 * 100 + kop2;
	buf = allKopecks1 / allKopecks2;
	Money divided;
	divided.rubles = buf;
	buf -= abs(divided.rubles);
	buf *= 100;
	divided.kopecks = buf;
	return divided;
}
Money Money::operator*(const double& t)
{
	long long int rub = rubles;
	int kop = kopecks;
	long long int buf;
	long long int allKopecks = rub * 100 + kop;
	buf = allKopecks * t;
	Money divided;
	divided.rubles = 0;
	divided.kopecks = buf % 100;
	divided.rubles += buf / 100;
	return divided;
}
Money Money::operator/(const double& t)
{
	long long int rub = rubles;
	int kop = kopecks;
	long long int buf;
	long long int allKopecks = rub * 100 + kop;
	buf = allKopecks / t;
	Money divided;
	divided.rubles = 0;
	divided.kopecks = buf % 100;
	divided.rubles += buf / 100;
	return divided;
}
istream& operator>>(istream& in, Money& t)
{
	cout << "Введите рубли без копеек (если вы вводите отрицательное число, вводите и рубли и копейки со знаком минус): ";
	in >> t.rubles;
	cout << "Введите копейки без рублей: "; in >> t.kopecks;
	if (abs(t.kopecks) >= 100)
	{
		int buf = t.kopecks / 100;
		t.rubles += buf;
		t.kopecks = t.kopecks % 100;
	}
	return in;
}
ostream& operator<<(ostream& out, const Money& t)
{
	int boof = t.kopecks;
	if (t.kopecks < 0)
	{
		boof = -t.kopecks;
	}
	if ((t.rubles == 0) && (t.kopecks < 0))
	{
		if (boof >= 10)
		{
			return (out << "-" << t.rubles << "," << boof);
		}
		else
		{
			return (out << "-" << t.rubles << "," << 0 << boof);
		}
	}
	else if (boof >= 10)
	{
		return (out << t.rubles << "," << boof);
	}
	else
	{
		return (out << t.rubles << "," << 0 << boof);
	}
}
fstream& operator>>(fstream& fin, Money& t)
{
	char buf1, buf2;
	fin >> buf1 >> t.rubles >> buf2 >> t.kopecks;
	if (buf1 == '-')
	{
		t.rubles *= -1;
		t.kopecks *= -1;
	}
	return fin;
}
fstream& operator<<(fstream& fout, const Money& t)
{
	fout << (t.rubles >= 0 ? '+' : '-') << (t.rubles >= 0 ? t.rubles : -t.rubles) << ',' << (t.kopecks >= 0 ? t.kopecks : -t.kopecks) << endl;
	return fout;
}
```

прикольный `main.cpp`
```cpp
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include "money.h"
using namespace std;

Money s;
Money sumMinMax(0, 0); // для обработки каждого

struct Equal_s // для поиска
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

struct Comp_less // для сортировки по убыванию
{
	bool operator()(Money t1, Money t2)
	{
		if (t1 > t2) return true;
		else return false;
	}
};

void sumAdd(Money& t) // для обработки каждого
{
	t = t + sumMinMax;
}

vector<Money> makeVector(int n) // создание и наполнение вектора
{
	Money a;
	vector<Money> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void printVector(vector<Money> v) // печать вектора
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	cout << endl;
}

queue<Money> makeQueue(int n) // создание и наполнение очереди
{
	Money a;
	queue<Money> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push(a);
	}
	return v;
}

void printQueue(queue<Money> v) // печать очереди
{
	Money tmp;
	for (int i = 0; i < v.size(); i++)
	{
		tmp = v.front();
		v.pop();
		cout << tmp << endl;
		v.push(tmp);
	}
	cout << endl;
}

vector<Money> copyQueueToVector(queue<Money> q)
{
	vector<Money> result;
	Money tmp;
	for (int i = 0; i < q.size(); i++)
	{
		tmp = q.front();
		q.pop();
		result.push_back(tmp);
		q.push(tmp);
	}
	return result;
}

queue<Money> copyVectorToQueue(vector<Money> v)
{
	queue<Money> result;
	Money tmp;
	for (int i = 0; i < v.size(); i++)
	{
		result.push(v[i]);
	}
	return result;
}

void sortQueue_o0O(queue<Money>& q)
{
	vector<Money> v(copyQueueToVector(q));
	sort(v.begin(), v.end());
	q = copyVectorToQueue(v);
}

void sortQueue_O0o(queue<Money>& q)
{
	vector<Money> v(copyQueueToVector(q));
	sort(v.begin(), v.end(), Comp_less());
	q = copyVectorToQueue(v);
}

Money queueMin(queue<Money> q)
{
	vector<Money> v(copyQueueToVector(q));
	auto i = min_element(v.begin(), v.end());
	return (*i);
}

Money queueMax(queue<Money> q)
{
	vector<Money> v(copyQueueToVector(q));
	auto i = max_element(v.begin(), v.end());
	return (*i);
}

Money queueFindS(queue<Money> q, Money s)
{
	vector<Money> v(copyQueueToVector(q));
	Money result(INT64_MAX, INT32_MAX);
	auto i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())
	{
		cout << "Элемент найден: " << *i << endl;
		result = (*i);
		return result;
	}
	else cout << "Нет такого элемента!" << endl;
	return result;
}

void queueRemoveS(queue<Money>& q, Money s)
{
	vector<Money> v(copyQueueToVector(q));
	auto i = remove_if(v.begin(), v.end(), Equal_s());
	v.erase(i, v.end());
	q = copyVectorToQueue(v);
}

void queueMinMaxAdder(queue<Money>& q)
{
	vector<Money> v(copyQueueToVector(q));
	sumMinMax = sumMinMax + queueMin(q);
	sumMinMax = sumMinMax + queueMax(q);
	for_each(v.begin(), v.end(), sumAdd);
	q = copyVectorToQueue(v);
}

map<int, Money> makeMap(int n)
{
	map<int, Money> m;
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void printMap(map<int, Money> m)
{
	for (int i = 0; i < m.size(); i++) cout << i << " - " << m[i] << endl;
}

int mapMaxElemKey(map<int, Money> v)
{
	auto i = v.begin(); 
	int nom = 0, k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

int mapMinElemKey(map<int, Money> v)
{
	auto i = v.begin();
	int nom = 0, k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

void delOneElemMap(map<int, Money>& mmm, int key)
{
	if (key >= mmm.size()) return;
	vector<Money> v;
	Money a;
	for (int i = 0; i < key; i++)
	{
		v.push_back(mmm[i]);
	}
	for (int i = key+1; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void sortMap_o0O(map<int, Money>& mmm)
{
	vector<Money> v;
	Money a;
	for (int i = 0; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	sort(v.begin(), v.end());
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void sortMap_O0o(map<int, Money>& mmm)
{
	vector<Money> v;
	Money a;
	for (int i = 0; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	sort(v.begin(), v.end(), Comp_less());
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void minMaxAddToMap(map<int, Money>& mmm)
{
	vector<Money> v;
	Money a;
	for (int i = 0; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	for_each(v.begin(), v.end(), sumAdd);
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

int main()
{
	system("chcp 1251 > null");
	int n;
	cout << "ЗАДАЧА 1. ВЕКТОР." << endl;
	cout << "Введите количество элементов в векторе: ";	cin >> n;
	vector<Money> v;
	v = makeVector(n);
	printVector(v);

	auto i = min_element(v.begin(), v.end());
	cout << "Минимальный элемент = " << *i << endl;
	v.push_back(*i);
	cout << "Пушим минимальный элемент в конец вектора:" << endl;
	printVector(v);

	cout << "Введите ключ, по которому будет найден элемент:\n";
	cin >> s;
	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end()) cout << "Элемент найден: " << *(i) << endl;
	else cout << "Нет такого элемента!" << endl;
	cout << "Удаление всех элементов с таким ключом:\n";
	i = remove_if(v.begin(), v.end(), Equal_s());
	v.erase(i, v.end());
	printVector(v);

	cout << "Сортировка по убыванию:" << endl;
	sort(v.begin(), v.end(), Comp_less());
	printVector(v);
	cout << "Сортировка по возрастанию:" << endl;
	sort(v.begin(), v.end());
	printVector(v);

	cout << "Ко всем элементам добавили сумму макс. и мин. элементов:" << endl;
	i = min_element(v.begin(), v.end());
	sumMinMax = sumMinMax + (*i);
	i = max_element(v.begin(), v.end());
	sumMinMax = sumMinMax + (*i);
	for_each(v.begin(), v.end(), sumAdd);
	printVector(v);
	sumMinMax.setKopecks(0); sumMinMax.setRubles(0);

	cout << "ЗАДАЧА 2. ОЧЕРЕДЬ." << endl;
	cout << "Введите количество элементов в очереди: ";	cin >> n;
	queue<Money> q;
	q = makeQueue(n);
	printQueue(q);

	Money qElem = queueMin(q);
	cout << "Минимальный элемент = " << qElem << endl;
	q.push(qElem);
	cout << "Пушим минимальный элемент в конец очереди:" << endl;
	printQueue(q);

	cout << "Введите ключ, по которому будет найден элемент:\n";
	cin >> s;
	queueFindS(q, s);
	cout << "Удаление всех элементов с таким ключом:\n";
	queueRemoveS(q, s);
	printQueue(q);

	cout << "Сортировка по убыванию:" << endl;
	sortQueue_O0o(q);
	printQueue(q);
	cout << "Сортировка по возрастанию:" << endl;
	sortQueue_o0O(q);
	printQueue(q);

	cout << "Ко всем элементам добавили сумму макс. и мин. элементов:" << endl;
	queueMinMaxAdder(q);
	printQueue(q);
	sumMinMax.setKopecks(0); sumMinMax.setRubles(0);

	cout << "ЗАДАЧА 3. СЛОВАРЬ." << endl;
	cout << "Введите количество элементов в словаре: ";	cin >> n;
	map<int, Money> m;
	m = makeMap(n);
	printMap(m);

	n = mapMinElemKey(m);
	cout << "Минимальный элемент = " << m[n] << endl;
	m.insert(make_pair(m.size(), m[n]));
	cout << "Пушим минимальный элемент в конец словаря:" << endl;
	printMap(m);

	cout << "Введите ключ, по которому будет найден элемент (в этом словаре ключ совпадает с индексом):\n";
	cin >> n;
	if ((n < m.size())&&(n >= 0)) cout << "Элемент найден: " << m[n] << endl;
	else cout << "Нет такого элемента!" << endl;
	cout << "Удаление элемента с таким ключом:\n";
	delOneElemMap(m, n);
	printMap(m);

	cout << "Сортировка по убыванию второго поля:" << endl;
	sortMap_O0o(m);
	printMap(m);
	cout << "Сортировка по возрастанию второго поля:" << endl;
	sortMap_o0O(m);
	printMap(m);

	cout << "Ко всем элементам добавили сумму макс. и мин. элементов:" << endl;
	n = mapMinElemKey(m);
	sumMinMax = sumMinMax + m[n];
	n = mapMaxElemKey(m);
	sumMinMax = sumMinMax + m[n];
	minMaxAddToMap(m);
	printMap(m);
	sumMinMax.setKopecks(0); sumMinMax.setRubles(0);
	return 0;
}
```
## (3) UML - диаграмма
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_13/UML13class.drawio.png">
  
## (4) Тест
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_13/1.png">
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_13/2.png">
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Class_Labs%20/Lab_13/3.png">
