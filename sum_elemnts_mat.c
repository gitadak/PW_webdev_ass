//Sum of all elements of a matrix
#include<stdio.h>

void read(int a[50][50],int m,int n)
{
	int i,j;
	printf("\nEnter the matrix elements:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("arr[%d][%d]=",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	return;
}

void disp(int a[50][50],int m,int n)
{
	int i,j;
	printf("\nThe Matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	return;
}

int sum(int a[50][50],int m,int n)
{
	int i,j,s=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			s+=a[i][j];
	}
	return s;
}

int main()
{
	int arr[50][50],s,m,n;
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
	read(arr,m,n);
	disp(arr,m,n);
	printf("\nSum of all elements = %d",sum(arr,m,n));
	return 0;
}
