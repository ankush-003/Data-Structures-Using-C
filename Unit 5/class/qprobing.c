#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Tsize 10
void insert(int htable[],int ele){
    int i,pos;
    for(i=0;i<Tsize;i++){
        pos=(ele+i*i)%Tsize;
        if(htable[pos]==-1){
            htable[pos]=ele;
            return;
        }


    }
    printf("\n Hash table is full...Insert failed\n");

}
void search(int htable[],int ele){
    int pos;
    for(int i=0;i<Tsize;i++){
        pos=(ele+i*i)%Tsize;
        if(ele==htable[pos]){
            printf("\n Element found at %d",pos);
            return;
        }
    }
    printf("\n Element not in Htable");

}
void delet(int htable[],int ele){
    int pos;
    for(int i=0;i<Tsize;i++){
        pos=(ele+i*i)%Tsize;
        if(ele==htable[pos]){
            printf("\n Element deleted from Htable");
            htable[pos]=-1;
            return;
        }
    }
    printf("\n Element not in Htable..cannot delete");

}
void print(int htable[]){
    for(int i=0;i<Tsize;i++){
        printf("\n%d %d", i,htable[i]);
    }

}
int main(){
    int htable[Tsize];
    int option,ele;
    for(int i=0;i<Tsize;i++)
        htable[i]=-1;  
    
    while(1){
        printf("\n Hash Table Operations:\n");
        printf("1. Insert\n2.Search\n3.Delete\n4.Display\n5.Exit ");
        printf("\n Enter your option:  ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("\n Enter the element to be inserted: ");
                    scanf("%d", &ele);
                    insert(htable,ele);
                    break;
            case 2: printf("\n Enter the element to be Searched: ");
                    scanf("%d", &ele);
                    search(htable,ele);
                    break;
            case 3: printf("\n Enter the element to be deleted: ");
                    scanf("%d", &ele);
                    delet(htable,ele);
                    break;
            case 4: print(htable);
                    break;
            case 5: exit(0);


        }

    }
}

