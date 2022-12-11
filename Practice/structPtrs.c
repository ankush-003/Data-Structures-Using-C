#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct element {
    int data;
    int priority;    
};
typedef struct element element;

void display(element *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d %d\n", array[i].data, array[i].priority);
    }
}


int main()
{
    element *array = (element *)malloc(sizeof(element) * 5);
    // error: invalid conversion from ‘void*’ to ‘element*’
    // for(int i = 0; i < 5;i++){
    //     array[i] = NULL;
    // }
    return 0;
}