#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define ALPHABET_SIZE 26

struct trieNode {
    struct trieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};
typedef struct trieNode Trie;

Trie *createroot(void) {
    Trie *newNode;
    newNode = (Trie *) malloc(sizeof(Trie));
    for(int i = 0; i < ALPHABET_SIZE;i++) {
        newNode->children[i] = NULL;
    }
    newNode->isEndOfWord = 0;
    return newNode;
}

void insert(Trie *root,char *key) {
    
}

int main()
{
    Trie *root;
    root = createRoot();
    char text[][5] = {"this","these","the","there","trie"};
    return 0;
}