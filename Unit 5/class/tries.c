#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ALPHABET_SIZE 26
struct trienode{
    struct trienode *children[ALPHABET_SIZE];
    int isEndofWord;
};
typedef struct trienode Trie;
//creates the root of the Trie
Trie *createroot(void){
    Trie *newnode;
    newnode=(Trie *)malloc(sizeof(Trie));
    for(int i=0;i<ALPHABET_SIZE;i++)
        newnode->children[i]=NULL;
    newnode->isEndofWord=0;
    return newnode;
}
//inserts a string into the Trie
void insert(Trie *root,char *key){
    int len;
    int level;
    int index;
    Trie *cur=root;
    len=strlen(key);
    
    for(level=0;level<len;level++){
        index=(int)key[level]-(int)'a';
        if(cur->children[index]==NULL)
            cur->children[index]=createroot();
        cur=cur->children[index];
    }
    cur->isEndofWord=1;

}
//searches for a string in the Trie
void search(Trie *root,char *searchkey){
    int len,index,level;
    len=strlen(searchkey);
    Trie *cur=root;
    for(level=0;level<len;level++){
        index=(int)searchkey[level]-(int)'a';
        if(cur->children[index]==NULL){
            printf("\n The string %s not in the trie ",searchkey);
            return;
        }
        cur=cur->children[index];
    }
    printf("\n String %s is in the trie",searchkey);
}
//return 1 if EndofWord flag is true
int isLeafNode(Trie *root){
    if(root->isEndofWord==1)
        return 1;
    return 0;
}
//displays contents of the Trie (Lexicographic Order)
void display(Trie *root, char *str, int level){   
    if(isLeafNode(root)){
        str[level]='\0';
        printf("\n %s", str);
    }
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]){
            str[level]=i+'a';
            display(root->children[i],str,level+1);
            
        }
    }
}
//displays strings of specified length
void displaylen(Trie *root, char *str, int level, int len){   
    if(isLeafNode(root)){
        str[level]='\0';
        if(level==len)
            printf("\n %s", str);
    }
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]){
            str[level]=i+'a';
            displaylen(root->children[i],str,level+1,len);            
        }
    }
}
//returns 1/ True if all children pointers are pointing to NULL
int isEmpty(Trie *root){
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i])
            return 0;
    }
    return 1;
}
//deletes specified string str from the Trie
Trie * removestring(Trie *root,char str[],int level){
    int len=strlen(str);
    if(!root)
        return NULL;
    if(level==len){
        if(root->isEndofWord==1){
            root->isEndofWord=0;
            if(isEmpty(root))
                free(root);
                return NULL;
        }
        return root;
    }
    int index=(int)str[level]-(int)'a';
    root->children[index]=removestring(root->children[index],str,level+1);
    if(isEmpty(root) && root->isEndofWord==0){
        free(root);
        root=NULL;
    }
    return root;
}
//deletes all strings in the trie
Trie *deleteall(Trie *root){
    if(isEmpty(root)){
        free(root);
        root=NULL;
        return root;
    }
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i])
            root->children[i]=deleteall(root->children[i]);
    }
    return NULL;
}
int ifLastNode(Trie *root){
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i])
            return 0;
    }
    return 1;
}
int autocomplete(Trie *root,char *str){
    int len=strlen(str);
    int index;
    Trie *cur=root;
    int level;
    int isWord,isLast;
    for(level=0;level<len;level++){
        index=(int)str[level]-(int)'a';
        if(cur->children[index]==NULL)
            return -1;
        cur=cur->children[index];
    }
    if(cur->isEndofWord==1)
        isWord=1;
    isLast=ifLastNode(cur);
    if(isLast && isWord){
        printf("%s", str);
        return 0;
    }
    if(isLast==0){
        display(cur,str,len);
        return 1;
    }
}
int main(){
    Trie *root;
    char str[20];
    root=createroot();
    /*char text[][2]={"this","these","the","there","trie"};
    for(int i=0;i<5;i++)
        insert(root,text[i]);*/
    char key[20];
    strcpy(key,"the");
    
    insert(root,key);
    strcpy(key,"this");
    insert(root,key);
    strcpy(key,"these");
    insert(root,key);
    strcpy(key,"trie");
    insert(root,key);
    strcpy(key,"there");
    insert(root,key);
    strcpy(key,"ant");
    insert(root,key);
    strcpy(key,"and");
    insert(root,key);
    strcpy(key,"antenna");
    insert(root,key);
    char searchkey[]="theree";
    search(root,searchkey);
    strcpy(str,"");
    printf("\n Contents of the Trie :\n");
    display(root,str,0);
    printf("\n Strings of length 5:\n");
    strcpy(str,"");
    displaylen(root,str,0,5);
    printf("\n Strings of length 3:\n");
    strcpy(str,"");
    displaylen(root,str,0,3);
    strcpy(str,"antenna");
    removestring(root,str,0);
    printf("\n Trie after Removal of string %s\n", str);
    strcpy(str,"");
    display(root,str,0);
    printf("\n Auto Suggestions\n");
    strcpy(str,"");
    strcpy(str,"the");
    int flag=autocomplete(root,str);

    printf("\n Deleting all strings from the trie\n");
    root=deleteall(root);
    if(root==NULL)
        printf("\n Empty Trie");
    // Recreating the Trie
    printf("\n Recreating the trie\n");
    root=createroot();
    strcpy(key,"ball");
    insert(root,key);
    strcpy(key,"band");
    insert(root,key);
    strcpy(str,"");
    printf("\n Contents of the Trie :\n");
    display(root,str,0);
}