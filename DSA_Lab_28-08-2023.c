#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node* create()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Enter the data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}

int check(int item,node *head)
{
	node *c;
	c=head;
	while(c!=NULL)
	{
		if(c->data==item)
			return 1;
		c=c->next;
	}
	return 0;
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

node* insert_beg(node *newnode,node* head)
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

node* insert_after(node* newnode,node *head)
{
	int item;
	node *c;
	if(head==NULL)
		return head;
	printf("Enter the element after which %d will be inserted: ",newnode->data);
	scanf("%d",&item);
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
	c=head;
	while(c->data!=item)
		c=c->next;
	newnode->next=c->next;
	c->next=newnode;
	return head;
}

node* insert_before(node* newnode, node* head)
{
	int item;
	node *c;
	if(head==NULL)
		return head;
	printf("Enter the element before which %d will be inserted: ",newnode->data);
	scanf("%d",&item);
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
	if(head->data==item)
	{
		newnode->next=head;
		head=newnode;
		return head;
	}
	c=head;
	while((c->next)->data!=item)
		c=c->next;
	newnode->next=c->next;
	c->next=newnode;
	return head;
}

node* del_beg(node *head)
{
	if(head==NULL)
		return head;
	node *ptr=head;
	head=head->next;
	free(ptr);
	return head;
}

node* del_end(node *head)
{
	node *c;
	if(head==NULL)
		return head;
	if(head->next==NULL)
	{
		head=NULL;
		free(head);
		return head;
	}
	while((c->next)->next!=NULL)
		c=c->next;
	c->next=NULL;
	free(c->next);
	return head;
}

node* del_after(node* head)
{
	int item;
	node *c,*del;
	if(head==NULL)
		return;
	printf("Enter the element after which deletion will take place: ");
	scanf("%d",&item);
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
	del=c->next;
	c->next=(c->next)->next;
	free(del);
	return head;
}

node* del_before(node *head)
{
	int item;
	node *c,*del;
	if(head==NULL)
		return head;
	printf("Enter the element before which deletion will take place: ");
	scanf("%d",&item);
	if(check(item,head)==0)
	{
		printf("%d is not present\n",item);
		return head;
	}
	if(item==head->data)
	{
		printf("First node\n");
		return head;
	}
	if((head->next)->data==item)
	{
		del=head;
		head=head->next;
		free(del);
		return head;
	}
	c=head;
	while(((c->next)->next)->data!=item)
		c=c->next;
	del=c->next;
	c->next=(c->next)->next;
	free(del);
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

int main()
{
	node* head=NULL,*newnode;
	int x,item;
	do
	{
		printf("\n1. Insert_end\n2. Insert_beg\n3. Display\n4. Insert_after\n5. Insert_before\n6. Delete_beg\n7. Delete_end\n8. Delete_after\n9. Delete_before\n10. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				newnode=create();
				head=insert_end(newnode,head);
				display(head);
				break;
			case 2:
				newnode=create();
				head=insert_beg(newnode,head);
				display(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				newnode=create();
				head=insert_after(newnode,head);
				display(head);
				break;
			case 5:
				newnode=create();
				head=insert_before(newnode,head);
				display(head);
				break;
			case 6:
				head=del_beg(head);
				display(head);
				break;
			case 7:
				head=del_end(head);
				display(head);
				break;
			case 8:
				head=del_after(head);
				display(head);
				break;
			case 9:
				head=del_before(head);
				display(head);
				break;
		}
	}while(x!=10);
	return 0;
}
