//all functions working


#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node node_t;

struct doubly_linked_list
{
	node_t* head;
	node_t* tail;
	int size;
};

typedef struct doubly_linked_list list_t;

list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t *list, int data)  // TODO: inserts data to the beginning of the linked list
{
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    
    if(list->head == NULL)
    {
        list->head = list->tail = temp;
        list->head->prev = NULL;
        list->tail->next =NULL;
    }
    else
    {
        list->head->prev = temp;
        temp->next = list->head;
        temp->prev = NULL;
        list->head = temp;
    }
    (list->size)++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;

    list->tail = list->head;
    temp->next = NULL;

    if(list->head == NULL)
    {
        temp->prev = NULL;
        list->head = temp;
    }

    else
    {
        while(list->tail->next != NULL)
        {
            list->tail = list->tail->next;
        }
        list->tail->next = temp;
        temp->prev = list->tail;
        list->tail = temp;
    }
    (list->size)++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;

    if(list->head==NULL)
        printf("no list so no prev\n"); // delete this later
    else
    {
       node_t *p = list->head;
       while(p!=NULL && p->data!=prev)
       {
            p = p->next;
       }

       if(p->next==NULL)
            printf("NO prev data\n");
       else
       {
            new_node->next = p->next;
            new_node->prev = p;
            p->next = new_node;
            p->next->prev = new_node;

            (list->size)++ ;
       }
    }
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
    node_t *temp;
    if(list->head == NULL)
        printf("Nothing to delete\n");  //you should delete this later
    else
    {
        temp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
        (list->size)--;
    }
    
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
    node_t *temp;
    if(list->tail == NULL)
        printf("Nothing to delete\n");  //you should delete this later
    else
    {
        temp = list->tail;
        list->tail = list->tail->prev;

        list->tail->next = NULL;
        free(temp);
        (list->size)--;
    }
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
    node_t *temp;
    if(list->head == NULL)
        printf("Nothing to delete\n");  //you should delete this later
    else
    {
        temp = list->head;
        if(temp->data == data)
            {list->head = temp->next;
            free(temp);}

        else
        {
            while (temp!=NULL && temp->data!=data)
            {
                temp = temp->next;
            }
            if(temp == NULL)
                printf("info not found\n");   //delete this later
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                free(temp);
            }  
            (list->size)--;
        }
    }
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
    if(list->head == NULL)
        return NULL;
    node_t *temp;
    temp = list->head;
    while(temp!=NULL && temp->data!=data)
        temp=temp->next;
    if(temp->data == data)
        return temp;
    else
        return NULL;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

    void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
    {
        // DO NOT MODIFY!!!
        node_t* it = list->head;
        while(it != NULL)
        {
            printf("%d ", it->data);
            it = it->next;
        }
        printf("\n");
    }


int main()
{
    list_t *l = create_list();
    insert_front(l, 1);
    insert_front(l, 2);
    insert_front(l, 3);
    insert_front(l, 4);
    
    insert_back(l,5);
    display_list(l);
    
    
    
    delete_back(l);
    display_list(l);
    
    delete_node(l,3);
    display_list(l);
    
    
    
    printf("%d\n", is_empty(l));
    printf("%d\n", size(l));
    
    
    
    
}