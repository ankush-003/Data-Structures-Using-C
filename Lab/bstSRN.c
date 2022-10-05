#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
struct node {
    char value;            // all void types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(char * s) 
{
    int i = 0;
    while(s[++i]);
    return i;
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    int i = 0;
    while(str2[i]) {
        str1[i] = str2[i];
        i++;
    }  
    str1[i] = str2[i];// for '\0'  
}

int my_strcmp(const char *a, const char *b)
{
    
}
//inserts elements into the tree
void insert(char* key, struct node** leaf)
{
    
}




//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    
}



//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    
}




int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }   
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}