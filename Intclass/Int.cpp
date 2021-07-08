#include<iostream>
#include<stdlib.h>
#include<string>
#include"Int.h"
#include"IntCorefuncs.h"

using namespace IntInsidefuncs;


Int::Int()
{
    
    this->Integer="0";
    
}
Int::Int(unsigned int Int)
{
    char temp;
    if(Int==0)
        this->Integer="0";
    else
        this->Integer="";
    while(Int!=0)
    {
        temp=Int-(Int/10)*10+48 ;
        
        Integer.push_back(temp);        
        Int=Int/10;
    }
    
    
    int len=Integer.length();
    for (int i = 0; i < len/2; i++)
    {
        std::swap(Integer[i],Integer[len-i-1]);
    }
    
}
Int::Int(std::string Int)
{
    int i=0;
    if(Int=="")
        Integer="0";
    for (i = 0; i < Int.length(); i++)
    {
        if(Int[i]<48 || Int[i]>57)
            break;
    }
    if(i!=Int.length())
        Integer="0";
    else
    {
        for (i = 0; i < Int.length(); i++)
        {
            if(Int[i]!='0')
                break;   
        }
        if(i!=Int.length())
            Integer=Int.substr(i,Int.length()-i);
        else
            Integer="0";
    }
}






Int operator+(Int a,Int b)
{
    Int c;
    std::string num1=a.Integer;
    std::string num2=b.Integer;
    c.Integer=func(num1,num2);
    
    return c;
}




std::ostream& operator<<(std::ostream& os,Int I)
{
    os<<I.Integer;
    return os;
}

std::istream& operator>>(std::istream& is,Int& I)
{
    std::string temp;
    int i=0;
    
    is>>temp;
    for ( i = 0; i < temp.length(); i++)
    {
        if(temp[i]<48 || temp[i]>57)
            break;
    }
    if(i != temp.length())
    {
        I.Integer="0";
    }
    else
    {
        for (i = 0; i < temp.length(); i++)
        {
            if(temp[i]!='0')
                break;   
        }
        if(i!=temp.length())
            I.Integer=temp.substr(i,temp.length()-i);
        else
            I.Integer="0";
    }
    return is;
}




bool operator==(Int a,Int b)
{
    return a.Integer==b.Integer;
}






Int Int::operator++(int)
{
    Int temp;
    temp.Integer=Integer;
    *(this)=*(this)+1;
    return temp;
}


Int Int::operator++()
{
    Int temp;
    *(this)=*(this)+1;
    temp.Integer=Integer;
    return temp;
}

Int operator-(Int a,Int b)
{
    Int c;
    std::string num1=a.Integer;
    std::string num2=b.Integer;
    c.Integer=funcsub(num1,num2);

    return c;
    
}





Int operator*(Int a,Int b)
{
    Int c;
    c.Integer=funcMul(a.Integer,b.Integer);
    return c;
}




Int operator/(Int a,Int b)
{
    Int c;
    c.Integer=funcDiv(a.Integer,b.Integer);
    return c;
}

Int operator+=(Int& a,Int b)
{
    Int c;
    c.Integer=func(a.Integer,b.Integer);
    a.Integer=c.Integer;
    return c;
}

Int operator-=(Int& a,Int b)
{
    Int c;
    c.Integer=funcsub(a.Integer,b.Integer);
    a.Integer=c.Integer;
    return c;
}

Int operator*=(Int& a,Int b)
{
    Int c;
    c.Integer=funcMul(a.Integer,b.Integer);
    a.Integer=c.Integer;
    return c;
}

Int operator/=(Int& a,Int b)
{
    Int c;
    c.Integer=funcDiv(a.Integer,b.Integer);
    a.Integer=c.Integer;
    return c;
}



Int Int::operator--()
{
    Int temp;
    *(this)=*(this)-1;
    temp.Integer=Integer;
    return temp;
}   
Int Int::operator--(int)
{
    Int temp;
    temp.Integer=Integer;
    *(this)=*(this)-1;
    return temp;
} 

bool operator>(Int a,Int b)
{
    bool c;
    c=funcGrater(a.Integer,b.Integer,false);
    return c;
}
bool operator<(Int a,Int b)
{
    return funcGrater(b.Integer,a.Integer,false);
}

bool operator>=(Int a,Int b)
{
    return funcGrater(a.Integer,b.Integer,true);
}

bool operator<=(Int a,Int b)
{
    return funcGrater(b.Integer,a.Integer,true);
}
bool operator!=(Int a,Int b)
{
    return a.Integer!=b.Integer;
}

std::string Int::GetStringVal()
{
    return Integer;
}