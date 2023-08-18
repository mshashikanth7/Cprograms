/* Implementation of Circular Linked list Operations
case = t1
input=
1
12
1
1
23
2
1
34
3
1
56
1
3
4
23
5
output=
56->12->23->34->
23 found at position 3

case = t2
input=
1
12 1
1
20 2
1
30 3
2 1
3
5
output =
20-> 30*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert();
void delete();
void displaycll();
void display();
void search();
int c = 0, b = 0;
void main()
{
    int a, ch;
    head = NULL;
    while (1)
    {
        // printf("\n1.INSERT\t2.DELETE.\t3.Display\t4.display-CLL\t5.SEARCH\t6.exit");
        // printf("\nEnter ur choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}
void insert()
{
    int n, p, i;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp2, *x;
    // printf("\nEnter the element and its position");
    scanf("%d%d", &n, &p);
    if (p <= 0 || p > c + 1)
        printf("Enter a valid position");
    else
    {
        c++;
        temp->data = n;
        temp->next = NULL;
        if (p == 1)
        {
            temp->next = head;
            head = temp;
            x = head;
            for (i = 1; i < c; i++)
                x = x->next;
            x->next = temp;
        }
        else
        {
            temp2 = head;
            for (i = 1; i < p - 1; i++)
            {
                temp2 = temp2->next;
            }
            temp->next = temp2->next;
            temp2->next = temp;
        }
    }
}
void delete()
{
    int p, i;
    struct node *temp1 = head, *temp2, *x;
    // printf("\nEnter the position from which data has to be removed");
    scanf("%d", &p);
    if (p <= 0 || p > c)
        printf("Enter a valid position");
    else
    {
        c--;
        if (p == 1)
        {
            head = temp1->next;
            free(temp1);
            x = head;
            for (i = 1; i < c; i++)
            {
                x = x->next;
            }
            x->next = head;
        }
        else
        {
            for (i = 1; i < p - 1; i++)
            {
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = temp2->next;
            free(temp2);
        }
    }
}

void search()
{
    int n, p = 0;
    struct node *x;
    // printf("\nEnter the element to be searched");
    scanf("%d", &n);
    x = head;
    do
    {
        if (x == NULL)
        {
            printf("list is empty");
            return;
        }
        p++;
        if (x->data == n)
        {
            printf("%d found at position %d\n", x->data, p);
            return;
        }
        x = x->next;
    } while (x != head);
    printf("element not found");
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("list is empty");
        return;
    }

    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}