#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//typedef is used to declare the values
typedef struct node{
    int data;
    struct node *next; 
}node;

node *list = NULL;