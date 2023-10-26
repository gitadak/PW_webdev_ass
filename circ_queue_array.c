#include<stdio.h>
#define size 3

struct queue
{
    int data[size];
    int front;
    int rear;
};
typedef struct queue queue;
queue q;

void Enqueue(int d)
{
    if(q.front==(q.rear+1)%size)
    {
        printf("\nQueue is full");
        return;
    }
    if(q.front==-1)
        q.front=0;
    q.rear=(q.rear+1)%size;
    q.data[q.rear]=d;
    return;
}

int Dequeue()
{
    int m;
    if(q.front==-1)
    {
        printf("\nEmpty Queue");
        return 0;
    }
    m=q.data[q.front];
    if(q.rear==q.front)
    {
        q.front=-1;
        q.rear=-1;
    }
    else
        q.front=(q.front+1)%size;
    return(m);
}

void display()
{
    int i;
    printf("\nQueue:");
    if(q.front!=-1)
    {
        printf("\nFront = %d    Rear = %d\n",q.front,q.rear);
        for(i=q.front;i!=q.rear;i=(i+1)%size)
            printf("%d\n",q.data[i]);
        printf("%d\n",q.data[q.rear]);
    }
    return;
}

int main()
{
	int ch,item;
	q.front=-1;
	q.rear=-1;
	do
	{
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. EXIT\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d",&item);
				Enqueue(item);
				display();
				break;
			case 2:
				printf("Popped item: %d",Dequeue());
				display();
				break;
			case 3:
				display();
                break;
		}
	}while(ch!=4);
	return 0;
}