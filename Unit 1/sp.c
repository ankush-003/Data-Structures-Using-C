#include<stdio.h>
#include<stdlib.h>
#define max_size 50
typedef enum {head,entry} tagfield;

typedef struct
{
    int row,col,val;
}entrynode;

struct mn       //matrix node
{

    struct mn *down;
    struct mn *right;
    tagfield tag;
    union
    {
        struct mn *next;
        entrynode entry;
    }u;
};

typedef struct mn *matrixpointer;
matrixpointer hdnode[max_size];

matrixpointer readsparse()
{
int numrows,numcols,numterms,numheads,i;
int row,col,val,currentrow;
matrixpointer temp,last,node;
printf("Enter the number of rows cols non zero elements\n");
scanf("%d %d %d", &numrows,&numcols,&numterms);
numheads=(numcols>numrows)? numcols:numrows;
node=(matrixpointer)malloc(sizeof(struct mn));
node->tag=entry;
node->u.entry.row=numrows;
node->u.entry.col=numcols;
if(!numheads)
   node->right=node;
else
    {
    for(i=0;i<numheads;i++)
    {
      temp=(matrixpointer)malloc(sizeof(struct mn));
        hdnode[i]=temp;
        hdnode[i]->tag=head;
        hdnode[i]->right=temp;
        hdnode[i]->u.next=temp;
    }
    currentrow=0;
    last=hdnode[0];
    for(i=0;i<numterms;i++)
    {
        printf("Enter row col and value\n");
        scanf("%d %d %d",&row,&col,&val);
        if(row>currentrow)
        {
            last->right=hdnode[currentrow];
            currentrow=row;
            last=hdnode[row];
        }
        temp=(matrixpointer)malloc(sizeof(*temp));
        temp->tag=entry;
        temp->u.entry.row=row;
        temp->u.entry.col=col;
        temp->u.entry.val=val;
        last->right=temp;
        last=temp;
        hdnode[col]->u.next->down=temp;
        hdnode[col]->u.next=temp;
    }
    last->right=hdnode[currentrow];
    for(i=0;i<numcols;i++)
      hdnode[i]->u.next->down=hdnode[i];
    for(i=0;i<numheads-1;i++)
      hdnode[i]->u.next=hdnode[i+1];
      hdnode[numheads-1]->u.next=node;
      node->right=hdnode[0];
}
return node;
}

void printsparse(matrixpointer node)
{
    int i;
    matrixpointer temp,head;
    head=node->right;
    printf("Numrows=%d Numcols=%d\n",node->u.entry.row,node->u.entry.col);
    printf("The matrix by row col and value are\n");
    for(i=0;i<node->u.entry.row;i++)
    {
        for(temp=head->right;temp!=head;temp=temp->right)
        printf("%5d %5d %5d\n",temp->u.entry.row,temp->u.entry.col,temp->u.entry.val);
        head=head->u.next;
        printf("\n");
    }
}

int main()
{
    matrixpointer p;
    p=readsparse();
    printsparse(p);
    return 0;
}
