//Doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
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

int check(int item,node *head)
{
	node *c;
	c=head;
	do
	{
		if(c->data==item)
			return 1;
		c=c->next;
	}while(c!=head);
	return 0;
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
	while(c->next!=NULL)
	{
		printf("%3d",c->data);
		c=c->next;
	}
	printf("%3d\nReverse:\n",c->data);
	for(;c!=NULL;c=c->prev)
		printf("%3d",c->data);
}

node* insert_end(node *newnode,node *head)
{
	node *c;
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	c=head;
	while (c->next!=NULL)
		c=c->next;
	newnode->prev=c;
	c->next=newnode;
	return head;
}

node* insert_beg(node *newnode,node *head)
{
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	newnode->next=head;
	newnode->prev=NULL;
	head->prev=newnode;
	head=newnode;
	return head;
}

node* del_end(node *head)
{
	node *c=head,*del;
	if(head==NULL)
		return head;
	if(head->next==NULL)
	{
		del=head;
		head=NULL;
		free(del);
		return head;
	}
	while((c->next)->next!=NULL)
		c=c->next;
	del=c->next;
	c->next=NULL;
	free(del);
	return head;
}

node* del_beg(node *head)
{
	node *del=head;
	if(head==NULL)
		return head;
	head=head->next;
	head->prev=NULL;
	free(del);
	return head;
}

node* insert_after(node *head,node *newnode,int item)
{
	node *c;
	if(head==NULL)
		return head;
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
	c=head;
	while(c->data!=item)
		c=c->next;
	if(c->next==NULL)
	{
		newnode->prev=c;
		c->next=newnode;
		return head;
	}
	newnode->prev=c;
	newnode->next=c->next;
	(c->next)->prev=newnode;
	c->next=newnode;
	return head;
}

node* insert_before(node *head,node *newnode,int item)
{
	node *c;
	if(head==NULL)
		return head;
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
	if(head->data==item)
	{
		newnode->next=head;
		newnode->prev=NULL;
		head->prev=newnode;
		head=newnode;
		return head;
	}
	c=head;
	while(c->data!=item)
		c=c->next;
	newnode->next=c;
	newnode->prev=c->prev;
	(c->prev)->next=newnode;
	c->prev=newnode;
    return head;
}

node* del_after(node *head,int item)
{
	node *c,*del;
	if(head==NULL)
		return head;
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
	c=head;
	while(c->data!=item)
		c=c->next;
	if(c->next==NULL)
	{
		printf("Last node\n");
		return head;
	}
	if((c->next)->next==NULL)
	{
		del=c->next;
		c->next=NULL;
		free(del);
		return head;
	}
	del=c->next;
	((c->next)->next)->prev=c;
	c->next=(c->next)->next;
	free(del);
    return head;
}

node* del_before(node *head,int item)
{
    node *c,*del;
    if(head==NULL)
        return head;
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
    if(head->data==item)
    {
        printf("First node\n");
        return head;
    }
    if((head->next)->data==item)
    {
        del=head;
    	head=head->next;
	    head->prev=NULL;
	    free(del);
	    return head;
    }
    c=head;
    while(c->data!=item)
        c=c->next;
    del=c->prev;
    ((c->prev)->prev)->next=c;
    c->prev=(c->prev)->prev;
    free(del);
    return head;
}

int main()
{
	node* head=NULL,*newnode;
	int x,data_item,item;
	char y;
	do
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				do
				{
					fflush(stdin);
					printf("\na. Insert at begin\nb. Insert at end\nc. Insert before an element\nd. Insert after an element\ne. Exit\nEnter your choice: ");
					scanf("%c",&y);
					switch(y)
					{
						case 'a':
							printf("Enter the data: ");
							scanf("%d",&data_item);
							newnode=create(data_item);
							head=insert_beg(newnode,head);
							display(head);
							break;
						case 'b':
							printf("Enter the data: ");
							scanf("%d",&data_item);
							newnode=create(data_item);
							head=insert_end(newnode,head);
							display(head);
							break;
						case 'c':
							printf("Enter the data: ");
							scanf("%d",&data_item);
							newnode=create(data_item);
							printf("Enter the data before which %d will be inserted: ",newnode->data);
							scanf("%d",&item);
							head=insert_before(head,newnode,item);
							display(head);
							break;
						case 'd':
							printf("Enter the data: ");
							scanf("%d",&data_item);
							newnode=create(data_item);
							printf("Enter the data after which %d will be inserted: ",newnode->data);
							scanf("%d",&item);
							head=insert_after(head,newnode,item);
							display(head);
							break;
					}
				} while (y!='e');
				break;
			case 2:
				do
				{
					fflush(stdin);
					printf("\na. Delete at begin\nb. Delete at end\nc. Delete before an element\nd. Delete after an element\ne. Exit\nEnter your choice: ");
					scanf("%c",&y);
					switch(y)
					{
						case 'a':
							head=del_beg(head);
							display(head);
							break;
						case 'b':
							head=del_end(head);
							display(head);
							break;
						case 'c':
							printf("Enter the data before which deletion will take place: ");
							scanf("%d",&item);
							head=del_before(head,item);
							display(head);
							break;
						case 'd':
							printf("Enter the data after which deletion will take place: ");
							scanf("%d",&item);
							head=del_after(head,item);
							display(head);
							break;
					} 
				}while (y!='e');
				break;
			case 3:
				display(head);
				break;
		}
	}while(x!=4);
	return 0;	
}
