#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node* create_node()
{
	int item;
    	node *newnode=(node*)malloc(sizeof(node));
    	printf("Enter the element: ");
    	scanf("%d",&item);
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

node* insert_beg(node* newnode,node* head)
{
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	newnode->next=head;
	head=newnode;
	return head;
}

void display(node* head)
{
	node *c;
    	if(head==NULL)
    	{
        	printf("Empty list");
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

int frequency(node *head,int item)
{
	int count=0;
	node *c;
	c=head;
	while(c!=NULL)
	{
		if(c->data==item)
			count++;
		c=c->next;
	}	
	return count;
}

int main()
{
	node* head=NULL,*newnode;
	int x,item;
	do
	{
		printf("\n1. Insert_end\n2. Insert_beg\n3. Display\n4. Frequency\n5. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
                		newnode=create_node();
				head=insert_end(newnode,head);
				display(head);
				break;
			case 2:
                		newnode=create_node();
				head=insert_beg(newnode,head);
				display(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				printf("Enter the elemnet to be found: ");
				scanf("%d",&item);
				printf("Frequency of %d is %d",item,frequency(head,item));
				break;
		}
	}while(x!=5);
	return 0;
}
