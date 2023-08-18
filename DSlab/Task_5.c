/*
LAB TASK 5
QUESTION: 5a- Write a C program to check for balanced parenthesis.

Test cases:
Case=t1
Input=()[]
Output=
Enter any expression:
Balanced pranthesis exp
Expression is balanced

Case=t2
Input= ((a+b)/(d%f)*(e/g))
Output=
Enter any expression:
Balanced pranthesis exp
Expression is balanced

*/
// Start writing program from here

#include <stdio.h>
#include <stdlib.h>

#define max 30

char stack[max];
int top = -1;

void push(char c)
{

    if (top == max - 1)
    {
        printf("stack overflow");
        exit(0);
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    char c;
    if (top <= -1)
    {
        printf("stack underflow");
        exit(0);
    }
    else
    {
        c = stack[top];
        top--;
        return c;
    }
}
void ev(char par[])
{
    int i;
    char c;
    for (i = 0; par[i] != '\0'; i++)
    {
        c = par[i];
        switch (c)
        {
        case '[':
        case '{':
        case '(':
            push(par[i]);
            break;
        case ')':
            if (stack[top] == '(')
            {
                pop();
                break;
            }
            else
            {
                printf("\nright paranthesis are more then left pranthesis\nExpression is unbalanced");
                exit(0);
            }
        case '}':
            if (stack[top] == '{')
            {
                pop();
                break;
            }
            else
            {
                printf("\nright paranthesis and more then left pranthesis\nExpression is unbalanced");
                exit(0);
            }
        case ']':
            if (stack[top] == '[')
            {
                pop();
                break;
            }
            else
            {
                printf("right paranthesis are more than left ");
                exit(0);
            }
        }
    }
    if (top == -1)
    {
        printf("\nBalanced pranthesis exp\nExpression is balanced\n");
    }
    else
    {
        printf("\nUnbalanced pranthesis\nExpression is unbalanced\n");
    }
}
int main()
{
    char par[max];
    printf("\nEnter any expression:");
    scanf("%s", par);
    ev(par);
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
/* 
LAB TASK 5 
QUESTION: 5b-Write a C program to implement priority queue using arrays. 

Test Cases:
Case=t1
Input=
1
m 4
1
p 2
1
a 1
3
4
Output=
 job name   priority
    m     -   4
    p     -   2
    a     -   1

Case=t2
Input=
1
p 5
1
a 1
1
as 4
1
d 10
4
Output=
queue is full

Note: Assumption of output will be displayed like this
1.Enqueue 2.Dequeue 3.display 4.exit
Enter your choice:1
Enter the job name(eg:m) and priority:m 4

1.Enqueue 2.Dequeue 3.display 4.exit
Enter your choice:1
Enter the job name(eg:m) and priority:p 2

1.Enqueue 2.Dequeue 3.display 4.exit
Enter your choice:1
Enter the job name(eg:m) and priority:a 1

1.Enqueue 2.Dequeue 3.display 4.exit
Enter your choice:3
 job name   priority
    m     -   4
    p     -   2
    a     -   1

1.Enqueue 2.Dequeue 3.display 4.exit
Enter your choice:4

*/
//Start writing program from here
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

struct Job {
    char name;
    int priority;
};

struct PriorityQueue {
    struct Job arr[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct PriorityQueue *pq) {
    pq->front = -1;
    pq->rear = -1;
}

int isEmpty(struct PriorityQueue *pq) {
    return (pq->front == -1);
}

int isFull(struct PriorityQueue *pq) {
    return (pq->rear == MAX_SIZE - 1);
}

void enqueue(struct PriorityQueue *pq, char jobName, int jobPriority) {
    if (isFull(pq)) {
        printf("queue is full\n");
        return;
    }

    if (isEmpty(pq)) {
        pq->front = pq->rear = 0;
        pq->arr[0].name = jobName;
        pq->arr[0].priority = jobPriority;
    } else {
        int i;
        for (i = pq->rear; i >= pq->front; i--) {
            if (jobPriority > pq->arr[i].priority) {
                pq->arr[i + 1] = pq->arr[i];
            } else {
                break;
            }
        }

        pq->arr[i + 1].name = jobName;
        pq->arr[i + 1].priority = jobPriority;
        pq->rear++;
    }

    //printf("Job '%c' with priority %d enqueued successfully.\n", jobName, jobPriority);
}

struct Job dequeue(struct PriorityQueue *pq) {
    struct Job emptyJob;
    emptyJob.name = '\0';
    emptyJob.priority = -1;

    if (isEmpty(pq)) {
        printf("queue is empty\n");
        return emptyJob;
    }

    struct Job dequeuedJob = pq->arr[pq->front];
    if (pq->front == pq->rear) {
        pq->front = pq->rear = -1;
    } else {
        pq->front++;
    }

    return dequeuedJob;
}

void display(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("queue is empty.\n");
        return;
    }

    printf("Job Name\tPriority\n");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("    %c     \t   %d\n", pq->arr[i].name, pq->arr[i].priority);
    }
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    int choice;
    char jobName;
    int jobPriority;

    do {
       /* printf("1.Enqueue ");
        printf("2.Dequeue ");
        printf("3.Display ");
        printf("4.Exit ");
        printf("\nEnter your choice: ");*/
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //printf("Enter the job name(eg:m) and priority:");
                scanf(" %c", &jobName);
                //printf("Enter the job priority: ");
                scanf("%d", &jobPriority);
                enqueue(&pq, jobName, jobPriority);
                break;
            case 2: {
                struct Job dequeuedJob = dequeue(&pq);
                if (dequeuedJob.name != '\0') {
                    printf("deleted element is '%c' with priority is %d\n", dequeuedJob.name, dequeuedJob.priority);
                }
                break;
            }
            case 3:
                display(&pq);
                break;
            case 4:
                //printf("Exiting the program.\n");
                
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
