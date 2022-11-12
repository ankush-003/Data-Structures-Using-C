typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
}Node;

void insertList(Node **head,int ele);
void displayList(Node **head);
int searchEle(Node **head,int ele);
