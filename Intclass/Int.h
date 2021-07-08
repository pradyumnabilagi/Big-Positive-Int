#pragma once
class Int
{
private:

    std::string Integer;
public:
    Int();
    Int(unsigned int );
    Int(std::string);
    friend std::ostream& operator<<(std::ostream&,Int);
    friend std::istream& operator>>(std::istream&,Int&);
    
    friend bool operator==(Int,Int);
    friend bool operator>(Int,Int);
    friend bool operator<(Int,Int);
    friend bool operator>=(Int,Int);
    friend bool operator<=(Int,Int);
    friend bool operator!=(Int,Int);

    friend Int operator+(Int ,Int );
    friend Int operator-(Int ,Int );
    friend Int operator*(Int ,Int );
    friend Int operator/(Int ,Int );
    
    friend Int operator+=(Int&,Int);
    friend Int operator-=(Int&,Int);
    friend Int operator*=(Int&,Int);
    friend Int operator/=(Int&,Int);

    Int operator++();
    Int operator++(int);
    Int operator--();
    Int operator--(int);
    std::string GetStringVal();
};



