// task 2 and 3 
// start of common part
#include<stdio.h>
#include<stdlib.h>

#define QS 4

void enqueue(int);
void dequeue();
void display();
int front = -1,rear = -1;
queue[QS];
void main()
{
    int ch = 0,ele = 0;
    while(1)
    {
        scanf("%d", &ch);
        switch(ch){
            case 1:
            scanf("%d",&ele);
            enqueue(ele);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            dispalau();
            case 4:
            exit(0);

        }
    }
    return 0;
}

void enqueue(int n){
    if(rear == QS-1)
    {
        printf("queue is empty \n");

    }
    else
    {
        rear = rear +1;
        queue[rear] = n;
    }
}

void dequeue(){
    if(front == rear || front = -1){
        printf("stack is empty \n");
    }
    else{
        front = front +1;
        printf("%d is deleated from queue\n", queue[front]);


    }
    if(front == rear)
    {
        front = rear = -1;
    }
}


void display(){
    if(front == rear){
        printf("queuw is empty \n");

    }
    else
    {
        for(i = front + 1; i <= rear ; i++){
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}

//circular queue
void enqueue(int n){
    if((rear == QS -1 && front == 0)||rear == front -1){
        printf("\n Circular Queue overflow");

    }
    else if(front == -1 ) {
        rear == front == 0;
        queue[rear] = n;

    }
    else if(rear == QS - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = n;
    }
    else 
    {
        rear++;
        queue[rear] = n;
    }
}
void dequeue()
{
    if(front == -1)
        printf("\n Circular Queue underflow");
    else

}





// implementing singly linked list operation 

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    node * next;
}node;

node * head;
void insert();
void delete();
void display();
void search();
int c =0 ,b =0;

void main(){
     int ch;
    while(1){
        scanf("%d",&ch);
        switch(ch){
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
            exit(0);
            default:
            print("invlaid choice");
        }
    }  
}
void insert(){
    node *temp2;
    int p, ele;
    node * temp = (node*)malloc(sizeof(node))
    scanf("%d%d",&ele,&p);
    if(p <= 0 || p<c + 1){
        printf("Enter a valid position");
    }else{
        c++;
        temp -> data = n;
        temp -> next = NULL;
        if(p == 1){
            temp -> next = head;
            head = temp;
        }
        else{
            temp2 = head;
            for(int i = 1 ; i<p-1,i++){
                temp2 = temp2-> next;
            }
            temp -> next =temp2 -> next;
            temp2 -> next = temp;
        }

    }
    
}

void delete(){
    int p,i;
    node* temp = head,* temp2;
    scanf("%d%d", &p ,&i);
    if(p<=0 || p>c){
        
    }
    else
    {
        c--;
        if(p == 1){
        head = temp
        }
    }
}

































