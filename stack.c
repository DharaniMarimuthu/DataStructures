#include<stdio.h>
#define SIZE 5
int stack[SIZE],top=-1;
void push(int);
void pop();
int peek();
void traverse();
void main()
{
    int choice,ele,peak;
    while(1)
    {
   printf("\n1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.Exit\n\n");
   printf("\nEnter your choice\n");
   scanf("%d",&choice);
   switch(choice)
   {
       case 1:
           printf("Enter element to push\n");
           scanf("%d",&ele);
           push(ele);
           break;
       case 2:pop();
       break;
       case 3:peak=peek();
       if(peak==-1)
       {
           printf("Stack is empty\n");
       }
       else
       {
           printf("Peek is %d \n",peak);
       }break;
       case 4:traverse();break;
       case 5:exit(0);
       default:printf("Invalid choice\n");
   }
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if(top==SIZE-1)
    {
       return 1;
    }
    else
    {
     return 0;
    }
}
void push(int ele)
{
    if(isFull())
    {
        printf("Stack overflows\n");
    }
    else
    {
        top++;
        stack[top]=ele;
        printf("Pushed %d\n",ele);
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack underflows\n");
    }
    else
    {
        printf("%d popped successfully\n",stack[top]);
        top--;
    }
}
int peek()
{
   if(isEmpty())
   {
       return -1;
   }
   else
   {
       return stack[top];
   }
}
void traverse()
{
    int i;
    if(isEmpty())
    {
        printf("No elements in stack\n");
    }
    else
    {
        printf("The stack elements are\n");
        for(i=top;i>=0;i--)
    {
        printf("%d\t\n",stack[i]);
    }
}
}
