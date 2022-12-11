#include<stdio.h>
#include<stdlib.h>
#define Max 10

struct record{
    int key;
    float info;
    struct record *next;
};
typedef struct record Rdata;
int hash_fun(int datakey){
    return datakey%Max;
}
void insert(Rdata *hashtable[]){
    int datakey,index;
    float datainfo;
    Rdata *newnode;
    printf("\n Enter key and info : ");
    scanf("%d %f", &datakey,&datainfo);
    index=hash_fun(datakey);
    newnode=(Rdata *)malloc(sizeof(Rdata));
    newnode->key=datakey;
    newnode->info=datainfo;
    newnode->next=hashtable[index];
    hashtable[index]=newnode;


}
void search(Rdata *hashtable[]){
    int skey, index;
    Rdata *cur;
    printf("\n Enter the record key : ");
    scanf("%d", skey);
    index=hash_fun(skey);
    cur=hashtable[index];
    if(cur==NULL){
        printf("\n Record Not Found ");
        return;
    }
    while(cur!=NULL){
        if(cur->key==skey){
            printf("\n Record Found : %d  %f", cur->key, cur->info);
            return;
        }
        cur=cur->next;
    }

    printf("\n Record Not Found ");
}

void display(Rdata *hashtable[]){
    Rdata *cur;
    for(int i=0;i<Max;i++){
        cur=hashtable[i];
        printf("\n");
        while(cur!=NULL){
            printf("%d  %f", cur->key, cur->info);
            cur=cur->next;

        }
        printf("  NULL");
    }
}
void delet(Rdata *hashtable[]){
    Rdata *cur, *prev;
    int datakey, index;
    printf("\n Enter the key of the record to be deleted : ");
    scanf("%d", &datakey);
    index=hash_fun(datakey);
    cur=hashtable[index];
    prev=hashtable[index];
    if(cur==NULL){
        printf("\n Record not found ");
        return;
    }
    while(cur!=NULL){
        if(cur->key==datakey){
            printf("\n found the record to delete \n");
            if(cur==hashtable[index]){
                hashtable[index]=cur->next;
                free(cur);
                return;
            }
            prev->next=cur->next;
            free(cur);
            return;
        }
        prev=cur;
        cur=cur->next;
    }
    printf("\n found the record to delete \n");
}
int main(){
    Rdata *hashtable[Max];
    int option;
    for(int i=0;i<Max;i++)
        hashtable[i]=NULL;
    while(1){
        printf("\n Hash Table Operations\n");
        printf("\n 1. Insert\n 2. Search\n 3. Delete \n4. Display\n 5. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &option);
        switch(option){
            case 1: insert(hashtable);
                    break;
            case 2: search(hashtable);
                    break;
            case 3: delet(hashtable);
                    break;
            case 4: display(hashtable);
                    break;
            case 5: exit(0);
        }
    }
}