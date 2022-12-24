#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct plant
{
    int pest;
    int num;
} plant;

typedef struct stack
{
    plant *garden;
    int size;
    int top;
} stack;

void initStack(stack *sptr, int size)
{
    sptr->size = size;
    sptr->top = -1;
    sptr->garden = (plant *)malloc(size * sizeof(plant));
}

int isEmpty(stack *sptr)
{
    return sptr->top == -1;
}

int isFull(stack *sptr)
{
    return sptr->top == sptr->size - 1;
}

void push(stack *sptr, plant p)
{
    if (isFull(sptr))
        printf("Stack overflowed!\n");
    else
    {
        sptr->garden[++sptr->top] = p;
    }
}

plant pop(stack *sptr)
{
    if (isEmpty(sptr))
    {
        printf("Stack underflowed!\n");
        exit(-1);
    }
    else
    {
        return sptr->garden[sptr->top--];
    }
}

plant peek(stack *sptr)
{
    plant temp;
    temp.num = -1;
    temp.pest = -1;
    if (!isEmpty(sptr))
    {
        temp.num = sptr->garden[sptr->top].num;
        temp.pest = sptr->garden[sptr->top].pest;
    }
    return temp;
}

plant *deadPlants(plant *g, int size, int *nalive)
{
    if (!size)
    {
        printf("Invalid input!\n");
        exit(-1);
    }
    else if (size == 1)
    {
        *nalive = size;
        return g;
    }
    else
    {
        plant *alive;
        stack aux;
        initStack(&aux, size);
        int dead = 0;
        plant left;
        for (int i = 0; i < size; i++)
        {
            if (isEmpty(&aux))
                push(&aux, g[i]);
            else
            {
                left = peek(&aux);
                if (left.pest > g[i].pest)
                    push(&aux, g[i]);
                else
                {
                    dead++;
                }
            }
        }
        if (!dead)
        {
            *nalive = size;
            return aux.garden;
        }
        *nalive = aux.top + 1;
        return deadPlants(aux.garden, aux.top + 1,nalive);
    }
}

int main()
{
    printf("Enter pesticide and plant:");
    int num;
    int pest;
    plant garden[50];
    plant *alive;
    int nalive = 0;
    int i = 0;
    scanf("%d %d", &pest, &num);
    while (num != -1 && pest != -1)
    {
        garden[i].num = num;
        garden[i].pest = pest;
        i++;
        scanf("%d %d", &pest, &num);
    }
    printf("\nPlants in Garden:\n");
    for (int j = 0; j < i; j++)
    {
        printf("pest: %d\tnum: %d\n", garden[j].pest, garden[j].num);
    }
    alive = deadPlants(garden, i,&nalive);
    printf("\nPlants Alive:\n");
    for (int k = 0; k < nalive; k++)
    {
        printf("pest: %d\tnum: %d\n", alive[k].pest, alive[k].num);
    }
    return 0;
}