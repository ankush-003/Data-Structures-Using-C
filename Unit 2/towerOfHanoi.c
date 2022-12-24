// for n disks we perform (2^n)-1 operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

void towerOfHanoi(int n,char src,char temp,char dest)
{
    if(n==1)
    {
        printf("Moved 1 from %c to %c\n",src,dest);
    }
    else
    {
        towerOfHanoi(n-1,src,dest,temp);
        printf("Moved %d from %c to %c\n",n,src,dest);
        towerOfHanoi(n-1,temp,src,dest);
    }
}

int main()
{
    int num;
    printf("Enter number of disks: ");
    scanf("%d",&num);
    towerOfHanoi(num,'A','B','C');
    printf("Completed!\n");
    return 0;
}