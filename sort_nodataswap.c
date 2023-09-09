#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node* create(int item)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=item;
	newnode->next=NULL;
	return newnode;
}

node* insert_end(node* newnode,node* head)
{
	node *c;
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	c=head;
	while(c->next!=NULL)
		c=c->next;
	c->next=newnode;
	return head;
}

void display(node* head)
{
	node *c;
	if(head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	printf("List:\n");
	c=head;
	while(c!=NULL)
	{
		printf("%3d",c->data);
		c=c->next;
	}
}
node* sort_nodeswap(node *head)
{
	node *i,*j,*prei,*prej,*posj;
	if(head==NULL)
		return head;
	top:
	for(i=head;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->data>j->data)
			{
			   	if(j==i->next)
				{
					i->next=j->next;
					j->next=i;
				}
				else
				{
				    posj=j->next;
					j->next=i->next;
					i->next=posj;
					prej->next=i;
				}
				if(i==head)
					head=j;
				else
					prei->next=j;	
				goto top;
			}
			prej=j;
		}
		prei=i;
	}
	return head;
}

int main()
{
	node *head=NULL,*newnode;
	int item,x;
	do
	{
		printf("\n1. Insert at end\n2. Sort\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d",&item);
				newnode=create(item);
				head=insert_end(newnode,head);
				display(head);
				break;
			case 2:
				head=sort_nodeswap(head);
				display(head);
				break;
			case 3:
				display(head);
				break;
		}
	}while(x!=4);
	return 0;
}
