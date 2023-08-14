#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
typedef struct{
    float a[SIZE];
    int tos;
    
}S_float;

void push(S_float *s1,float ele1)
{
    if(s1->tos==SIZE-1) //check if stack is full
    {
        printf("Stack Overflow");
    }
    s1->tos++;
    printf("Pushed element is:%f",ele1);
    s1->a[s1->tos]=ele1;

}
void pop(S_float *s1)
{
    if(s1->tos==-1) //check if stack is empty
    {
        printf("Stack Underflow");
        return;
    }
    float x;
    s1->a[s1->tos--]=x; //decrement stack after passing value of x
    printf("Popped element=%f",x);
}
void peek(S_float s1)
{
    printf("The top element is %f",s1.a[s1.tos]);//print topmost element
}
void display(S_float s1)
{
    int i;
    for(i = s1.tos; i>=0 ; i--)  
    {
        printf("%f\t",s1.a[i]);
    }

}
int main()
{
    S_float s;//s is variable of type stack
    s.tos=-1;
    int option; 
    char a;
    float ele;
    do
    {
        printf("Enter 1 for Push \n2 for Pop\n3 for peek\n4 for display\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:printf("Enter element to be pushed:");
               scanf("%f",&ele);
               push(&s,ele); //call push function
            break;
        case 2:pop(&s);
            break;
        case 3:peek(s);
            break;
        case 4:display(s);
            break;
        
        default:printf("Invalid choice");
        
        }
        printf("Do you wish to continue? Press y or Y");
        scanf("%c",a);
    } while (a=="y"||a=="Y");
    


    return 0;
}