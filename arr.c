#include<stdio.h>
int ins_end(int a[50],int n)
{
	int d,i;
	printf("\nEnter the element: ");
	scanf("%d",&d);
	a[n]=d;
	return ++n;
}
int ins_beg(int a[50],int n)
{
	int i,d;
	printf("\nEnter the element: ");
	scanf("%d",&d);
	for(i=n-1;i>=0;i--)
		a[i+1]=a[i];
	a[0]=d;
	return ++n;
}
int ins_bet(int a[50],int n)
{
	int i,d,pos;
	printf("\nEnter the element: ");
	scanf("%d",&d);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	for(i=n-1;i>=pos-1;i--)
		a[i+1]=a[i];
	a[pos-1]=d;
	return ++n;
}
int del_beg(int a[50],int n)
{
	int i;
	for(i=1;i<n;i++)
		a[i-1]=a[i];
	return --n;
}
int del_bet(int a[50],int n)
{
	int i,p;
	printf("\nEnter the position to be deleted: ");
	scanf("%d",&p);
	for(i=p;i<n;i++)
		a[i-1]=a[i];
	return --n;
}
int del_end(int a[50],int n)
{
	return --n;
}
void disp(int a[50],int n)
{
	int i;
	printf("\nThe array:\n");
	for(i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
}
int main()
{
	int i,x,p,arr[50];
	static int n;
	char m;
	/*printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);*/
	do
	{
		printf("\n1. insert\n2. delete\n3. exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				do
				{
					printf("\na. ins_beg\nb. ins_bet\nc. ins_end\nd. exit\nEnter your choice: ");
					fflush(stdin);
					scanf("%c",&m);
					switch(m)
					{
						case 'a':
							n=ins_beg(arr,n);
							disp(arr,n);
							break;
						case 'b':
							n=ins_bet(arr,n);
							disp(arr,n);
							break;
						case 'c':
							n=ins_end(arr,n);
							disp(arr,n);
							break;
					}
				}while(m!='d');
				break;
			case 2:
				do
				{
					printf("\na. del_beg\nb. del_bet\nc. del_end\nd. exit\nEnter your choice: ");
					fflush(stdin);
					scanf("%c",&m);
					switch(m)
					{
						case 'a':
							n=del_beg(arr,n);
							disp(arr,n);
							break;
						case 'b':
							n=del_bet(arr,n);
							disp(arr,n);
							break;
						case 'c':
							n=del_end(arr,n);
							disp(arr,n);
							break;
					}
				}while(m!='d');
				break;
		}
	}while(x!=3);
	return 0;
}
