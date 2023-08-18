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
