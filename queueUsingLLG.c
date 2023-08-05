#include <stdio.h>
#include <stdlib.h>
void search();

struct node
{
    int data;
    struct node *next;
};

int c = 0;
struct node *head;
int b = 0;
void enqueue(int);
int dequeue();
void display();

int main()
{
    int n, a, p, ch;
    head = NULL;
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &n);
            enqueue(n);

            break;

        case 2:
            if (head == NULL)
            {
                printf("queue is empty");
                exit(0);
            }
            else
            {
                p = dequeue();
                printf("\ndeleted element is:%d\n", p);
            }
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("invalid choice");
        }
    }
    return 0;
}

void enqueue(int element)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    c++;
    insert->data = element;
    insert->next = NULL;

    if (head == NULL)
    {
        head = insert;
    }
    else
    {
        struct node *traverse = head;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse->next = insert;
    }
}
int dequeue()
{
    int element;
    struct node *deleted = head;
    c--;
    element = deleted->data;
    head = deleted->next;
    free(deleted);
    return element;
}
void display()
{
    struct node *display;
    display = head;
    while (display != NULL)
    {
        printf("%d->", display->data);
        display = display->next;
    }
}