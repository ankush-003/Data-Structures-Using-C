#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct trie {
    struct trie *child[26];
    int endOfWord;
}Trie;

Trie *createNode()
{
    Trie *newNode = (Trie *)malloc(sizeof(Trie));
    newNode->endOfWord = 0;
    for (int i = 0; i < 26; i++)
        newNode->child[i] = NULL;
    return newNode;
}

void insert(Trie *root, char *word) {
    Trie *cur = root;
    while(*word) {
        if(cur->child[*word - 'a'] == NULL)
            cur->child[*word - 'a'] = createNode();
        cur = cur->child[*word - 'a'];
        word++;    
    }
    cur->endOfWord = 1;
}



int search(Trie *root, char *word) {
    Trie *cur = root;
    while(*word) {
        if(cur->child[*word - 'a'] == NULL)
            return 0;
        cur = cur->child[*word - 'a'];
        word++;    
    }
    return cur->endOfWord;
}

int isEmpty(Trie *root) {
    for (int i = 0; i < 26; i++)
        if (root->child[i])
            return 0;
    return 1;
}

Trie* delete(Trie *root, char *str, int level, int len) {
    // recursive function to delete a string from trie
    if(root == NULL) {
        return root;
    }
    if(level == len) {
        if(root->endOfWord) {
            root->endOfWord = 0;
        }
        if(isEmpty(root)) {
            free(root);
            root = NULL;
        }
        return root;
    }
    int index = str[level] - 'a';
    root->child[index] = delete(root->child[index], str, level + 1, len);
    if(isEmpty(root) && root->endOfWord == 0) {
        free(root);
        root = NULL;
    }
    return root;
}

void display(Trie *root, char *str, int level) {
    if(root->endOfWord) {
        str[level] = '\0';
        printf("%s\n", str);
    }

    for(int i = 0; i < 26; i++) {
        if(root->child[i]) {
            str[level] = i + 'a';
            display(root->child[i], str, level + 1);
        }
    }
}

int main()
{
    Trie *root = createNode();
    // insert(root, "hello");
    insert(root, "apple");
    insert(root, "app");
    insert(root, "apples");
    char word[20];
    printf("Enter word to search: ");
    scanf("%s", word);
    if(search(root, word))
        printf("Word found in trie\n");
    else
        printf("Word not found in trie\n");    
    return 0;
}