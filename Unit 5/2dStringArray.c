#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    char arr[][10] = {"this","these","the","there","trie"};
    int i = 0;
    while(*arr[i]) {
        printf("%s\n",arr[i]);
        i++;
    }
    return 0;
}