struct node
{
    struct node *rlink;
    int digit;
    struct node *llink;
};
typedef struct node Node;

Node *createlist(Node *head,int number);
Node *insertfront(Node *head,int digit);
Node *addlist(Node *l1,Node *l2,Node *res);
void displaylist(Node *head);