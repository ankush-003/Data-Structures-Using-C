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

Trie *createRoot(void) {
    Trie *newNode;
    newNode = (Trie *) malloc(sizeof(Trie));
    for(int i = 0; i < ALPHABET_SIZE;i++) {
        newNode->children[i] = NULL;
    }
    newNode->isEndOfWord = 0;
    return newNode;
}

void insert(Trie *root,char *key) {
    int len = strlen(key);
    int level;
    int index;
    Trie *cur = root;

    for(level = 0;level < len;level++) {
        index = (int) key[level] - (int)'a'; // Pointer varies from 0 to 25
        if(cur->children[index] == NULL) {
            cur->children[index] = createRoot();
        }
        cur = cur->children[index];
    }
    cur->isEndOfWord = 1;
}

void search(Trie *root,char *searchkey) {
    int len = strlen(searchkey);
    int index,level;
    Trie *cur = root;
    for(level = 0; level < len;level++) {
        if(cur->children[index] == NULL) {
            printf("The string %s is not in the trie\n",searchkey);
            return;
        }
        cur = cur->children[index];
    }
    printf("String %s is in the trie\n",searchkey);
}

int isLeafNode(Trie *root) {
    return root->isEndOfWord == 1;
}

void display(Trie *root,char *str,int level) {
    Trie *cur;
    
    if(isLeafNode(root)) {
        str[level] = '\0';
        printf("\n%s\n",str);
        return;
    }

    for(int i = 0; i < ALPHABET_SIZE;i++) {
        if(root->children[i]) {
            str[level] = i + 'a';
            display(root->children[i],str,level+1);
            level--;
        }
    }
}

int main()
{
    Trie *root;
    char str[20];
    root = createRoot();
    char text[][5] = {"this","these","the","there","trie"};
    for(int i = 0; i < 5;i++) {
        insert(root,text[i]);
    }
    char searchKey[] = "theree";
    search(root,searchKey);
    display(root,str,0);
    return 0;
}