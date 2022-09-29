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



typedef node_t song_t;
typedef queue_t music_queue_t;

struct playlist
{
	list_t* list;
	int num_songs;
	song_t* last_song; // last played song		
};

typedef struct playlist playlist_t;
#include <stdio.h>
#include <stdlib.h>

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


       if(p==NULL)
            printf("NO prev data\n"); // delete this later
        else if(p->next == NULL)
            insert_back(list, data);
       else
       {
            new_node->next = p->next;
            new_node->prev = p;
           
            p->next->prev = new_node;
            p->next = new_node;

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

        return data;

    }


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

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
    if(where == -1)
        insert_front(playlist->list, song_id);
    else if(where == -2)
        insert_back(playlist->list, song_id);
    else if(where>0)
        insert_after(playlist->list, song_id, where);
    else
        printf("Invalid\n");   //delete this later
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
    delete_node(playlist->list, song_id);
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
    return search(playlist, song_id);
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{

}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{

}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{

}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
    front(q);
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
    enqueue(q, song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
    node_t *temp, *current;
    temp = NULL;
    current = playlist->list->head;

    while(current!=NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL)
        playlist->list->head = temp->prev;
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
    int i;
    node_t* temp = NULL;
    node_t* current = playlist->list->head;
    if(playlist->list->head == NULL)
        printf("playlist is empty\n");   // delete this later
    for(i = 0; i+k < size(playlist->list); i++)
    {   
        swap(i, i+k);
    }
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
    k_swap(playlist,k);
    reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{

}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}

int main()
{
    playlist_t *pl = create_playlist();
    add_song(pl, 1, -1);
    add_song(pl, 2, -1);
    add_song(pl, 3, -1);
    add_song(pl, 4, -1);

    add_song(pl, 5,-2);
    add_song(pl, 6, -2);
    

    add_song(pl, 8, 6);
    display_playlist(pl);

    

    
    reverse(pl);
    display_playlist(pl);


    song_t* s = search_song(pl, 1);
    printf("%d\n", s->data);


}