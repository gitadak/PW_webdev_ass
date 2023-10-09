//QUEUE using array
#include<stdio.h>
#define size 10

struct queue
{
	int data[size];
	int front;
	int rear;
}q;

void Enqueue(int item)
{
	if(q.rear==size-1)
	{
		printf("Queue overflow\n");
		return;
	}
	if(q.front==-1)
		q.front=0;
	q.data[++q.rear]=item;
}

int Dequeue()
{
	int y;
	if(q.front==-1)
	{
		printf("Queue underflow\n");
		return 0;
	}
	y=q.data[q.front];
	if(q.front==q.rear)
	{
		q.front=-1;
		q.rear=-1;
	}
	else
		q.front++;
	return y;
}

void display()
{
	int i;
	printf("\nQueue:\n");
	if(q.front==-1)
	{
		printf("Empty Queue\n");
		return;
	}
	printf("Front=%d    Rear=%d\n",q.front,q.rear);
	for(i=q.front;i<=q.rear;i++)
		printf("%3d",q.data[i]);
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
		}
	}while(ch!=4);
	return 0;
}
