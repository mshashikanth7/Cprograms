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