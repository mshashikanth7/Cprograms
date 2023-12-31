/*Write a C program to implement stack using linked list.

 Test Case examples :

    case = t1
    input =
        1 12 1 34 1 45 3 4 output =
            45->34->12->

            case = t2
                input =
                    1 45 1 34 1 23 2 2 2 2 4 output =
                        deleted element is:
23 deleted element is : 34 deleted element is : 45 stack is empty
        */
// Start writing program from here
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
void push(int);
int pop();
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
            push(n);
            break;

        case 2:
            if (head == NULL)
            {
                printf("stack is empty");
            }
            else
            {
                p = pop();
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
void push(int element)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->data = element;
    insert->next = head;
    head = insert;
}
int pop()
{
    int element;
    struct node *deleted = head;
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
/* Write a C program to implement queue using linked list
Test Case examples:

input=
1
12
1
34
1
45
3
output=
12->34->45->
4

*/
// Start writing program from here
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
    head = deleted-  >next;
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