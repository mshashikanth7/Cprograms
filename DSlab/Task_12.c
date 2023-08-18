/*
TASK 12 A -  Write a C code for Inorder Preorder and Postorder traversals of Binary serach Tree uisng recursion.

Test Case example:
case=t2
input=
1
10
1
20
1
30
4
2
3
5
output=
Postorder Traversal of BST
30	20	10
Preorder Traversal of BST
10	20	30
Inorder Traversal of BST
 10	20	30

*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int ikey);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);

int main()
{
    struct node *root = NULL, *ptr;
    int choice, k;

    while (1)
    {
        // printf("\n");
        // printf("\n 1.Search 2.Insert  3.Delete  4.Display 5.Quit \nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1: // printf("\nEnter the key to be inserted : ");
            scanf("%d", &k);
            root = insert(root, k);
            break;

        case 2:
            printf("Preorder Traversal of BST\n");
            preorder(root);
            break;
        case 3:
            printf("Inorder Traversal of BST\n");
            inorder(root);
            break;
        case 4:
            printf("Postorder Traversal of BST\n");
            postorder(root);
            break;
        case 5:
            exit(1);

        default:
            printf("\n Invalid Choice\n");
        }
    }
    return 0;
}

struct node *insert(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (ikey < ptr->info) /*Insertion in left subtree*/
        ptr->lchild = insert(ptr->lchild, ikey);
    else if (ikey > ptr->info) /*Insertion in right subtree */
        ptr->rchild = insert(ptr->rchild, ikey);
    else
        printf("\nDuplicate key\n");
    return ptr;
}

void postorder(struct node *ptr)
{
    if (ptr == NULL) /*Base Case*/
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d  ", ptr->info);
}

void preorder(struct node *ptr)
{
    if (ptr == NULL) /*Base Case*/
        return;
    printf("%d  ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{
    if (ptr == NULL) /*Base Case*/
        return;
    inorder(ptr->lchild);
    printf("%d  ", ptr->info);
    inorder(ptr->rchild);
}

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

/*
LAB TASK 12
QUESTION: 12 B- Design a C program for level order traversal of a Binary Search Tree.

Test Cases:
case = t1
input =
2
3
output =
Level Order Traversal of BST :
Binary Search Tree is Empty

case = t2
input =
1
10
1
20
1
30
1
5
2
3
output =
Level Order Traversal of BST :
10 5 20 30

case = t3
input =
4
3
output =
Invalid choice

*/
// Start writing program from here

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
int rear = -1, front = -1;
struct node *insert(struct node *root, int data);
void levelorder(struct node *root);
struct node *queue[20];
void enqueue(struct node *x);
void dequeue();

int main()
{
    int ch, n;
    while (1)
    {
        // printf("\n1. INSERT 2.LEVEL ORDER TRAVERSAL 3.EXIT -Enter ur choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // printf("\nEnter the element to be inserted :");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            printf("\nLevel Order Traversal of BST :\n");
            levelorder(root);
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}

struct node *insert(struct node *root, int data)
{
    struct node *temp;
    if (root == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        root = temp;
        return root;
    }
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void levelorder(struct node *root)
{
    struct node *temp;
    if (root == NULL)
    {
        printf("\nBinary Search Tree is Empty\n");
        return;
    }
    enqueue(root);
    while (front != rear)
    {
        temp = queue[front + 1];
        printf("%d ", temp->data);
        if (temp->left != NULL)
            enqueue(temp->left);
        if (temp->right != NULL)
            enqueue(temp->right);
        dequeue();
    }
}

void enqueue(struct node *x)
{
    rear++;
    queue[rear] = x;
}

void dequeue()
{
    front++;
}