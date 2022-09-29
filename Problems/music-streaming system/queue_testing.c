//all functions working but not able to call empty(). 1 warning.

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


struct queue
{
	list_t* list;
	node_t* front;
	node_t* rear;
	int size;
};

typedef struct queue queue_t;

list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
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


queue_t* create_queue()   // return a newly created empty queue
{
	// DO NOT MODIFY!!!
	queue_t* Q = (queue_t*) malloc(sizeof(queue_t));
	Q->list = create_list();
	Q->front = Q->list->head;
	Q->rear = Q->list->tail;
	Q->size = Q->list->size;
	return Q;
}

void enqueue(queue_t* q, int data) // TODO: insert data at the end of a queue
{
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if(q->front == NULL)
    {
        q->front = q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    (q->size)++;
}

int front(queue_t* q) // TODO: return the data at the front of a queue. Return -1 if queue is empty
{
    if(q->front == NULL)
        return -1;
    else
    {
        return q->front->data;
    }
}


int dequeue(queue_t* q) 	// TODO: return the data at the front of a queue and remove it. Return -1 if queue is empty
{
    if(q->front == NULL)
        return -1;
    else
    {
        int data = front(q);
        queue_t* temp = q->front;
        if(q->front == q->rear)
        {
            q->rear = q->front = NULL;
        }

        else
        {
            q->front = q->front->next;
            q->front->prev = NULL;
        }
        (q->size)--;
        return data;


    }


}



int empty(queue_t* q) // return if the queue is empty
{
	// DO NOT MODIFY!!!
	return is_empty(q->list);
}

int queue_size(queue_t* q) // returns the number of elements in the queue
{
	// DO NOT MODIFY!!!
	return q->size;
}

void delete_queue(queue_t* q) // empty the contents of the queue
{
	// DO NOT MODIFY!!!
	delete_list(q->list);
	free(q);
}


void display_queue(queue_t* q)
{
    node_t *temp = q->front;
    if(q->front == NULL)
        printf("no queue\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}


int main()
{
    queue_t *q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    display_queue(q);
    dequeue(q);
    display_queue(q);

    printf("%d\n", front(q));
    printf("%d\n", queue_size(q));
    



}