# 1) Код программы
```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct node
{
    char* key;
    node* pointer_to_prev_node = nullptr;
};

node* create_node(const char* key)
{
    node* new_node = new node;
    new_node->key = new char[strlen(key) + 1];
    strcpy(new_node->key, key);
    new_node->pointer_to_prev_node = nullptr;
    return new_node;
}
void print_list(node* head_node)
{
    if (head_node == nullptr)
    {
        cout << "Стек пуст" << endl;
        return;
    }
    node* current_node = head_node;
    while (current_node != nullptr)
    {
        cout << current_node->key << "  ";
        current_node = current_node->pointer_to_prev_node;
    }
    cout << endl;
}
void add_element_to_start(node*& head_node, const char* key)
{
    node* new_node = create_node(key);
    if (head_node == nullptr)
    {
        head_node = new_node;
    }
    else
    {
        new_node->pointer_to_prev_node = head_node;
        head_node = new_node;
    }
}
void add_element_to_end(node*& head_node, const char* key)
{
    node* new_node = create_node(key);
    if (head_node == nullptr)
    {
        head_node = new_node;
    }
    else
    {
        node* current_node = head_node;
        while (current_node->pointer_to_prev_node != nullptr)
        {
            current_node = current_node->pointer_to_prev_node;
        }
        current_node->pointer_to_prev_node = new_node;
    }
}
void delete_elem(node*& head_node, const char* key)
{
    if (head_node == nullptr)
    {
        return;
    }
    
    node* current_node = head_node;
    node* prev_node = nullptr;
    
    while (current_node != nullptr)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            if (prev_node == nullptr)
            {
                head_node = current_node->pointer_to_prev_node;
            }
            else
            {
                prev_node->pointer_to_prev_node = current_node->pointer_to_prev_node;
            }

            delete[] current_node->key;
            delete current_node;
            
            break;
        }
        
        prev_node = current_node;
        current_node = current_node->pointer_to_prev_node;
    }
}

void write_stack_in_file(node* head_node)
{
    ofstream file("file");
    if (!file)
    {
        cout << "Ошибка открытия файла." << endl;
        return;
    }
    node* current_node = head_node;
    while (current_node != nullptr)
    {
        file << current_node->key << endl;
        current_node = current_node->pointer_to_prev_node;
    }
    file.close();
}
void destroy_stack(node*& head_node)
{
    node* current_node = head_node;
    while (current_node != nullptr)
    {
        node* temp = current_node;
        current_node = current_node->pointer_to_prev_node;
        delete[] temp->key;
        delete temp;
    }
    head_node = nullptr;
}
node* restore_stack_from_file()
{
    node* head_node = nullptr;
    ifstream file("file");
    if (!file)
    {
        cout << "Ошибка открытия файла." << endl;
        return head_node;
    }
    string STR;
    while (getline(file, STR))
    {
        add_element_to_end(head_node, STR.c_str());
    }
    file.close();
    return head_node;
}
int main()
{
    node* head_node = nullptr;
    cout << "Сколько элементов добавить в стек?" << endl;
    int k;
    cin >> k;
    cin.ignore();
    cout << "Введите элементы:" << endl;
    char s[255];
    for (int i = 0; i < k; i++)
    {
        cout << "Добавить элемент в начало:";
        cin.getline(s, 255);
        add_element_to_start(head_node, s);
        cout << "Добавить элемент в конец:";
        cin.getline(s, 255);
        add_element_to_end(head_node, s);
    }
    
    print_list(head_node);
    
    write_stack_in_file(head_node);
    
    cout << "удалить элемент с ключевым словом: ";
    char LL[255];
    cin.getline(LL, 255);
    delete_elem(head_node, LL);
    print_list(head_node);
    destroy_stack(head_node);
    print_list(head_node);
    
    head_node = restore_stack_from_file();
    print_list(head_node);
    destroy_stack(head_node);
    
    return 0;
}
```
# 2) Блок-схема
 <image src ="11_ЗЕЛ_add_element_to_end.png">
  <image src ="11_ЗЕЛ_add_element_to_start.png">
   <image src ="11_ЗЕЛ_create_node.png">
    <image src ="11_ЗЕЛ_delete_elem.png">
     <image src ="11_ЗЕЛ_destroy_stack.png">
       <image src ="11_ЗЕЛ_main.png">
        <image src ="11_ЗЕЛ_print_list.png">
         <image src ="11_ЗЕЛ_restore_stack_from_file.png">
          <image src ="11_ЗЕЛ_struct_node.png">
             <image src ="11_ЗЕЛ_write_list_in_file.png">
      
# 3) Тесты
```cpp
/*
    Test 1
Сколько элементов добавить в стек?
2
Введите элементы:
Добавить элемент в начало:sss
Добавить элемент в конец:rrr
Добавить элемент в начало:ttt
Добавить элемент в конец:qqq
ttt  sss  rrr  qqq  
удалить элемент с ключевым словом: rrr
ttt  sss  qqq  
Стек пуст
ttt  sss  rrr  qqq

    Test 2
Сколько элементов добавить в стек?
3
Введите элементы:
Добавить элемент в начало:q
Добавить элемент в конец:w
Добавить элемент в начало:e
Добавить элемент в конец:r
Добавить элемент в начало:t
Добавить элемент в конец:y
t  e  q  w  r  y  
удалить элемент с ключевым словом: w
t  e  q  r  y  
Стек пуст
t  e  q  w  r  y  

    Test 3
Сколько элементов добавить в стек?
2
Введите элементы:
Добавить элемент в начало:1111
Добавить элемент в конец:3333
Добавить элемент в начало:2222
Добавить элемент в конец:4444
2222  1111  3333  4444  
удалить элемент с ключевым словом: 1111
2222  3333  4444  
Стек пуст
2222  1111  3333  4444  
*/
```
