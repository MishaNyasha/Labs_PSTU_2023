#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include "money.h"
using namespace std;

Money s;
Money sumMinMax(0, 0);

struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

struct Comp_less
{
	bool operator()(Money t1, Money t2)
	{
		if (t1 > t2) return true;
		else return false;
	}
};

void sumAdd(Money& t)
{
	t = t + sumMinMax;
}

vector<Money> makeVector(int n)
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

void printVector(vector<Money> v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	cout << endl;
}

queue<Money> makeQueue(int n)
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

void printQueue(queue<Money> v)
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
	for (int i = key + 1; i < mmm.size(); i++)
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
	if ((n < m.size()) && (n >= 0)) cout << "Элемент найден: " << m[n] << endl;
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