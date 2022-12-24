#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFront(node **head,int data) {
    node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d at front\n",data);
}

void insertRear(node **head, int data) {
    node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        node *cur = *head;
        while(cur->next !=NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->prev = cur;
    }
    printf("Inserted %d at rear!\n",data);
}

void insertAt(node **head, int data, int pos) {
    node *newNode = createNode(data);
    if(*head == NULL) {
        printf("List is empty!\n");
        *head = newNode;
    } else {
        node *cur = *head;
        // position starts from 1
        for(int i = 1; (i < pos-1) && cur;i++) {
            cur = cur->next;
        }
        if(cur == NULL) {
            printf("Invalid position!\n");
            printf("Inserting at the end of the list!\n");
            insertRear(head,data);
        } else {
            newNode->next = cur->next;
            cur->next = newNode;
            newNode->prev = cur;
            // if the node is not the last node
            if(newNode->next) {
                newNode->next->prev = newNode;
            }
            printf("Inserted %d at position %d\n",data,pos);
        }
    }
}

void deleteFront(node **head) {
    if(*head == NULL) {
        printf("List is Empty!\n");
    } else {
        node *temp = *head;
        *head = (*head)->next;
        // if the list has only one node
        if(*head) {
            (*head)->prev = NULL;
        }
        printf("Deleted %d from front!\n",temp->data);
        free(temp);
    }
}

void deleteRear(node **head) {
    if(*head == NULL) {
        printf("List is Empty!\n");
    }
    else {
        node *cur = *head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        // if the list has only one node
        if(cur->prev == NULL) {
            *head = NULL;
        }
        else {
            cur->prev->next = NULL;
        }
        printf("Deleted %d from rear!\n",cur->data);
        free(cur);
    }
}

void deleteAt(node **head, int pos) {
    if(*head == NULL) {
        printf("List is Empty!\n");
    } else {
        node *cur = *head;
        // position starts from 1
        for(int i = 1; i < pos && cur; i++) {
            cur = cur->next;
        }
        if(cur == NULL) {
            printf("Invalid position!\n");
            return;
        } 
        // if the node is the first node
        if(cur->prev == NULL) {
            *head = cur->next;
            if(*head) {
                (*head)->prev = NULL;
            }
        }
        // if the node is the last node
        else if(cur->next == NULL) {
            cur->prev->next = NULL;
        }
        // if the node is in the middle
        else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        printf("Deleted %d from position %d\n",cur->data,pos);
        free(cur);
    }
}

// Recursive function to delete the alternate nodes
void deleteAlt(node **head) {
    if(*head == NULL) {
        printf("Deletion Complete!\n");
        return;
    }
    node *cur = *head;
    *head = (*head)->next;
    free(cur);
    if(*head) {
        (*head)->prev = NULL;
        deleteAlt(&((*head)->next));
    }
}

int displayList(node *head) {
    if(head == NULL) {
        printf("List is Empty!\n");
        return 0;
    }
    node *cur = head;
    int count = 0;
    while(cur != NULL) {
        printf("<- %d ->",cur->data);
        count++;
        cur = cur->next;
    }
    printf("Null \n");
    return count;
}

int main()
{
    node *head = NULL;
    int choice,data,pos;
    while(1) {
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from rear\n");
        printf("6. Delete from position\n");
        printf("7. Delete alternate nodes\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                insertFront(&head,data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d",&data);
                insertRear(&head,data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d",&data);
                printf("Enter the position: ");
                scanf("%d",&pos);
                insertAt(&head,data,pos);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                deleteRear(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d",&pos);
                deleteAt(&head,pos);
                break;
            case 7:
                deleteAlt(&head);
                break;
            case 8:
                printf("Number of nodes: %d\n",displayList(head));
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}