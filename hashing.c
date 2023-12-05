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
	printf("\nHash Table:\n");

    printf("Key  :");
	for(i=0;i<n;i++)
		printf("%5d",i);

    printf("\nValue:");
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
}

int main()
{
	int ch,data;
    char x;
	static int a[50], b[50];
	do
	{
        printf("\n1. Key_mod_size\n2. Multiplication\n3. Exit\nChoose a hash function: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                do
                {
                    fflush(stdin);
                    printf("\na. Create\nb. Searching\nc. Display\nd. Exit\nEnter your option: ");
                    scanf("%c",&x);
                    switch (x)
                    {
                        case 'a':
				            printf("Enter the element u want to insert: ");
				            scanf("%d",&data);
				            create_key_mod_size(a,size,data);
				            display(a,size);                            
                            break;
                        case 'b':
        				    printf("Enter the element to be searched: ");
				            scanf("%d",&data);	
				            search_key_mod_size(a,size,data);
				            display(a,size);
				            break;
                        case 'c':
                            display(a,size);
                            break;
                    }
                } while (x!='d');
                break;  
            case 2:
                do
                {
                    fflush(stdin);
                    printf("\na. Create\nb. Searching\nc. Display\nd. Exit\nEnter your option: ");
                    scanf("%c",&x);
                    switch (x)
                    {
                        case 'a':
				            printf("Enter the element u want to insert: ");
				            scanf("%d",&data);
				            create_multiplication(b,size,data);
				            display(b,size);
				            break;
                        case 'b':
				            printf("Enter the element to be searched: ");
				            scanf("%d",&data);	
				            search_multiplication(b,size,data);
				            display(b,size);
				            break;
                        case 'c':
                            display(b,size);
                            break;
                    }
                } while (x!='d');
                break;                  
        }
	}while(ch!=3);
	return 0;
}