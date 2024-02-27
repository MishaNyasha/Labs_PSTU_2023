# 1) Задание
Сформировать двоичный файл из элементов, заданной в варианте структуры, распечатать его содержимое, выполнить удаление и добавление элементов в соответствии со своим вариантом, используя для поиска удаляемых или добавляемых элементов функцию. Формирование, печать, добавление и удаление элементов оформить в виде функций. Предусмотреть сообщения об ошибках при открытии файла и выполнении операций ввода/вывода.
# 2) Код программы
```cpp
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
struct state
{
    string language;
    string money;
    double rate;
};
using States = map<string, state>;
void write_file(const char * file_name, const States& states)
{
    ofstream outfile(file_name);
    if (!outfile.is_open())
    {
        cout << "error";
        exit(0);
    }
    for(auto i : states)
    {
        outfile << i.first << "  " << i.second.language << "  " << i.second.money << "  " << i.second.rate << endl;
    }
    outfile.close();
}

States read_file(const char * file_name)
{
    ifstream infile(file_name);
    States states;
    if (!infile.is_open())
    {
        cout << "error";
        exit(0);
    }
    while(!infile.eof())
    {
        string name, language, money;
        double rate;
        infile >> name >> language >> money >> rate;
        if (name.length()  == 0)
        {
            break;
        }
        pair<string, state> new_state = pair<string, state>(name, {language, money, rate});
        states.insert(new_state);
    }
    infile.close();
    return states;
}
void print_states(const States& states)
{
    for(auto i : states)
    {
        cout << i.first << "  " << i.second.language << "  " << i.second.money << "  " << i.second.rate << endl;
    }
}
pair<string, state> read_state_from_user()
{
    string name, language, money;
    double rate;
    cin >> name >> language >> money >> rate;
    return pair<string, state>(name, {language, money, rate});
}
States read_states_from_user()
{
    cout << "Введите данные стран (Название, название языка, название денежной единицы, денежная единица относительно $)\n";
    States states;
    for(int i = 0; i < 5; i++)
    {
        pair<string, state> new_state = read_state_from_user();
        states.insert(new_state);
    }
    return states;
}
void create_file()
{
    States states = read_states_from_user();
    cout << "Введенные данные\n";
    print_states(states);
    write_file("F1", states);
}
void erase_state(States& states)
{
    cout << "Введите страну для удаления: ";
    string state_to_erase;
    cin >> state_to_erase;
    states.erase(state_to_erase);
}
void add_state(States& states)
{
    cout << "Введите данные новой страны:\n";
    pair<string, state> new_state = read_state_from_user();
    if(states.find(new_state.first) != states.end())
    {
        cout << "Страна с данным именем уже существует" << endl;
        exit(0);
    }
    states.insert(new_state);
}
void process_file()
{
    States states = read_file("F1");
    erase_state(states);
    add_state(states);
    add_state(states);
    cout << "Результат:\n";
    print_states(states);
    write_file("F2", states);
}
int main()
{
    create_file();
    process_file();
    return 0;
}
```
# 3) Блок-схема
<image src ="8_ЗЕЛ_States read_states_from_user().png">
  <image src ="8_ЗЕЛ_States_read_file.png">
    <image src ="8_ЗЕЛ_add_state.png">
      <image src ="8_ЗЕЛ_create_file.png">
        <image src ="8_ЗЕЛ_erase_state.png">
          <image src ="8_ЗЕЛ_main.png">
            <image src ="8_ЗЕЛ_pair_string, state_ read_state_from_user().png">
              <image src ="8_ЗЕЛ_print_states.png">
                <image src ="8_ЗЕЛ_process_file.png">
                  <image src ="8_ЗЕЛ_struct(state).png">
                    <image src ="8_ЗЕЛ_write_fail.png">
                      
# 4) Тесты
```cpp
/*
    Test
Введите данные стран (Название, название языка, название денежной единицы, денежная единица относительно $)
Germ
Germ
Gr
0.3939
Russ
Russ
Rub
0.107107
Engl
Engl
En
1.07
Japa
Japa
Jp
0.0032
Turk
Turk
Tr
0.315
Введенные данные
Engl  Engl  En  1.07
Germ  Germ  Gr  0.3939
Japa  Japa  Jp  0.0032
Russ  Russ  Rub  0.107107
Turk  Turk  Tr  0.315
Введите страну для удаления: Germ
Введите данные новой страны:
Span
Span
Sp  
1.5
Введите данные новой страны:
USA
Amer
Dollar
1
Результат:
Engl  Engl  En  1.07
Japa  Japa  Jp  0.0032
Russ  Russ  Rub  0.107107
Span  Span  Sp  1.5
Turk  Turk  Tr  0.315
USA  Amer  Dollar  1
*/
```
