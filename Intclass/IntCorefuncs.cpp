#include<iostream>
#include<stdlib.h>
#include<string>
#include"IntCorefuncs.h"
namespace IntInsidefuncs
{
   

std::string func(std::string num1,std::string num2)
{
    
    std::string num3="";
    int count=std::max(num1.length(),num2.length());
    int alen=num1.length();
    int blen=num2.length();
    int atemp;
    int btemp;
    int carry=0;
    for (int i = 0; i < count+1; i++)
    {
        if(alen-i-1>=0)
            atemp=num1[alen-i-1]-48;
        else
            atemp=0;
        if(blen-i-1>=0)
            btemp=num2[blen-i-1]-48;
        else
            btemp=0;


        num3.push_back((char)((atemp+btemp+carry)-((atemp+btemp+carry)/10)*10+48));
        carry=(atemp+btemp+carry)/10;
        
    }
    if(num3.length()>1 && num3[num3.length()-1]=='0')
        num3.pop_back();
    
    int len=num3.length();

    for (int i = 0; i < len/2; i++)
    {
        std::swap(num3[i],num3[len-i-1]);
    }
    
    return num3;
}

bool funcGrater(std::string num1,std::string num2,bool Isequal)
{
    int alen=num1.length();
    int blen=num2.length();
    

    bool AIsGreater=false;
    int i=0;
    if(alen!=blen)
        AIsGreater=(alen>blen);
    else
    {
        for (i = 0; i < alen; i++)
        {
            if(num1[i]!=num2[i])   
            {
                AIsGreater=(num1[i]>num2[i]);
                break;
            }    
        }
        if(Isequal)
        {
            if(i==alen)
                AIsGreater=true;
        }
    }
    return AIsGreater;
}

std::string funcsub(std::string num1,std::string num2)
{
    std::string num3="";
    int alen=num1.length();
    int blen=num2.length();
    int atemp,btemp;

    bool AIsGreater=funcGrater(num1,num2,false);

    
    int carry=0;
    if(AIsGreater)
    {
        for (int i = 0; i < alen; i++)
        {
            atemp=num1[alen-i-1]-48;
            if(blen-i-1<0)
                btemp=0;
            else
                btemp=num2[blen-i-1]-48;
            if(atemp-btemp+carry<0 && atemp-btemp+carry>=-10)
            {
                num3.push_back(atemp-btemp+carry+10+48);
                carry=-1;
            }
            else if(atemp-btemp+carry>=0)
            {
                num3.push_back(atemp-btemp+carry+48);
                carry=0;
            }
            else if(atemp-btemp+carry<-10 && atemp-btemp+carry>=-20)
            {
                num3.push_back(atemp-btemp+carry+20+48);
                carry=-2;
            }


        }
        int len=num3.length();

        for (int i = 0; i < len/2; i++)
        {
            std::swap(num3[i],num3[len-i-1]);
        }
       
    }
    else
        num3="0";


    
    int len=num3.length();
    int l=0;
    for ( l = 0; l < len; l++)
    {
        if(num3[l]!='0')
        {
            break;
        }
    }
   
    if(l==len)
        num3="0";
    else
        num3=num3.substr(l,len-l);

    return num3;

}

std::string funcMul(std::string num1,std::string num2)
{
    std::string temp="";
    std::string num3="0";
    int alen=num1.length();
    int blen=num2.length();
    int carry=0;
    int atemp;
    int btemp;
    int len;
    for (int i = 0; i < blen; i++)
    {
        btemp=num2[blen-i-1]-48;
        carry=0;
        temp="";
        for(int j=alen-1;j>-2;j--)
        {
            if(j<0)
                atemp=0;
            else
                atemp=num1[j]-48;
            
            temp.push_back((char)((atemp*btemp+carry)-((atemp*btemp+carry)/10)*10+48));
            carry=(atemp*btemp+carry)/10;
        }
        if(temp.length()>1 && temp[temp.length()-1]=='0')
            temp.pop_back();
        len=temp.length();
        for (int i = 0; i < len/2; i++)
        {
            std::swap(temp[i],temp[len-i-1]);
        }
        for (int j = 0; j < i; j++)
            temp.push_back('0');
        
        num3=func(temp,num3);
        
    }
    
    len=num3.length();
    int l=0;
    for (l = 0; l < len; l++)
    {
        if(num3[l]!='0')
            break;
    }
    
    if(l==len)
    {
        num3="0";
    }
    else
    {
        num3=num3.substr(l,len-l);
    }
    return num3;
}

std::string funcDiv(std::string num1,std::string num2)
{
    if(num2=="0")
        return "0";
    int alen=num1.length();
    int blen=num2.length();
    std::string substr="";
    std::string temp="";
    std::string num3="";
    int j=0;
    for (int i = 0; i < alen; i++)
    {
        if(substr=="0")
            substr="";
        substr.push_back(num1[i]);
        
        for(j=9;j>-1;j--)
        {
            temp="";
            temp.push_back(j+48);
            temp=funcMul(num2,temp);
            
            if(funcGrater(substr,temp,true))
                break;
        }
        substr=funcsub(substr,temp);
        num3.push_back(j+48);

    }
    int len=num3.length();
    int l=0;
    for (l = 0; l < len; l++)
    {
        if(num3[l]!='0')
            break;
    }
    if(l==len)
        num3=num3.substr(len-1,1);
    else
        num3=num3.substr(l,len-l);
    return num3;

}

}