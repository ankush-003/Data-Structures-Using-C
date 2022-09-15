typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
}Node;

void insertList(Node **head,int ele);
void displayList(Node **head);
void mergeLists(Node **l1, Node **l2,Node **l3);