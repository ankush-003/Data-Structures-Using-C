#include <stdio.h>
#include <stdlib.h>

int fact(int n) { // Non Tail Recursive Call
    if(n==1)
        return n;
    return n*fact(n-1);    
}

int fact1(int n,int a) { // Tail Recursive call
    if(n==1)
        return a;
    return fact1(n-1,n*a); // better memory utilization as previous stack frame can be deleted  
}

int main()
{
    
}