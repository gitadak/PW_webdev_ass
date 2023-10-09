//STACK using array
#include<stdio.h>
#define size 10
struct stack
{
	int data[size];
	int top;
}s;

void push(int item)
{
	if(s.top==size-1)
	{
		printf("Stack overflow\n");
		return;
	}
	s.data[++s.top]=item;
}

int pop()
{
	int y;
	if(s.top==-1)
	{
		printf("Stack underflow\n");
		return 0;
	}
	y=s.data[s.top--];
	return y;
}

void peek()
{
	int i;
	printf("\nStack:\n");
	if(s.top==-1)
	{
		printf("Empty Stack\n");
		return;
	}
	for(i=s.top;i>=0;i--)
		printf("%d\n",s.data[i]);
}

int main()
{
	int ch,item;
	s.top=-1;
	do
	{
		printf("\n1. PUSH\n2. POP\n3. PEEK\n4. EXIT\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d",&item);
				push(item);
				peek();
				break;
			case 2:
				printf("Popped item: %d",pop());
				peek();
				break;
			case 3:
				peek();
		}
	}while(ch!=4);
	return 0;
}
