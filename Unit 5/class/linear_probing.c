#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 20

struct dataitem{
    int key;
    float var;
    char info[10];
};
typedef struct dataitem Record;
int hash_fun(int newkey){
    return newkey%Max;
}
void insert(Record hashtable[]){
    int index;
    int newkey;
    float newvar;
    char newinfo[10];
    printf("\n Enter the key of the new record to be inserted :");
    scanf("%d", &newkey);
    printf("\n Enter new var and info");
    scanf("%f %s", &newvar,newinfo);
    index=hash_fun(newkey);
    for(int i=0;i<Max;i++){
        if(hashtable[index].key==-1){
            hashtable[index].key=newkey;
            hashtable[index].var=newvar;
            strcpy(hashtable[index].info, newinfo);
            return;
        }
        index=(index+i)%Max;
    }
    printf("\n Hash Table is full..cannot insert\n");
}
void search(Record hashtable[]){
    int searchkey;
    int index;
    printf("\n Enter the key of the record to be searched : ");
    scanf("%d", &searchkey);
    index=hash_fun(searchkey);
    if(hashtable[index].key==searchkey){
        printf("\n Record Found\n");
        printf("%d  %f  %s", hashtable[index].key, hashtable[index].var, hashtable[index].info);
        return;
    }
    for(int i=1;i<Max;i++){
        index=(index+i)%Max;
        if(hashtable[index].key==searchkey){
            printf("\n Record Found\n");
            printf("%d  %f  %s", hashtable[index].key, hashtable[index].var, hashtable[index].info);
         return;
        }
    }
    printf("\n Record Not Found\n");
}
void delet(Record hashtable[]){
    int dkey;
    int index;
    printf("\n Enter the key of the record to be deleted : ");
    scanf("%d", &dkey);
    index=hash_fun(dkey);
    for(int i=0;i<Max;i++){
        index=(index+i)%Max;
        if(hashtable[index].key==dkey){
            printf("\n Record deleted");
            hashtable[index].key=-1;
            return;
        }
    }
    printf("\n Record not found\n");
}
void display(Record hashtable[]){
    for(int i=0;i<Max;i++){
        if(hashtable[i].key!=-1)
            printf("\n %d  %f  %s", hashtable[i].key, hashtable[i].var, hashtable[i].info);
        else
            printf("\n-1");

    }
}
int main(){
    Record hashtable[Max];
    int option;
    for(int i=0;i<Max;i++){
        hashtable[i].key=-1;
    }
    while(1){
        printf("\n Linear Probing\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n 5. Exit\n");
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