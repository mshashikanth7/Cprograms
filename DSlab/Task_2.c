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
        while(l<j){
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