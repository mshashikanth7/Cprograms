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

#include<stdio.h>

void quickSort(int [], int ,int);

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
    int pivot,l,j,temp;
    if(left < right)
    {
        pivot = a[left];
        l = left;
        j = right;
        while(l<j)
        {
            while((a[l] <= pivot) && (l < right)){
                l++;
            while(a[j] >pivot)
                j++;
                if(l<j)
                {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;    
                }
            }
            temp = a[l];
            a[l] = a[j];
            a[j] = temp;

            quickSort(a,left,j-1);
            quickSort(a,j+1,right);
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
void mergesort(int a[], int, int);
void merge(int a[], int, int, int);
int x;
int main()
{
    int a[10], i, n;
    // printf("enter n");
    scanf("%d", &n);
    // printf("enter");
    x = n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("THE  UNSORTED LIST\n");
    for (i = 0; i < n; i++)
        printf("%5d", a[i]);

    mergesort(a, 0, n - 1);

    printf("\nTHE  SORTED LIST - MERGE SORT\n");
    for (i = 0; i < n; i++)
        printf("%5d", a[i]);
}
void mergesort(int a[], int low, int high)
{
    int mid, i;
    if (low < high) // 0<7   0<3   0<1
    {
        mid = (low + high) / 2; // 3   1   0

        mergesort(a, low, mid);      //(a,0,3)    (a,0,1)   (a,0,0)  // calling
        mergesort(a, mid + 1, high); //(a,4,7)   (a,2,3)   (a,1,1)//store
        merge(a, low, mid, high);    //(a,0,0,0)
        printf("\nPASS -");
        for (i = 0; i < x; i++)
            printf("%d\t", a[i]);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int b[10], h, i, j, k;
    i = low;     // 0
    j = mid + 1; // 1
    k = low;     // 0
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
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