#include<stdio.h>
struct node
{
 int data;
 struct node *next;
}*start=NULL;
void create();
void insert_after();
void delete_after();
void display();
struct node *search(int);
/// @brief 
void main()
{
struct node *ptr;
int ch,key;
while(1)
{
printf("\nMAIN MENU\n");
printf("1.create\n 2.Insert After\n3.Delete After\n4.print \n5.search\n 6.exit");
printf("Enter Choice");
scanf("%d",&ch);
switch(ch)
{
case 1: create();
 break;
case 2 :insert_after();
break;
case 3: delete_after();
 break;
case 4: display();

break;
case 5: printf("Enter Key element");
 scanf("%d",&key);
 ptr=search(key);
 if(ptr==NULL)
 printf("key is not found");
 else
 printf("key is found");
case 6: exit(0);
default:printf("invalid option");
}
}
}

void create()
{
struct node *ptr,*new_node;
int ele;
printf("Enter -1 to end the list \nEnter element");
scanf("%d",&ele);
while(ele!=-1)
{ new_node=(struct node *)malloc(sizeof(struct node));
 new_node->data=ele;
 new_node->next=NULL;
if(start==NULL)
 start=new_node;
else
{
 ptr=start;
 while(ptr->next!=NULL)
 ptr=ptr->next;
 ptr->next=new_node;
}
printf("Enter -1 to end the list \nEnter element");
scanf("%d",&ele);
}
}
void insert_after()
{
struct node *keyptr,*newnode;
int ele,key;
printf("\nEnter nEnter element");
scanf("%d",&ele);
printf("\nEnter the key element");
scanf("%d",&key);
newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=ele;
 keyptr= search(key);
 if(keyptr==NULL)
 printf("\nKey is not found");
 else
 {
 newnode->next=keyptr->next;
 keyptr->next=newnode;
 }
}
 
struct node* search(int key)
{
 struct node *ptr;
 ptr=start;
 while(ptr!=NULL)
 
{
 if(ptr
->data==key)
 return ptr;
 ptr=ptr->next;
 
}
 return NULL; }
void display() {
 struct node *ptr;
 ptr=start;
 if(ptr==NULL)
 printf("\n list is empty");
 else
 
{
 while(ptr!=NULL)
 
{
 printf("%5d->",ptr->data);
 ptr=ptr->next;
 
}
 
}
}
void delete_after() {
 struct node *keyptr,*Aptr;
 int key;
 printf("\nEnter the key element");
 scanf("%d",&key);
 keyptr= search(key);
 if(keyptr==NULL)
 printf("\nKey is not found");
 else
 
{
 Aptr=keyptr->next;
 keyptr->next=Aptr->next;
 free(Aptr);
 
}
}
