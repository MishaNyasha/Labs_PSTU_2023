#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool check(char C)
{
    return (C == 'q' || C == 'w' || C == 'r' || C == 't' || C == 'p' || C == 's' ||  C == 'd' || C == 'f' || C == 'g' || C == 'h' || C == 'j' || C == 'k' || C == 'l' || C == 'z' || C == 'x' || C == 'c' || C == 'v' || C == 'b' || C == 'n' || C == 'm');
}
int main()
{
    ifstream file1("F1.txt");
    ofstream file2("F2.txt");
    if(!file1.is_open() && !file2.is_open())
    {
        cout << "error" << endl;
    }
    while(!file1.eof())
    {
        string line;
        getline(file1, line);
        
        stringstream line_stream;
        line_stream.str(line);

        string first_word;
        line_stream >> first_word;

        while(!line_stream.eof())
        {
            string word;
            line_stream >> word;

            if(word == first_word)
            {
                file2 << line << endl;
                break;
            }
        }
    }
    file1.close();
    file2.close();
    
    string prev_line;
    string line;

    ifstream file3("F2.txt");
    
    while(!file3.eof())
    {
        prev_line = line;
        getline(file3, line);
    }
    
    file3.close();

    if(line.length() == 0)
    {
        line = prev_line;
    }
    
    
    int count = 0;
    for(char i : line)
    {
        if(check(i))
        {
            count++;
        }
    }
    cout << "Количество согласных в последней строке файла F2.txt : " << count;
    return 0;
}
/*
Количество согласных в последней строке файла F2.txt : 15
*/
