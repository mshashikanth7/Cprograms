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
int reverse();
int reverse(struct node *);
int c = 0, b = 0;

void main()
{
   int a, ch, flag;
   head = NULL;
   while (1)
   {
      // printf("\n1.INSERT\t2.DELETE.\t3.Display\t4.SEARCH\t5.reverse\t6.exit");
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
         flag = reverse(head);
         if (flag == 0)
            printf("SLL is empty");
         break;
      case 6:
         exit(0);
      default:
         printf("invalid choice");
      }
   }
}
void insert()
{
   int n, p, i;
   struct node *temp = (struct node *)malloc(sizeof(struct node)); // TEMP
   struct node *temp2;
   // printf("\nEnter the element and its position:");
   scanf("%d%d", &n, &p);   // 10 1     N=10   P=1
   if (p <= 0 || p > c + 1) //
      printf("Enter a valid position");
   else
   {
      c++; //  1
      temp->data = n;
      temp->next = NULL;
      if (p == 1)
      {
         temp->next = head;
         head = temp;
      }
      else // P=3
      {
         temp2 = head;
         for (i = 1; i < p - 1; i++) // i=
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
   // printf("\nEnter the position from which data has to be removed");
   scanf("%d", &p);
   if (p <= 0 || p > c)
      printf("\nenter a valid position");
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
   // printf("\nEnter the element to be searched");
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

/*void reverse()
{
    struct node *temp,*cur,*rev;
     temp=head;
     rev=NULL;
     while(temp!=NULL)
     {
          cur=rev;
          rev=temp;
          temp=temp->next;
          rev->next=cur;
     }
     head=rev;

} */
int reverse(struct node *list)
{
   if (list == NULL)
   {
      return 0;
   }

   reverse(list->next);
   printf("%d->", list->data);
}