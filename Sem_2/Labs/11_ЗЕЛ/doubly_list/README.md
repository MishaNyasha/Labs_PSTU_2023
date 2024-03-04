# 1) Код программы
```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Node
{
    char* key;
    Node* pointer_to_prev_node = nullptr;
    Node* pointer_to_next_node = nullptr;
};
Node* create_Node(const char* key)
{
    Node* new_Node = new Node;
    new_Node->key = new char[strlen(key) + 1];
    strcpy(new_Node->key, key);
    new_Node->pointer_to_prev_node = nullptr;
    new_Node->pointer_to_next_node = nullptr;
    return new_Node;
}
void prin_list (Node* head_node)
{
    if (head_node == nullptr)
    {
        cout << "Список пуст" << endl;
        return;
    }
    Node* current_node = head_node;
    while (current_node != nullptr)
    {
        cout << current_node->key << "  ";
        current_node = current_node->pointer_to_next_node;
    }
    cout << endl;
}
void add_element_to_start (Node*& head_node, const char* key)
{
    Node* new_Node = create_Node(key);
    new_Node->pointer_to_next_node = head_node;
    if (head_node != nullptr)
    {
        head_node->pointer_to_prev_node = new_Node;
    }
    head_node = new_Node;
}
void add_element_to_end (Node*& head_node, const char* key)
{
    Node* new_Node = create_Node(key);
    if (head_node == nullptr)
    {
        head_node = new_Node;
    }
    else
    {
        Node* current_node = head_node;
        while (current_node->pointer_to_next_node != nullptr)
        {
            current_node = current_node->pointer_to_next_node;
        }
        current_node->pointer_to_next_node = new_Node;
        new_Node->pointer_to_prev_node = current_node;
    }
}
void delete_element (Node*& head_node, const char* key)
{
    if (head_node == nullptr)
    {
        return;
    }
    Node* current_node = head_node;
    while (current_node != nullptr)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            if(current_node->pointer_to_prev_node != nullptr)
            {
                current_node->pointer_to_prev_node->pointer_to_next_node = current_node->pointer_to_next_node;
            }
            else
            {
                head_node = current_node->pointer_to_next_node;
            }
            if(current_node->pointer_to_next_node != nullptr)
            {
                current_node->pointer_to_next_node->pointer_to_prev_node = current_node->pointer_to_prev_node;
            }
            delete[] current_node->key;
            delete current_node;
            return;
        }
        current_node = current_node->pointer_to_next_node;
    }
}
void write_list_in_file(Node* head_node)
{
    ofstream file("file");
    Node* current_node = head_node;
    while (current_node != nullptr)
    {
        file << current_node->key << endl;
        current_node = current_node->pointer_to_next_node;
    }
    file.close();
}
void destroy_list(Node*& head_node)
{
    Node* current_node = head_node;
    while (current_node != nullptr)
    {
        Node* temp = current_node;
        current_node = current_node->pointer_to_next_node;
        delete[] temp->key;
        delete temp;
    }
    head_node = nullptr;
}
Node* restore_list_from_file()
{
    Node* head_node = nullptr;
    ifstream file("file");
    if (!file)
    {
        cout << "Ошибка открытия файла." << endl;
        return head_node;
    }
    string key;
    while (getline(file, key))
    {
        add_element_to_end(head_node, key.c_str());
    }
    file.close();
    return head_node;
}
int main()
{
    Node* head_node = nullptr;
    cout << "Сколько К элементов добавить в начало и конец?" << endl;
    int k;
    cin >> k;
    cout << "Введите элементы:" << endl;
    char S[255];
    cin.getline(S, 255);
    for (int i = 0; i < k; i++)
    {
        cout << "Добавить в начало:";
        cin.getline(S, 255);
        add_element_to_start(head_node, S);
        cout << "Добавить в конец:";
        cin.getline(S, 255);
        add_element_to_end(head_node, S);
    }
    prin_list(head_node);
    write_list_in_file(head_node);
    cout << "Введие ключевое слово, которое надо удалить: ";
    char LL[255];
    cin.getline(LL, 255);
    delete_element(head_node, LL);
    prin_list(head_node);
    destroy_list(head_node);
    prin_list(head_node);
    head_node = restore_list_from_file();
    prin_list(head_node);
    destroy_list(head_node);
    return 0;
}
```
# 2) Блок-схема
 <image src ="11_ЗЕЛ_add_element_to_end .png">
  <image src ="11_ЗЕЛ_add_element_to_start .png">
   <image src ="11_ЗЕЛ_create_Node.png">
    <image src ="11_ЗЕЛ_delete_element .png">
     <image src ="11_ЗЕЛ_destroy_list.png">
      <image src ="11_ЗЕЛ_doubly_list.cpp">
       <image src ="11_ЗЕЛ_main.png">
        <image src ="11_ЗЕЛ_prin_list.png">
         <image src ="11_ЗЕЛ_restore_list_from_file.png">
          <image src ="11_ЗЕЛ_struct.png">
           <image src ="11_ЗЕЛ_write_list_in_file.png">
      
# 3) Тесты
```cpp
/*
    Test 1
Сколько К элементов добавить в начало и конец?
5
Введите элементы:
Добавить в начало:ss
Добавить в конец:rr
Добавить в начало:qq
Добавить в конец:zz
Добавить в начало:oo
Добавить в конец:pp
Добавить в начало:gg
Добавить в конец:cc
Добавить в начало:nn
Добавить в конец:mm
nn  gg  oo  qq  ss  rr  zz  pp  cc  mm  
Введие ключевое слово, которое надо удалить: zz
nn  gg  oo  qq  ss  rr  pp  cc  mm  
Список пуст
nn  gg  oo  qq  ss  rr  zz  pp  cc  mm  

    Test 2
Сколько К элементов добавить в начало и конец?
3
Введите элементы:
Добавить в начало:Roar
Добавить в конец:gaoh
Добавить в начало:orroa
Добавить в конец:tieng_gam
Добавить в начало:rugido
Добавить в конец:garjana
rugido  orroa  Roar  gaoh  tieng_gam  garjana  
Введие ключевое слово, которое надо удалить: gaoh
rugido  orroa  Roar  tieng_gam  garjana  
Список пуст
rugido  orroa  Roar  gaoh  tieng_gam  garjana  

    Test 3
Сколько К элементов добавить в начало и конец?
4
Введите элементы:
Добавить в начало:Chapa
Добавить в конец:Rubi
Добавить в начало:Chapa
Добавить в конец:Rubi
Добавить в начало:Chipi
Добавить в конец:Raba
Добавить в начало:Chipi
Добавить в конец:Raba
Chipi  Chipi  Chapa  Chapa  Rubi  Rubi  Raba  Raba  
Введие ключевое слово, которое надо удалить: Chipi
Chipi  Chapa  Chapa  Rubi  Rubi  Raba  Raba  
Список пуст
Chipi  Chipi  Chapa  Chapa  Rubi  Rubi  Raba  Raba  
*/
```
