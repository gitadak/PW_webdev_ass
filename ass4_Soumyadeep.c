//Delete a node in singlly linked list -> delete begin, delete_end
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node* create(int val)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

node* insert_beg(node *head,node *newnode)
{
	if(head == NULL)
	{
		head = newnode;
		return head;
	}
	newnode->next = head;
	head = newnode;
	return head;
}

node* delete_beg(node *head)
{
	if(head == NULL)
		return head;
	node *del = head;
	head = head->next;
	free(del);
	del = NULL;
	return head;
}

node* delete_end(node *head)
{
	node *c, *del;
	if(head == NULL || head->next == NULL)
	{
		head = NULL;
		return head;
	}
	for(c = head; (c->next)->next != NULL; c = c->next)
	{
	}
	del = c->next;
	c->next = NULL;
	free(del);
	del = NULL;
	return head;
}

void display(node *head)
{
	node *c;
	if(head == NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("The list:\n");
	for(c = head; c != NULL; c = c->next)
		printf("%d -> ",c->data);
	printf("NULL");
	return;
}

int main()
{
	node *head = NULL, *newnode;
	int ch, val;
	do
	{
		printf("\n1. Insert_beg\n2. Delete_beg\n3. Display\n4. Delete_end\n5. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value: ");
				scanf("%d",&val);
				newnode = create(val);
				head = insert_beg(head,newnode);
				display(head);
				break;
			case 2:
				head = delete_beg(head);
				display(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				head = delete_end(head);
				display(head);
				break;
		}
	}while(ch != 5);
	return 0;
}
