#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
struct Record 
{
    string name;
    string birth_date;
    string passport_number;
    Record* next;
};
class HashTable 
{
private:
    static const int TABLE_SIZE = 100;
    Record* table[TABLE_SIZE];

    int hashFunction(string key) 
    {
        double A = 0.6180339887;
        int hash = floor(TABLE_SIZE * fmod(stod(key) * A, 1));
        return hash;
    }
public:
    HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            table[i] = nullptr;
        }
    }
    void insertRecord(Record* record) 
    {
        int hash = hashFunction(record->birth_date);
        record->next = table[hash];
        table[hash] = record;
    }
    void deleteRecord(string key) 
    {
        int hash = hashFunction(key);
        Record* current = table[hash];
        Record* prev = nullptr;
        while (current != nullptr) 
        {
            if (current->birth_date == key) 
            {
                if (prev == nullptr) 
                {
                    table[hash] = current->next;
                } 
                else 
                {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }
    void saveToFile(string filename) 
    {
        ofstream file(filename);
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            Record* current = table[i];
            while (current != nullptr)
            {
                file << "name = " << current->name << endl << "year = " << current->birth_date << endl << "pass = " << current->passport_number << "\n---------------------------------------\n";
                current = current->next;
            }
        }
        file.close();
    }
    void loadFromFile(string filename) 
    {
        ifstream file(filename);
        if (file.is_open()) 
        {
            Record record;
            while (file >> record.name >> record.birth_date >> record.passport_number) 
            {
                Record* newRecord = new Record;
                newRecord->name = record.name;
                newRecord->birth_date = record.birth_date;
                newRecord->passport_number = record.passport_number;
                insertRecord(newRecord);
            }
            file.close();
        }
    }
    void displayCollisions() 
    {
        int table_sizes[] = {40, 75, 90};
        for (int size : table_sizes) 
        {
            int collisions = 0;
            for (int i = 0; i < size; i++) 
            {
                Record* current = table[i];
                if (current != nullptr) 
                {
                    int count = 0;
                    while (current != nullptr) 
                    {
                        count++;
                        current = current->next;
                    }
                    if (count > 1) 
                    {
                        collisions += count - 1;
                    }
                }
            }
            cout << "Number of collisions for table size " << size << ": " << collisions / 2 << endl;
        }
    }
};
string GenerateName()
{
    const int N = 9;
    string s;
    for (int j = 0; j < N - 1; j++)
        s += 'a' + rand()%26;
    return s;
}
int main() 
{
    srand(time(0));
    HashTable ht;
    for (int i = 0; i < 100; i++) 
    {
        Record* record = new Record;
        record->name = GenerateName() + '_' + GenerateName() + '_' + GenerateName();
        record->birth_date = to_string(1950 + rand() % 70);
        record->passport_number = "PASS №" + to_string(rand() % 1000000);
        record->next = nullptr;
        ht.insertRecord(record);
    }
    ht.saveToFile("records.txt");
    HashTable ht2;
    ht2.loadFromFile("records.txt");
    ht2.displayCollisions();
    return 0;
}
