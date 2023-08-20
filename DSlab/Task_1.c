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

void  insertionSort(int n, int a[]);

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
