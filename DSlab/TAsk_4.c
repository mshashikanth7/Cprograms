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