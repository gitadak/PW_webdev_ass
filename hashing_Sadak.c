#include<stdio.h>
#include<math.h>
#define size 10
#define A 0.2

void create_key_mod_size(int a[50],int n,int data)
{
	int i;
	int pos=data%n;
	if(a[pos]==0)
	{
		a[pos]=data;
		return;
	}
	for(i=pos;i<n;i++)
	{
		if(a[i]==0)
		{
			a[i]=data;
			return;				
		}
	}
	printf("No space in array\n");
}

void create_multiplication(int a[50],int n,int data)
{
	int i;
	int pos=n*remainder((data*A),1);
	if(a[pos]==0)
	{
		a[pos]=data;
		return;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			a[i]=data;
			return;				
		}
	}
	printf("No space in array\n");
}

void search_key_mod_size(int a[50],int n,int item)
{
	int i;
	int pos=item%n;
	if(a[pos]==item)
	{
		printf("%d found in position %d",item,pos);
		return;
	}
	for(i=pos;i<n;i++)
	{
		if(a[i]==item)
		{
			printf("%d found in position %d",item,i);
			return;			
		}
	}
	printf("%d is not present",item);
}

void search_multiplication(int a[50],int n,int item)
{
	int i;
	int pos=n*remainder((item*A),1);
	if(a[pos]==item)
	{
		printf("%d found in position %d",item,pos);
		return;
	}
	for(i=pos;i<n;i++)
	{
		if(a[i]==item)
		{
			printf("%d found in position %d",item,i);
			return;			
		}
	}
	printf("%d is not present",item);
}

void display(int a[50],int n)
{
	int i;
	printf("\nThe array:\n");
	for(i=0;i<n;i++)
	{
		printf("%5d [%d]",a[i],i);
	}
}

int main()
{
	int ch,data;
	static int a[50];
	do
	{
		printf("\n1. create_key_mod_10\n2. create_multiplication\n3. Search_key_mod_size\n4. Search_multiplication\n5. Display\n6. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element u want to insert: ");
				scanf("%d",&data);
				create_key_mod_size(a,size,data);
				//display(a,size);
				break;
			case 2:
				printf("Enter the element u want to insert: ");
				scanf("%d",&data);
				create_multiplication(a,size,data);
				//display(a,size);
				break;
			case 3:
				printf("Enter the element to be searched: ");
				scanf("%d",&data);	
				search_key_mod_size(a,size,data);
				//display(a,size);
				break;
			case 4:
				printf("Enter the element to be searched: ");
				scanf("%d",&data);	
				search_multiplication(a,size,data);
				//display(a,size);
				break;
			case 5:
				display(a,size);
				break;
		}
	}while(ch!=6);
	return 0;
}
