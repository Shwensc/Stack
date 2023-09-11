#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
typedef struct
{
    int tos;
    char a[SIZE];
} Bracket;

void push(Bracket *b, char ele)
{

    if (b->a[b->tos] == SIZE - 1)
    {
        printf("Stack overflow");
        exit(-1);
    }
    b->a[++b->tos] = ele;
}

char pop(Bracket *b)
{
    char ele;
    if (b->a[b->tos] == -1)
    {
        printf("Stack underflow");
        exit(-2);
    }
    ele = b->a[b->tos];
    b->a[b->tos--];
    return ele;
}

int isEmpty(Bracket b)
{
    return (b.tos==-1);
}
int main()
{
    Bracket b1;
    b1.tos = -1;
    char x;
    char input[SIZE];
    printf("Enter expression:\n");
    gets(input);
    printf("Current expression:%s\n", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            push(&b1, input[i]); /*if opening bracket, then pus onto stack*/
        }
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            x = pop(&b1);                            /*closing brcket then pop tos to check
                                                element*/
             if (input[i] == ')' && x != '(' || input[i] == ']' && x != '[' || input[i] == '}' && x != '{')
            {
                printf("Not a balanced expression"); /*if element is differentopening bracket than current closing bracket
                                                    then stop and print invalid expression{}*/
                exit(-3);
            }
        
        }
        
    }
        if(!isEmpty(b1))
        {
            printf("Invalid expression\n");
            exit -1;  //if element is popped and no further element to be compared with
        } 
        else 
        printf("It is a valid expression");

    return 0;
}