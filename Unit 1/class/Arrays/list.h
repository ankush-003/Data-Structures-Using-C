struct list
{
    int *arr;
    int arrsize;
    int noe;//active number of elements
};

typedef struct list List;

void create_list(List *lptr,int lsize);
void insert_ele(List *lptr,int ele,int pos);
void delete_ele(List *lptr,int pos);
void display(List *lpr);
int search(List *lpr,int ele);