#include <stdio.h>
#include<stdlib.h>
#define SIZE 13

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 11 - (key % 11);
}

int isFull(int *hashTable) {
    int numKeys = 0, i = 0;
    while(i < SIZE) {
        if(hashTable[i]) {
            numKeys++;
        }
        i++;
    }
    return numKeys == SIZE;
}

void insertIntoHash(int key, int *hashtable)
{
    if(isFull(hashtable)) {
        printf("-1\n");
        return;
    }
    int collision = 0;
    int index = hash1(key);
    int inserted = 0;
    while(!inserted) {
        if(hashtable[index]==0) {
            hashtable[index] = key;
            inserted = 1;
        }
        else {
            collision++;
            index = (hash1(key) + collision * hash2(key)) % SIZE;
        }
    }
}

void printHashTable(int *hashtable)
{
    for(int i = 0; i < SIZE;i++) {
        printf("%d ",hashtable[i]);
    }
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}
