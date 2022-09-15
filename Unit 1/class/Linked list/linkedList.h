/*
1.) Ceate list
2.) Insert List
3.) Insert Rear
4.) Insert at Pos
5.) Delete Front
6.) Delete Rear
7.) Delete at Pos
8.) Display
*/
struct node {
    int data;
    struct node *link;
};
typedef struct node Node;

Node *createList(Node *head);
Node *insertFront(Node *head, int ele);
Node *insertRear(Node *head, int ele);
Node *insertAtPos(Node *head,int pos,int ele);
Node *deleteFront(Node *head);
Node *deleteRear(Node *head);
Node *deleteAtPos(Node *head, int pos);
void displayList(Node *head);
Node *destroyList(Node *head);