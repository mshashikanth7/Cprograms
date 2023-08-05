#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *getnode(int n);
struct node *insert(struct node *root, int data);
int countNodes(struct node *root);
int height(struct node *root);
int minValue(struct node *node);
int maxValue(struct node *node);

void main()
{
    int ch, n, a, k;
    while (1)
    {
        // printf("\n1. INSERT\t2. CountNodes\t3. Hight of BST\t4. Minimum Node\t5. MaximumNode\t.6Exit");
        // printf("\nEnter ur choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // printf("\nEnter the element to be inserted");
            scanf("%d", &n);
            root = insert(root, n);
            break;

        case 2:
            printf("Number of nodes in BST is %d\n", countNodes(root));
            break;

        case 3:
            printf("Height of BST is %d\n", height(root));
            break;

        case 4:
            printf("Minimum Value in BST is %d\n", minValue(root));
            break;
        case 5:
            printf("Maximum Value in BST is %d\n", maxValue(root));
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}
struct node *getnode(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = getnode(data);
        return root;
    }
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
int search(struct node *root, int data)
{
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// A utility function to calculate height of a given BST
int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(root->left);
        int rDepth = height(root->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

// A utility function to find minimum value in BST
int minValue(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return (current->data);
}

// A utility function to find maximum value in BST
int maxValue(struct node *node)
{
    struct node *current = node;

    /* loop down to find the rightmost leaf */
    while (current->right != NULL)
        current = current->right;

    return (current->data);
}