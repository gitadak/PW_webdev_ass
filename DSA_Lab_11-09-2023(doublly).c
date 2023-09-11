//Doublly circular
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;

node* create(int item)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=item;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void display(node *head)
{
	node *c;
	if(head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	printf("List:\n");
	c=head;
	do
	{
		printf("%3d",c->data);
		c=c->next;
	}while(c!=head);
	printf("\nReverse:\n");
	c=head->prev;
	do
	{
		printf("%3d",c->data);
		c=c->prev;
	}while(c!=head->prev);	
}

node* ins_beg(node *head,node *newnode)
{
	if(head==NULL)
	{
		head=newnode;
		head->prev=head;
		head->next=head;
		return head;
	}
	newnode->next=head;
	newnode->prev=head->prev;
	(head->prev)->next=newnode;
	head->prev=newnode;
	head=newnode;
	return head;
}

node* ins_end(node *head,node *newnode)
{
	if(head==NULL)
	{
		head=newnode;
		head->prev=head;
		head->next=head;
		return head;
	}
	newnode->next=head;
	newnode->prev=head->prev;
	(head->prev)->next=newnode;
	head->prev=newnode;
	return head;
}

node* del_beg(node *head)
{
	if(head==NULL)
		return head;
	if(head->next==head)
	{
		head=NULL;
		return head;
	}
	node *del=head;
	(head->prev)->next=head->next;
	(head->next)->prev=head->prev;
	head=head->next;
	free(del);
	del=NULL;
	return head;
}

node* del_end(node *head)
{
	if(head==NULL)
		return head;
	if(head->next==head)
	{
		head=NULL;
		return head;
	}
	node *del=head->prev;
	((head->prev)->prev)->next=head;
	head->prev=(head->prev)->prev;
	free(del);
	del=NULL;
	return head;
}

int main()
{
	node *head=NULL,*newnode;
	int x,item;
	do
	{
		printf("\n1. Insert at beginning\n2. Insert at last\n3. Delete from beginning\n4. Delete from last\n5. Display\n6. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter the data to be inserted: ");
				scanf("%d",&item);
				newnode=create(item);
				head=ins_beg(head,newnode);
				display(head);
				break;
			case 2:
				printf("Enter the data to be inserted: ");
				scanf("%d",&item);
				newnode=create(item);
				head=ins_end(head,newnode);
				display(head);
				break;
			case 3:
				head=del_beg(head);
				display(head);
				break;
			case 4:
				head=del_end(head);
				display(head);
				break;
			case 5:
				display(head);
				break;
		}
	}while(x!=6);
	return 0;
}
