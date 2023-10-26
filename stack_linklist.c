//STACK using LinkedList
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack stack;

stack* push(stack *top,int d)
{
    stack *newnode;
    newnode=(stack*)malloc(sizeof(stack));
    newnode->data=d;
    newnode->next=top;
    top=newnode;
    return top;
}

int pop(stack **atop)
{
    int x;
    stack *c;
    if(*atop==NULL)
    {
        printf("\nSTACK underflow");
        return 0;
    }
    c=*atop;
    x=(*atop)->data;
    *atop=(*atop)->next;
    free(c);
    c=NULL;
    return x;
}

void peek(stack *top)
{
    stack *c;
    printf("\nSTACK:");
    for(c=top;c!=NULL;c=c->next)
        printf("\n%5d",c->data);
    return;
}

int main()
{
    stack *top=NULL;
    int n,c,d;
    do
    {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. EXIT\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\nData: ");
                scanf("%d",&d);
                top=push(top,d);
                peek(top);
                break;
            case 2:
                d=pop(&top);
                printf("\nThe Popped element: %d",d);
                peek(top);
                break;
            case 3:
                peek(top);
                break;
        }
    } while (c!=4);
    return 0;
}