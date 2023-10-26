//QUEUE using LinkedList
#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

typedef struct
{
    node *front;
    node *rear;
}queue;

void enqueue(int d,queue **aq)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data=d;
    newnode->next=NULL;
    if((*aq)->rear==NULL)
    {
        (*aq)->rear=newnode;
        (*aq)->front=newnode;
        return;
    }
    (*aq)->rear->next=newnode;
    (*aq)->rear=newnode;
}

int dequeue(queue **aq)
{
    int d;
    node *c;
    if((*aq)->front==NULL)
    {
        printf("\nEmpty QUEUE");
        return 0;
    }
    c=(*aq)->front;
    d=(*aq)->front->data;
    if((*aq)->front==(*aq)->rear)
    {
        (*aq)->front=NULL;
        (*aq)->rear=NULL;
    }
    else
        (*aq)->front=(*aq)->front->next;
    free(c);
    c=NULL;
    return d;
}

void display(queue *q)
{
    node *c;
    printf("\nQUEUE:\n");
    if(q->front!=NULL)
    {
        for(c=q->front;c!=q->rear;c=c->next)
            printf("%3d",c->data);
        printf("%3d",c->data);
    }
    return;
}

int main()
{
    queue *q;
    int a,d;
    q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    do
    {
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\nEnter your choice: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                printf("\nData to be inserted: ");
                scanf("%d",&d);
                enqueue(d,&q);
                display(q);
                break;
            case 2:
                d=dequeue(&q);
                printf("\nPopped element: %d",d);
                display(q);
                break;
            case 3:
                display(q);
                break;
        }
    } while (a!=4);
    return 0;
}