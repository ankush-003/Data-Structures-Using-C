#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

int factorial(int num)
{
    if(num == 1)
        return 1;
    else    
        return num * factorial(num-1);    
}

int multiply(int a,int b)
{
    if(b==1)
        return a;
    else
        return (multiply(a,b-1)) + a;    
}

int fib(int n)
{
    if ( (n==0) || (n==1))
        return n;
    int x,y;    
    x= fib(n-1) ;
    y= fib(n-2);
    return x+y;
}

// Recursive function to display the elements of the linked list in the reverse
// order
// int display(struct node *p)
// {
// if(p->next!=NULL)
// display(p->next)
// printf(“%d “,p->data);
// }

int sum(int *a, int n)
//a is pointer to the array, n is the index of the last element of the array
{
    int s;
    if(n==0) // base condition
        return a[0];
    s= sum(a,n-1) + a[n]; // compute sum of n-1 elements and add the nth element
    return s;
}

int main()
{
    int num,res;
    /*
    // factorial
    printf("Enter Number to find Factorial: ");
    scanf("%d",&num);
    res = factorial(num);
    printf("factorial of %d is %d\n",num,res);

    int num2;
    printf("Enter numbers to Multiply: ");
    scanf("%d%d",&num,&num2);
    res = multiply(num,num2);
    printf("result: %d\n",res);*/
    printf("Enter index of Fibonacci sequence: ");
    scanf("%d",&num);
    printf("Element is %d\n",fib(num));

    return 0;
}