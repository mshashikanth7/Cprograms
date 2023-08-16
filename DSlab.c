/*
LAB TASK 1
QUESTION: 1a-Implement Bubble sort using a C program.

INPUT FORMAT:
FIRST LINE CONTAINS "n" NO OF ELEMENTS
SECOND LINE CONTAINS "n" integers seperated by a space

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE

Test Cases:

case = t4
input = 5
5 4 3 2 1
output =
Unsorted List
5	4	3	2	1
BUBBLE SORT
Sorted List
1	2	3	4	5

*/
// Start writing program from here
#include <stdio.h>
void bubbleSort();
void main()
{
    int a[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nBUBBLE SORT\n");
    printf("Sorted List\n");

    bubbleSort(n, a);
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
}
void bubbleSort(int m, int a[])
{
    int temp;
    for (int turn = 0; turn < m; turn++)
    {
        for (int j = 0; j < m - turn; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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
LAB TASK 1
QUESTION: 1b-Implement Selection sort using a C program.

INPUT FORMAT:
FIRST LINE CONTAINS "n" NO OF ELEMENTS
SECOND LINE CONTAINS "n" integers seperated by a space

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE

Test Cases:
case = t1
input = 6
-1 6 -45 -8 0 4
output =
Unsorted List
-1	6	-45	-8	0	4
SELECTION SORT
Sorted List
-45	-8	-1	0	4	6

*/
// Start writing program from here
#include <stdio.h>
void selectionSort();
void main()
{
    int a[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nSELECTION SORT\n");
    printf("Sorted List\n");

    selectionSort(n, a);
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
}
void selectionSort(int n, int a[])
{
    int i, j, min, index, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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
/* LAB TASK 1
QUESTION: 1c-Implement Insertion sort using a C program.

INPUT FORMAT:
FIRST LINE CONTAINS "n" NO OF ELEMENTS
SECOND LINE CONTAINS "n" integers seperated by a space

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE

Test Cases:
case = t1
input = 6
-1 6 -45 -8 0 4
output =
Unsorted List
-1	6	-45	-8	0	4
INSERTION SORT
Sorted List
-45	-8	-1	0	4	6
*/
// Start writing program from here

#include <stdio.h>

void insertionSort(int n, int a[]);

void main()
{
    int a[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nINSERTION SORT\n");
    printf("Sorted List\n");
    insertionSort(n, a);
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
}

void insertionSort(int n, int a[])
{
    int i, j, index;
    for (i = 1; i < n; i++)
    {
        index = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > index))
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = index;
    }
}
/*

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
LAB TASK 2
QUESTION: 2a-Develop a C program for Quick sort.

INPUT FORMAT:
FIRST LINE CONTAINS "n" NO OF ELEMENTS
SECOND LINE CONTAINS "n" integers seperated by a space

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE

Test Cases:
case = t1
input = 6
-1 6 -45 -8 0 4
output =
Unsorted List
-1	6	-45	-8	0	4
QUICK SORT
Sorted List
-45	-8	-1	0	4	6
*/
// Start writing program from here

#include <stdio.h>
void quickSort(int[], int, int);

int main()
{
    int n, i, a[10];
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
    quickSort(a, 0, n - 1);
    printf("\nQUICK SORT\n");

    printf("Sorted List\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
void quickSort(int a[], int left, int right)
{
    int pivot, t, i, j, l, r, temp;
    if (left < right)
    {
        pivot = a[left];
        l = left;
        r = right;
        while (l < r)
        {
            while (a[i] <= pivot && i < right)
                l++;
            while (a[r] > pivot)
                r--;
            if (l < r)
            {
                t = a[l];
                a[l] = a[r];
                a[r] = t;
            }
        }

        temp = a[left];
        a[left] = a[r];
        a[r] = temp;

        quickSort(a, left, r - 1);
        quickSort(a, r + 1, right);
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
 LAB TASK 2
 QUESTION: 2B-Demonstrate Merge sort using a C program.

 INPUT FORMAT:
 FIRST LINE CONTAINS "n" NO OF ELEMENTS
 SECOND LINE CONTAINS "n" integers seperated by a space

 OUTPUT FORMAT:
 DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE

 Test Cases:
 case = t1
 input = 6
 -1 6 -45 -8 0 4
 output =
 Unsorted List
 -1	6	-45	-8	0	4
 MERGE SORT
 Sorted List
 -45	-8	-1	0	4	6
 */
// Start writing program from here
#include <stdio.h>
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
    int a[10], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\nMERGE SORT\n");
    mergeSort(a, 0, n - 1);

    printf("Sorted List\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}
void mergeSort(int a[], int l, int r)
{

    if (l < r)
    {

        // mid = l + ((r-l)/2);
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

void merge(int a[], int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
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
LAB TASK 2
QUESTION: 2C- Design a C program for Radix Sort.

INPUT FORMAT:
FIRST LINE CONTAINS "n" NO OF ELEMENTS
SECOND LINE CONTAINS "n" integers seperated by a space

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE

Test Cases:
case = t1
input = 6
502 674 175 542 874 245
output =
UNSORTED LIST
502	674	175	542	874	245
RADIX SORT
SORTED LIST
175	245	502	542	674	874
*/
// Start writing program from here

#include <stdio.h>
int getmax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
void countingsort(int a[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}
void radixsort(int a[], int n)
{
    int m = getmax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countingsort(a, n, exp);
    }
}
int main()
{
    int a[10], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\nRADIX SORT\n");
    radixsort(a, n);

    printf("SORTED LIST\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
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
/*4a. Write a C program to implement INFIX TO POSTFIX conversion.

case = t1
input = a+b*c-(d/e+f*g*h)
output = abc*+de/fg*h*+-

case = t2
input = a-b/(c*d+e)
output = abcd*e+/-

case = t3
input = (2+3)
output = 23+

case = t4
input = (a+b)*c
output = ab+c*
*/
// Start writing program from here

#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = -1;

void push(char[], char);
char pop(char[]);
int getpriority(char);

void main()
{
    char infix[100], postfix[100], temp;
    int i, j = 0;

    //  printf("enter any infix exp");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            push(stack, infix[i]);
        else if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
        {
            while (getpriority(stack[top]) >= getpriority(infix[i]))
            {
                postfix[j] = pop(stack);
                j++;
            }
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {

            while (stack[top] != '(')
            {
                postfix[j] = pop(stack);
                j++;
            }
            temp = pop(stack);
        }
    }

    while ((top != -1))
    {
        postfix[j] = pop(stack);
        j++;
    }
    postfix[j] = '\0';
    printf(" %s", postfix);
}
void push(char stack[], char element)
{
    if (top == STACK_SIZE - 1)
    {
        printf("stackoverflow");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}
char pop(char stack[])
{
    char val;
    if (top == -1)
        printf("underflow");
    else
    {
        val = stack[top];
        top--;
    }
    return val;
}
int getpriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
    else
    {
        return -1;
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
/*4b. Write a C program to evaluation postfix expression.

Test Case example:

Input=982+-
Output=
value of the postfix expression=-1.00
*/
// Start writing program from here
#include <stdio.h>
#include <ctype.h>
#define STACK_SIZE 100

float stack[STACK_SIZE];
int top = -1;
void push(float[], float);
float pop(float[]);

void main()
{
    int i;
    float op1, op2, value, result;
    char exp[100];
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(stack, (float)(exp[i] - '0'));
        }
        else
        {
            op2 = pop(stack);
            op1 = pop(stack);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(stack, value);
        }
    }
    result = pop(stack);
    printf("value of the postfix expression=%.2f", result);
}
void push(float stack[], float value)
{
    if (top == STACK_SIZE - 1)
        printf("\n stack overflow");
    else
    {
        top++;
        stack[top] = value;
    }
}
float pop(float stack[])
{
    float val;
    if (top == -1)
    {
        printf("\n stack underflow");
    }
    else
    {
        val = stack[top];
        top--;
    }
    return val;
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

/*6. Write a C program to implement Singly Linked List operations. 

Test Case examples:
Case=t1
Input=
1                                                                               
10                                                                              
20                                                                              
30                                                                              
40                                                                              
0                                                                               
2                                                                           
7
Output=
The Created List is                                                             
10->20->30->40->
*/
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
void display();
void search();
int reverse(struct node *);
int c = 0, b = 0;

int main()
{
    int ch;
    head = NULL;
    while (1)
    {
        printf("\n1.INSERT\t2.DELETE.\t3.Display\t4.SEARCH\t5.reverse\t6.exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            reverse(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}

void insert()
{
    int n, p, i;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp2;
    printf("\nEnter the element and its position:");
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
    struct node *temp1 = head, *temp2;
    printf("\nEnter the position from which data has to be removed:");
    scanf("%d", &p);
    if (p <= 0 || p > c)
        printf("\nEnter a valid position");
    else
    {
        c--;
        if (p == 1)
        {
            head = temp1->next;
            free(temp1);
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
    printf("\nEnter the element to be searched:");
    scanf("%d", &n);
    x = head;
    while (x != NULL)
    {
        p++;
        if (x->data == n)
        {
            b = 1;
            break;
        }
        x = x->next;
    }
    if (b == 1)
        printf("%d is found at position %d", x->data, p);
    else
        printf("%d element not found", n);
}

void display()
{
    struct node *x;
    x = head;
    if (x == NULL)
    {
        printf("SLL is empty");
        return;
    }
    while (x != NULL)
    {
        printf("%d-> ", x->data);
        x = x->next;
    }
}

void reverse(struct node *list)
{
    if (list == NULL)
    {
        return;
    }

    reverse(list->next);
    printf("%d->", list->data);
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
/* 8. Write a C program to implement Doubly Linked List operations.

Test Case example:

input=
1
12 1
1
45 2
1
34 1
3
2
2
3
5
output =
FORWARD Traversal: 34 12 45
BACKWARD Traversal: 45 12 34
FORWARD Traversal: 34 45
BACKWARD Traversal: 45 34
*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *head;
void insert();
void delete();
void display();
void search();
int c = 0, b = 0;
void main()
{
    int a, ch;
    head = NULL;
    while (1)
    {
        // printf("\n1.INSERT\t2.DELETE.\t3.Display\t4.SEARCH\t5.exit");
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
        temp->pre = NULL;
        if (head == NULL)
            head = temp;
        else if (p == 1)
        {
            x = head;
            x->pre = temp;
            temp->next = x;
            head = temp;
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
            temp->pre = temp2;
            if (p != c)
            {
                temp2 = temp->next;
                temp2->pre = temp;
            }
        }
    }
}
void delete()
{
    int p, i;
    struct node *temp1 = head, *temp2;
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
            if (c != 0)
            {
                temp2 = temp1->next;
                temp2->pre = temp1->pre;
            }
            free(temp1);
        }
        else
        {
            for (i = 1; i < p - 1; i++)
            {
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = temp2->next;
            if (p != c + 1) // if u deleting the element in between the other elements
            {
                temp1 = temp2->next;
                temp1->pre = temp2->pre;
            }
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
    if (head == NULL)
    {
        printf("DLL is empty");
        return;
    }
    x = head;
    while (x != NULL)
    {
        p++;
        if (x->data == n)
        {
            b = 1;
            break;
        }
        x = x->next;
    }
    if (b == 1)
        printf("%d found at position %d", x->data, p);
    else
        printf("element not found");
}
void display()
{
    int i;
    struct node *x, *y;
    if (head == NULL)
    {
        printf("DLL is empty");
        return;
    }
    x = head;
    y = head;
    printf("\nFORWARD Traversal: ");
    while (x != NULL)
    {
        printf("%d ", x->data);
        x = x->next;
    }
    printf("\nBACKWARD Traversal: ");
    for (i = 1; i < c; i++)
    {
        y = y->next;
    }
    while (y != NULL)
    {
        printf("%d ", y->data);
        y = y->pre;
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
    struct node *display = (struct node *)malloc(sizeof(struct node));
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
/*
LAB TASK 10
QUESTION: 10- a. Implement the following operations on Binary Search Tree
 i. create ii. insert iii. search iv. delete.

Test cases:
case = t1
input=
1
35
1
13
1
56
1
12
1
27
2
13
4
5
output=
12->27->56->35->

case = t2
Input=1
15
1
10
1
23
2
10
4
3
10
1
23
4
5
output=
23->15->
10 element not found
23->23->15->
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
LAB TASK 11
QUESTION: 11.Implement the following operations on Binary Search Tree i. count-nodes ii. height iii. minimum node iv. maximum node

Test cases:
case =t1
Input=1
45
1
34
1
12
2
3
4
5
6
Output=
Number of nodes in BST is 3
Height of BST is 3
Minimum Value in BST is 12
Maximum Value in BST is 45
Maximum Value in BST is 80
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
LAB TASK 13
QUESTION: 13a. Write a C program to implement Adjacency Matrix of a given graph.

Test Cases:
case = t1
input = 4
0 1 1 0 1 0 1 1 1 1 0 1 0 1 1 0
output =

ADJACENCY MATRIX OF GRAPH G
VERTEX 0 : 0 1 1 0
VERTEX 1 : 1 0 1 1
VERTEX 2 : 1 1 0 1
VERTEX 3 : 0 1 1 0

*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void getgraph();
void printgraph();
int G[MAX][MAX];
int n, i, j;
void main()
{
    scanf("%d", &n);
    int G[n][n];
    getgraph(G);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    printgraph(G);
}

void getgraph(int G[n][n])
{

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }
}
void printgraph(int G[n][n])
{
    int i, j;
    printf("ADJACENCY MATRIX OF GRAPH G");
    for (i = 0; i < n; i++)
    {
        printf("\nVERTEX %d : ", i);
        for (j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
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
LAB TASK 13
QUESTION: 13 B- Write a C program to implement Adjacency List of a given graph.
Test Cases:
case = t1
input = 4 5
0 1
0 2
0 3
1 2
2 3
output =
ADJACENCY LIST OF GRAPH G

Vertex 0: 3 -> 2 -> 1 ->
Vertex 1: 2 -> 0 ->
Vertex 2: 3 -> 1 -> 0 ->
Vertex 3: 2 -> 0 ->
*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct node *createNode(int);
struct Graph
{
    int numVertices;
    struct node **adjLists;
};
struct Graph *createGraph(int);
void addEdge(struct Graph *, int, int);
void printGraph(struct Graph *);

void main()
{

    struct Graph *graph;
    int i, no_of_vertices, no_of_edges, src, dest;

    scanf("%d%d", &no_of_vertices, &no_of_edges);
    graph = createGraph(no_of_vertices);

    for (i = 0; i < no_of_edges; i++)
    {
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);
}

struct node *createNode(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->vertex = n;
    temp->next = NULL;
    return temp;
}

struct Graph *createGraph(int n)
{
    struct Graph *temp = (struct Graph *)malloc(sizeof(struct Graph));

    temp->numVertices = n;
    temp->adjLists = (struct node **)malloc(n * sizeof(struct node *));

    for (int i = 0; i < n; i++)
        temp->adjLists[i] = 0;

    return temp;
}

void addEdge(struct Graph *graph, int s, int d)
{
    struct node *temp;

    temp = createNode(d);
    temp->next = graph->adjLists[s];
    graph->adjLists[s] = temp;

    temp = createNode(s);
    temp->next = graph->adjLists[d];
    graph->adjLists[d] = temp;
}

void printGraph(struct Graph *graph)
{
    printf("ADJACENCY LIST OF GRAPH G\n");

    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = graph->adjLists[i];
        printf("\nVertex %d: ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
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
/*14a. Write a C program to implement traverse the graph in DFS order.

Test Case example:

input= 5
0 1 1 1 0
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
0 1 1 1 0
1
output=
1 2 5 3 4


*/
// Start writing program from here
#include <stdio.h>
void dfs(int);
int G[10][10], visited[10], n, s;
void main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    for (i = 1; i <= n; i++)
        visited[1] = 0;
    scanf("%d", &s);
    dfs(s);
}

void dfs(int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for (j = 1; j <= n; j++)
        if ((visited[j] == 0) && G[i][j] == 1)
            dfs(j);
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

/*14 b. Write a C program to traverse the graph in BFS order.

Test Case example:

input= 5
0 1 1 1 0
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
0 1 1 1 0
3
output=
3 1 5 2 4


*/
// Start writing program from here
#include <stdio.h>

int q[20], front = -1, rear = -1, a[20][20], vis[20];
int delete();
void add(int item);
void bfs(int s, int n);

void main()
{
    int n, i, s, j;
    // printf("ENTER THE NUMBER VERTICES ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    // printf("THE ADJACENCY MATRIX IS\n");

    for (i = 1; i <= n; i++)
        vis[i] = 0;

    // printf("\n ENTER THE SOURCE VERTEX :");
    scanf("%d", &s);
    bfs(s, n);
}
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
        printf(" %d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf(" %d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}

void add(int item)
{
    if (rear == 19)
        printf("QUEUE FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}
int delete()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
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
LAB TASK 15
QUESTION: 15- Design a C program for level order traversal of a Binary Search Tree.

Test Cases:
case = t1
Input=1
23
1
45
1
22
1
17
1
34
1
56
4
2
45
3
22
5
Output=
1.Insert
2.delete
3.search
4.display
5.quit
23 inserted at arr[3]
45 inserted at arr[0]
22 inserted at arr[2]
Collision at hash table cannot insert the element
34 inserted at arr[4]
56 inserted at arr[1]
hash table is:
arr[0] = 45
arr[1] = 56
arr[2] = 22
arr[3] = 23
arr[4] = 34
56 inserted at arr[1]
hash table is:
arr[0] = 45
arr[1] = 56
arr[2] = 22
arr[3] = 23
arr[4] = 34
deleting value 45
after deletion hash table is:
arr[0] = -1
arr[1] = 56
arr[2] = 22
arr[3] = 23
arr[4] = 34
searching value 22...
key Found
case = t2
Input=1
43
1
36
1
54
1
87
1
56
4
2
36
3
67
5

Output=
1.Insert
2.delete
3.search
4.display
5.quit
43 inserted at arr[3]
36 inserted at arr[1]
54 inserted at arr[4]
87 inserted at arr[2]
Collision at hash table cannot insert the element
hash table is:
arr[0] = -1
arr[1] = 36
arr[2] = 87
arr[3] = 43
arr[4] = 54
deleting value 36
after deletion hash table is:
arr[0] = -1
arr[1] = -1
arr[2] = 87
arr[3] = 43
arr[4] = 54
searching value 67...
key doesn't exist





*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>
#define size 5
int arr[size];
void init();
void insert(int value);
void delete(int value);
void search(int value);
void display();
void main()
{
    int ch;
    int no = 0;
    init();
    printf("1.Insert\n2.delete\n3.search\n4.display\n5.quit\n");
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &no);
            insert(no);
            break;
        case 2:
            scanf("%d", &no);
            printf("deleting value %d\n", no);
            delete (no);
            printf("after deletion hash table is : \n");
            display();
            break;
        case 3:
            scanf("%d", &no);
            printf("searching value %d...\n", no);
            search(no);
            break;
        case 4:
            printf("hash table is : \n");
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}
void init()
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = -1;
}
void insert(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
        printf("Collision at hash table cannot insert the element\n");
}
void delete(int value)
{
    int key = value % size;
    if (arr[key] == value)
        arr[key] = -1;
    else
        printf("%d element not present in hash table\n", value);
}
void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
        printf("key Found\n");
    else
        printf("key doesn't exist\n");
}
void display()
{
    int i;
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}
