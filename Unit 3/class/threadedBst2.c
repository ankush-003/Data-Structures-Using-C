#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int info;
	struct node *left,*right;
	bool rthread;
}N;

typedef struct tree
{
	N *root;
}T;

void init(T *pt)
{
	pt->root=NULL;
}

N* createNode(int e)
{
	N* temp=malloc(sizeof(N));
	temp->info=e;
	temp->left=NULL;
	temp->right=NULL;
	temp->rthread=1;
	return temp;
}

void setLeft(N *q,int e)
{
	N* temp=createNode(e);
	q->left=temp;
	temp->right=q;
}

void setRight(N* q,int e)
{
	N* temp=createNode(e);
	temp->right=q->right; //thread
	q->right=temp;
	q->rthread=0;
}

void inOrder(T *t)
{
	N *p=t->root;
	N *q;
	do
	{
		q=NULL;
		while(p!=NULL)
		{
			q=p;
			p=p->left;
		}
		if(q!=NULL)
		{
			printf("%d ",q->info);
			p=q->right;
			while(q->rthread && p!=NULL)
			{
				printf("%d ",p->info);
				q=p;
				p=p->right;
			}
		}
	}while(q!=NULL);
}

void create(T *pt)
{
	N *p,*q;
	int e,wish;
	printf("Enter root info\n");
	scanf("%d",&e);
	pt->root=createNode(e);
	do
	{
		printf("Enter info\n");
		scanf("%d",&e);
		
		p=pt->root;
		q=NULL;
	while(p!=NULL)
	{
		q=p;
		if(e<p->info)
			p=p->left;
		else
		{
			if(p->rthread)
				break;
			else
				p=p->right;
		}		
	}
	if(e < q->info)
		setLeft(q,e);
	else
		setRight(p,e);
	printf("Do you wish to add another element\n");
	scanf("%d",&wish);
	}while(wish);
}



int main()
{
	T t;
	init(&t);
	create(&t);
	inOrder(&t);
    return 0;
}