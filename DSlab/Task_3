/*3a. Write a C program to implement STACK operations using array

Test Cases:
example 1:
input = 1
12
1
21
1
45
3
4
output = 45 21 12

example 2:
case = t2
input = 2 4
output = stack is empty
*/
// Start writing program from here

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int stack[MAX_SIZE];
int top = -1;

void push(int);
void pop();
void print();

void push(int ele)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = ele;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int poppedElement = stack[top];
        printf("%d is popped from stack\n", stack[top]);
        top--;
    }
}

void print()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {

        for (int i = top; i >= 0; --i)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        int k, i;
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            scanf("%d", &i);
            push(i);
            break;
        case 2:
            pop();
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
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
/*3b. Write a C program to implement QUEUE operations using array

Test Cases:
example 1:
input = 1
12
1
21
1
45
3
4
output = 12 21 45

example 2:
case = t2
input = 2 4
output = queue is empty
*/
// Start writing program from here

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

int queue[QUEUE_SIZE];
int front = rear = -1;

void enqueue(int);
void dequeue();
void display();
int main()
{
    int ch = 0, ele = 0;
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // printf("enter the element to inserted :");
            scanf("%d", &ele);
            enqueue(ele);

            break;
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}

void enqueue(int ele)
{
    if (rear == QUEUE_SIZE - 1)
    {
        printf("\nqueue is full");
    }
    else
    {
        rear = rear + 1;
        queue[rear] = ele;
    }
}

void dequeue()
{
    if (front == rear)
    {
        printf("queue is empty \n");
    }
    else
    {
        front = front + 1;
        printf("%d is deleted from queue\n", queue[front]);
    }
    if (front == rear)
    {
        front = rear = -1;
    }
}

void display()
{
    int i;
    if (front == rear)
        printf("\n queue is empty ");
    else
    {
        for (i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
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
/*
TASK 3C. Write a C program to implement CIRCULAR QUEUE operations using arrays.

Test Cases:
case=t4
input=
1
20
1
30
1
40
1
50
3
2
1
50
1
60
3
4
output=
Circular Queue overflow
20	30	40
rear=2 pointing at 40
front=0 pointing at 20
Deleted Element is 20
Circular Queue overflow
50	30	40
rear=0 pointing at 50
front=1 pointing at 30
*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>

#define QS 3

int queue[QS];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue();
void display();

int main()
{
    int ch, ele;
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

void enqueue(int ele)
{
    if ((rear == QS - 1 && front == 0) || (rear == front - 1))
        printf("\nCircular Queue overflow");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = ele;
    }
    else if (rear == QS - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = ele;
    }
    else
    {
        rear++;
        queue[rear] = ele;
    }
}

void dequeue()
{
    if (front == -1)
        printf("\nCircular Queue underflow");
    else
    {
        printf("\nDeleted Element is %d", queue[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == QS - 1)
            front = 0;
        else
            front++;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("\nCircular Queue is empty");

    else
    {
        if (rear > front)
        {
            printf("\n");
            for (i = front; i <= rear; i++)
                printf("%d\t", queue[i]);
        }
        else
        {
            printf("\n");

            for (i = 0; i <= rear; i++)
                printf("%d\t", queue[i]);
            for (i = front; i < QS; i++)
                printf("%d\t", queue[i]);
        }

        printf("\nrear=%d pointing at %d", rear, queue[rear]);
        printf("\nfront=%d pointing at %d", front, queue[front]);
    }
}