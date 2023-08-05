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
int search(struct node *root, int data);
struct node *del(struct node *root, int n);
struct node *rmin(struct node *root);
void display(struct node *root);

void main()
{
    int ch, n, key, a, k;
    while (1)
    {
        // printf("\n1. INSERT\t2. DELETE\t3. SEARCH\t4. DISPLAY");
        // printf("\nEnter ur choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // printf("\nEnter the element to be inserted");
            scanf("%d", &n);
            root = insert(root, n);
            break;

        case 2: // printf("Enter the element to be deleted");
            scanf("%d", &k);
            root = del(root, k);
            break;

        case 3: // printf("\nEnter the element to be searched");
            scanf("%d", &key);
            if (search(root, key) == 1)
                printf("%d element is found\n", key);
            else
                printf("%d element not found\n", key);
            break;

        case 4:
            display(root);
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice");
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
void display(struct node *root) // postorder
{
    if (root == NULL)
        return;
    display(root->left);
    display(root->right);
    printf("%d->", root->data);
}

struct node *rmin(struct node *root)
{
    if (root == NULL)
        return 0;
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct node *del(struct node *root, int n)
{
    struct node *temp;
    if (root == NULL)
        return root;
    else if (n < root->data)
        root->left = del(root->left, n);
    else if (n > root->data)
        root->right = del(root->right, n);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            temp = root;        /// 23
            root = root->right; // 35
            free(temp);
        }
        else if (root->right == NULL)
        {
            temp = root;       // 23
            root = root->left; // 18
            free(temp);
        }
        else
        {
            temp = rmin(root->right);                   // 18
            root->data = temp->data;                    /// 18
            root->right = del(root->right, temp->data); // deletes the inorder successor from its original place
        }
    }
    return root;
}