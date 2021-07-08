#include<iostream>
#include<stdlib.h>
#include"Int.h"

int main()
{
    
    Int c=1;
    for(int i=0;i<3000;i++)
    {
        c=c*739;
    }
    std::cout<<c;
}