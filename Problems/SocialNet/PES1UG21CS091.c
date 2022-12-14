#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    if(users == NULL) return NULL;
    else {
        // key is found
        if(key == users->id) return users;
        // key is smaller than root's key
        else if(key < users->id) return search(key, users->left);
        // key is greater than root's key
        else return search(key, users->right);
    }
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    if(user == NULL) {
        return NULL;
    }
    // Until we dont find the user with the same ID
    while(search(user->id,users)!=NULL)
    {
        user->id++;
    }
    struct node *userFriend = NULL;
    //for each friend of user
    bool friendFound=false;
    int i = 0;
    while ((i < user->numfren)&&(user->numfren!=0))
    {
        userFriend = search(user->friends[i],users);
        // delete the friend if it is not in the tree
        if(userFriend == NULL)
        {
            for (int j = i; j < user->numfren-1; j++)
            {
                user->friends[j]=user->friends[j+1];
            }
            user->numfren--;
        }
        else {
            for (int j = 0; (j < userFriend->numfren)&&(!friendFound); j++)
            {
                if(userFriend->friends[j]==user->id)
                {
                    friendFound=true;
                }
            }
            if (!friendFound && userFriend->numfren != MAX)
            {
                userFriend->friends[userFriend->numfren]=user->id;
                userFriend->numfren++;
            }
            friendFound=false;
            i++;
        }
    }
    if(user->numfren==0) user->friends[0]=-1;
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
    // root != NULL
    if(root!=NULL) {
        if(id > root->id) {
            root->right = insertUser(root->right,id,user);
        }
        else if(id < root->id) {
            root->left = insertUser(root->left,id,user);
        }
        return root;
    }
    //root is null case
    else {
        user->right = NULL;
        user->left = NULL;
        root = user;
        return root;
    }
}

//prints friends list
void friends(int id, struct node *users) 
{
    struct node *tempUser = NULL;
    tempUser = search(id,users);
    if(tempUser != NULL) {
        // printf("Friends of %d: ",id);
        if(tempUser->numfren==0)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=0;i<tempUser->numfren;i++)
            {
                printf("%d\n",tempUser->friends[i]);
            }
        }
    }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
    if(node == NULL) return node;
    else {
        struct node *currentUser = node;
        while(currentUser->left != NULL) {
            currentUser = currentUser->left;
        }
        return currentUser;
    }
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    struct node *tempUser = search(key,users);
    struct node *tempFriend = NULL;
    if(tempUser != NULL) {
        for(int i = 0;i < tempUser->numfren;i++) {
            tempFriend = search(tempUser->friends[i],users);
            if(tempFriend != NULL) {
                for(int j = 0; j < tempFriend->numfren;j++) {
                    if(tempFriend->friends[j] == key) {
                        for (int k = j; k < tempFriend->numfren - 1; k++)
                        {
                            tempFriend->friends[k] = tempFriend->friends[k + 1];
                        }
                        tempFriend->numfren--;
                    }
                }
            }
        }
        free(tempUser->friends);
        tempUser->friends = NULL;
        tempUser->numfren = 0;
    }
    return users;
}

void copyNode(struct node *node1,struct node *node2) {
    node1->id = node2->id;
    strcpy(node1->name,node2->name);
    node1->numfren = node2->numfren;
    node1->friends = node2->friends;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == NULL) {
        return NULL;
    }
    else if(key < root->id) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->id) {
        root->right = deleteNode(root->right, key);
    }
    else {
        struct node *tempNode;
        // deleting node with one child
        if(root->left == NULL) {
            tempNode = root->right;
            free(root);
            return tempNode;
        }
        else if(root->right == NULL) {
            tempNode = root->left;
            free(root);
            return tempNode;
        }
        // deleting node with two children
        else {
            tempNode = minValueNode(root->right);
            // Copying the inorder successor's content to this node
            copyNode(root,tempNode);
            // Deleting the inorder successor
            root->right = deleteNode(root->right, tempNode->id);
            return root;
        }
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    // if tree is empty
    if(myusers == NULL) return;
    // print left subtree
    printInOrder(myusers->left);
    // print root
    printf("%d %s\n", myusers->id,myusers->name); 
    // print right subtree
    printInOrder(myusers->right);
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}