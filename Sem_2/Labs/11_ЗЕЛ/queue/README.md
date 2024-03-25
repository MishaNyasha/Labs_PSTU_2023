# 1) Код программы
```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node
{
    char* key;
    Node* pointer_to_next_node = nullptr;
    Node* pointer_to_previous_node = nullptr;
};

Node* create_Node(const char* key)
{
    Node* new_Node = new Node;
    new_Node->key = new char[strlen(key) + 1];
    strcpy(new_Node->key, key);
    new_Node->pointer_to_next_node = nullptr;
    new_Node->pointer_to_previous_node = nullptr;
    return new_Node;
}

void prin_queue(Node* head_node)
{
    if (head_node == nullptr)
    {
        cout << "Очередь пуста" << endl;
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
void add_element_to_begin(Node*& head_node, Node*& tail_node, const char* key)
{
    Node* new_Node = create_Node(key);
    if (head_node == nullptr)
    {
        head_node = new_Node;
        tail_node = new_Node;
    }
    else
    {
        new_Node->pointer_to_next_node = head_node;
        head_node->pointer_to_previous_node = new_Node;
        head_node = new_Node;
    }
}

void add_element_to_end(Node*& head_node, Node*& tail_node, const char* key)
{
    Node* new_Node = create_Node(key);
    if (head_node == nullptr)
    {
        head_node = new_Node;
        tail_node = new_Node;
    }
    else
    {
        tail_node->pointer_to_next_node = new_Node;
        new_Node->pointer_to_previous_node = tail_node;
        tail_node = new_Node;
    }
}

void delete_element(Node*& head_node, Node*& tail_node, const char* key)
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
            Node* temp = current_node;
            if (current_node->pointer_to_previous_node != nullptr)
            {
                current_node->pointer_to_previous_node->pointer_to_next_node = current_node->pointer_to_next_node;
            }
            if (current_node->pointer_to_next_node != nullptr)
            {
                current_node->pointer_to_next_node->pointer_to_previous_node = current_node->pointer_to_previous_node;
            }
            if (head_node == current_node)
            {
                head_node = current_node->pointer_to_next_node;
            }
            if (tail_node == current_node)
            {
                tail_node = current_node->pointer_to_previous_node;
            }
            current_node = current_node->pointer_to_next_node;
            delete[] temp->key;
            delete temp;
        }
        else
        {
            current_node = current_node->pointer_to_next_node;
        }
    }
}

void write_queue_in_file(Node* head_node)
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

void destroy_queue(Node*& head_node, Node*& tail_node)
{
    while (head_node != nullptr)
    {
        Node* temp = head_node;
        head_node = head_node->pointer_to_next_node;
        delete[] temp->key;
        delete temp;
    }
    head_node = nullptr;
    tail_node = nullptr;
}

Node* restore_queue_from_file()
{
    Node* head_node = nullptr;
    Node* tail_node = nullptr;
    ifstream file("file");
    if (!file)
    {
        cout << "Ошибка открытия файла." << endl;
        return head_node;
    }
    string key;
    while (getline(file, key))
    {
        add_element_to_end(head_node, tail_node, key.c_str());
    }
    file.close();
    return head_node;
}

int main()
{
    Node* head_node = nullptr;
    Node* tail_node = nullptr;
    cout << "Сколько K элементов добавить в начало и конец?" << endl;
    int k;
    cin >> k;
    cout << "Введите элементы:" << endl;
    char S[255];
    cin.getline(S, 255);
    for (int i = 0; i < k; i++)
    {
        cout << "Добавить в конец:";
        cin.getline(S, 255);
        add_element_to_end(head_node, tail_node, S);
        cout << "Добавить в начало:";
        cin.getline(S, 255);
        add_element_to_begin(head_node, tail_node, S);
    }
    prin_queue(head_node);
    write_queue_in_file(head_node);
    
    cout << "Введие ключевое слово, которое надо удалить: ";
    char LL[255];
    cin.getline(LL, 255);
    
    delete_element(head_node, tail_node, LL);
    
    prin_queue(head_node);
    destroy_queue(head_node, tail_node);
    
    prin_queue(head_node);
    head_node = restore_queue_from_file();
    
    prin_queue(head_node);
    destroy_queue(head_node, tail_node);
    return 0;
}
```
# 2) Блок-схема
 <image src ="11_ЗЕЛ_main.png">
  <image src ="11_ЗЕЛ_add_element_to_end.png">
   <image src ="11_ЗЕЛ_create_Node.png">
    <image src ="11_ЗЕЛ_delete_element.png">
     <image src ="11_ЗЕЛ_destroy_queue.png">
       <image src ="11_ЗЕЛ_prin_queue.png">
        <image src ="11_ЗЕЛ_restore_queue_from_file.png">
         <image src ="11_ЗЕЛ_struct_Node.png">
          <image src ="11_ЗЕЛ_write_queue_in_file.png">
      
# 3) Тесты
```cpp
/*

    Test 1
Сколько K элементов добавить в начало и конец?
3
Введите элементы:
Добавить в конец:sss
Добавить в начало:rrrr
Добавить в конец:zzz
Добавить в начало:sss
Добавить в конец:sss
Добавить в начало:rrr
rrr  sss  rrrr  sss  zzz  sss  
Введие ключевое слово, которое надо удалить: sss
rrr  rrrr  zzz  
Очередь пуста
rrr  sss  rrrr  sss  zzz  sss
    
    Test 2
Сколько K элементов добавить в начало и конец?
2
Введите элементы:
Добавить в конец:ss
Добавить в начало:pp
Добавить в конец:zz
Добавить в начало:mm
mm  pp  ss  zz  
Введие ключевое слово, которое надо удалить: zz
mm  pp  ss  
Очередь пуста
mm  pp  ss  zz  

    Test 3
Сколько K элементов добавить в начало и конец?
15
Введите элементы:
Добавить в конец:q
Добавить в начало:w
Добавить в конец:e
Добавить в начало:r
Добавить в конец:t
Добавить в начало:y
Добавить в конец:u
Добавить в начало:i
Добавить в конец:o
Добавить в начало:p
Добавить в конец:a
Добавить в начало:s
Добавить в конец:d
Добавить в начало:f
Добавить в конец:g
Добавить в начало:h
Добавить в конец:j
Добавить в начало:k
Добавить в конец:l
Добавить в начало:z
Добавить в конец:x
Добавить в начало:c
Добавить в конец:v
Добавить в начало:b
Добавить в конец:n
Добавить в начало:m
Добавить в конец:pop
Добавить в начало:pop
Добавить в конец:pop
Добавить в начало:pop
pop  pop  m  b  c  z  k  h  f  s  p  i  y  r  w  q  e  t  u  o  a  d  g  j  l  x  v  n  pop  pop  
Введие ключевое слово, которое надо удалить: pop
m  b  c  z  k  h  f  s  p  i  y  r  w  q  e  t  u  o  a  d  g  j  l  x  v  n  
Очередь пуста
pop  pop  m  b  c  z  k  h  f  s  p  i  y  r  w  q  e  t  u  o  a  d  g  j  l  x  v  n  pop  pop  
*/
```
