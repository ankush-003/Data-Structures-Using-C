#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int arr[10] = {1,2,3,4,5};
    // shift
    for(int i = 0; i < 10; i++) {
        arr[i] = arr[i+1];
    }
    return 0;
}