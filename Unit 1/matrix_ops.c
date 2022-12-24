// multiply two matrices.
#include<stdio.h>
void read_matrix(int c1;int (*)[c1],int r1,int c1);
void display_matrix(int c2;int (*)[c2],int r2,int c2);
void addition(int c1;int (*a)[c1],int (*b)[c1], int r1,int c1,int(*c)[c1]);
void multiply_matrix(int c1; int c2;int (*a)[c1],int (*b)[c2],int r1,int c1,int c2,int (*)[c2]);
int main()
{
	int r1,r2,c1,c2;
	int a[100][200];
	int b[100][100];
	int c[100][100];
	printf("enter the rows and columns in a first matrix\n");
	scanf("%d%d",&r1,&c1);
	printf("enter the rows and columns in a second matrix\n");
	scanf("%d%d",&r2,&c2);
	if (r1==r2 && c1 == c2)
	{	printf("addition possible\n");
		printf("enter %d elements in A\n",r1*c1);
		read_matrix(a,r1,c1);
		printf("enter %d elements in B\n",r2*c2);
		read_matrix(b,r2,c2);
		addition(a,b,r1,c1,c);
		printf("addition of two matrices is\n");
		display_matrix(c,r1,c1);
		//sub_matrix(a,b,r1,c1,c);
		//printf("subtraction of two matrices is\n");
		//display(c,r1,c1);
	}
	else
		printf("not compatible for addition\n");
	if (c1 == r2)
	{
		printf("enter %d elements in A\n",r1*c1);
		read_matrix(a,r1,c1);
		printf("enter %d elements in B\n",r2*c2);
		read_matrix(b,r2,c2);
		multiply_matrix(a,b,r1,c1,c2,c);
		printf("multiplication of two matrices is\n");
		display_matrix(c,r1,c2);
	}	

	else
		printf("not compatible for multiplication\n");
	return 0;
}


void read_matrix(int c1;int (*a)[c1],int r1,int c1)
{
	int i,j;
	for(i = 0;i<r1;i++)
	{
		for(j = 0;j<c1;j++)
		{
			printf("enter the element\n");
			scanf("%d",&a[i][j]);
		}
	}
}
void display_matrix(int c2;int (*a)[c2],int r2,int c2)
{
	int i,j;
	for(i = 0;i<r2;i++)
	{
		for(j = 0;j<c2;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void addition(int c1;int (*a)[c1],int (*b)[c1], int r1,int c1,int(*c)[c1])
{
	int i,j;
	for(i = 0;i<r1;i++)
	{
		for(j = 0;j<c1;j++)
		{
			c[i][j] = a[i][j]+b[i][j];	
		}
		printf("\n");
	}
}

void multiply_matrix(int c1; int c2;int (*a)[c1],int (*b)[c2],int r1,int c1,int c2,int (*c)[c2])
{	// c1 = r2 (condition for multiplication of two arrays)
	int i,j,k;
	for(i = 0;i<r1;i++)
	{
		for(j = 0;j<c2;j++)
		{
			int sum = 0;
			for(k = 0;k<c1;k++)
			{
		
				sum  = sum + (a[i][k]*b[k][j]);
			}
			c[i][j] = sum;	
		}
		printf("\n");
	}	
}
