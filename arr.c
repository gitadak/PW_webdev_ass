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
	int arr[50],n,i,x,p;
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	do
	{
		printf("\n1. ins_beg\n2. ins_bet\n3. ins_end\n4. del_beg\n5. del_bet\n6. del_end\n7. exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				n=ins_beg(arr,n);
				disp(arr,n);
				break;
			case 2:
				n=ins_bet(arr,n);
				disp(arr,n);
				break;
			case 3:
				n=ins_end(arr,n);
				disp(arr,n);
				break;
			case 4:
				n=del_beg(arr,n);
				disp(arr,n);
				break;
			case 5:
				n=del_bet(arr,n);
				disp(arr,n);
				break;
			case 6:
				n=del_end(arr,n);
				disp(arr,n);
				break;
		}
	}while(x!=7);
	return 0;
}
