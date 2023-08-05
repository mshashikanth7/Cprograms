#include<stdio.h>
#include<stdlib.h>
struct slinklist
{
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;

node* start = NULL;

int menu()
{ 
 int ch;

printf("\n 1.Create a list "); 
 printf("\n--------------------------"); 
printf("\n 2.Insert a node at beginning "); 
printf("\n 3.Insert a node at end"); 
printf("\n 4.Insert a node at middle"); 
 printf("\n--------------------------"); 
printf("\n 5.Delete a node from beginning"); 
printf("\n 6.Delete a node from Last"); 
printf("\n 7.Delete a node from Middle"); 
 printf("\n--------------------------"); 
printf("\n 8.Traverse the list (Left to Right)"); 
printf("\n 9.Traverse the list (Right to Left)"); 
//Lecture Notes 38 Dept. of Information Technology 
 printf("\n--------------------------"); 
printf("\n 10. Count nodes "); 
printf("\n 11. Exit "); 
printf("\n\n Enter your choice: "); 
 scanf("%d",&ch); 
 return ch; 
} 

node *getnode()
{
    node * newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode -> data)
    newnode -> next = NULL;
    return newnode;

}

int countnode(node *ptr)
{
    int count =0;
    while(ptr != 0){
    count++
    ptr = ptr -> next;
    }
    return(count);
}

void creatlist(int n)
{
    int i;
    node* newnode;
    node* temp;
    for(i = 0;i < n;i++)
    {
        newnode = getnode();
        newnode -> next = NULL;
    }
}