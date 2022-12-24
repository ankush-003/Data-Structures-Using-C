typedef struct node
{
	int info;
	struct node *prev,*next;
}Node;

typedef struct list
{
	Node *head;
}List;

void initList(List* pl);
Node *createNode(int ele);
void insertFront(List* pl,int ele);
void insertLast(List* pl,int ele);
void insertAtPos(List* pl,int ele,int pos);
void destroyList(List* pl);
void display(List* pl);
int deleteFront(List* pl,int *pe);
int deleteLast(List* pl,int *pe);
int deleteAtPos(List* pl,int *pe,int pos);
int deleteInfo(List* pl,int pe);