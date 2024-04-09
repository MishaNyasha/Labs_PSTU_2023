#pragma once 
#include "PAIR.h" 
class FRACTION : public PAIR
{
public:
    FRACTION(); 
    ~FRACTION(); 
    FRACTION(int, float); 
    FRACTION(const FRACTION&); 
    int Get_whole_part()
    { 
        return whole_part;
    }
    float Get_not_a_whole_part()
    {
        return not_a_whole_part;
    } 
    void Set_whole_part(int);
    void Set_not_a_whole_part(float);
    FRACTION& operator=(const FRACTION&); 
    friend istream& operator>>(istream& in, FRACTION& l); 
    friend ostream& operator<<(ostream& out, const FRACTION& l); 
    bool operator>(const FRACTION& f);
    bool operator==(const FRACTION& f);
    bool operator<(const FRACTION& f);
protected:
    int whole_part; 
    float not_a_whole_part;
};