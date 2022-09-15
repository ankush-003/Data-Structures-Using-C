#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;

Node *createnode(int ele)
{
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    if(newNode)
    {
        newNode->data = ele;
        newNode->link = NULL;
    }
    return newNode;
}

//here head to last element is more efficient
int insert_head(Node **ptail,int ele)
{
    Node *newNode;
    newNode = createnode(ele);
    if(newNode != NULL)
    {
        if(*ptail == NULL)
        {
            *ptail = newNode;
            newNode->link = *ptail;
        }
        else
        {
            newNode->link = (*ptail)->link;
            (*ptail)->link = newNode;
        }
        return 1;
    }
    return 0;
}

int insert_tail(Node **ptail,int ele)
{
    Node *newNode;
    newNode = createnode(ele);
    if(newNode != NULL)
    {
        if(*ptail == NULL)
        {
            *ptail = newNode;
            newNode->link = *ptail;
        }
        else
        {
            newNode->link = (*ptail)->link;
            (*ptail)->link = newNode;
            *ptail = newNode;
        }
        return 1;
    }
    return 0;
}

void delete_node(Node **ptail,int ele)
{
    if(!(*ptail))
    {
        printf("No element to be deleted");
        
    }
    else {
        Node *prev,*cur,*last;
        last = *ptail;
        prev = last;
        cur = (*ptail)->link;
        while((cur != last)&&(cur->data != ele))
        {
            prev = cur;
            cur = cur->link;
        }
        if(cur->data == ele)
        {
            //checking if its the last node (single node)
            if(cur->link == cur)
            {
                *ptail = NULL;
            }
            else {
                prev->link = cur->link;
                //change tail pointer if its the last node
                if(cur == last)
                {
                    *ptail = prev;
                }
            }
            printf("Deleted element %d\n",cur->data);
            free(cur);
        }
        else
        {
            printf("Data not found\n");
        }
    }
}

void reverse_list(Node **ptail)
{
    if((*ptail) == NULL)
    {
        printf("List is Empty!\n");
    }
    else if ((*ptail)->link == *ptail)
    {
        printf("Only one element in list\n");
    }
    else
    {
        Node *last = *ptail;
        Node *cur = (*ptail)->link;
        (*ptail) = cur;
        Node *prev = last;
        Node *ptr = last;
        while(cur != last)
        {
            prev = cur;
            cur = cur->link;
            prev->link = ptr;
            ptr = prev;
        }
        cur->link = prev;
        printf("List has been reversed!\n");
    }
}

void display_list(Node *tail)
{
    if(tail == NULL)
    {
        printf("List is empty!\n");
    }
    else {
        Node *pres = (tail)->link;
        printf("\nThe elements of list are:\n");
        while (pres != (tail))
        {
            printf("%d->",pres->data);
            pres = pres->link;
        }
        printf("%d\n",pres->data);
    }
}

void destroy(Node **ptail)
{
    if(*ptail == NULL)
    {
        printf("List is empty!\n");
    }
    else if ((*ptail)->link == *ptail)
    {
        Node *temp = *ptail;
        free(temp);
    }
    else
    {
        Node *pres = (*ptail)->link;
        Node *temp = NULL;
        while(pres != *ptail)
        {
            temp = pres;
            pres = pres->link;
            printf("Deleted %d\n",temp->data);
            free(temp);
        }
        printf("Deleted %d\n",pres->data);
        free(pres);
    }
    *ptail = NULL;
    printf("List destroyed succssfully!\n");
}

int main()
{
    Node *tail = NULL;
    int n,ele;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ele);
        insert_tail(&tail,ele);
    }
    display_list(tail);
    printf("Enter element to delete: ");
    scanf("%d",&ele);
    delete_node(&tail,ele);
    display_list(tail);
    reverse_list(&tail);
    display_list(tail);
    destroy(&tail);
    display_list(tail);
    return 0;
}