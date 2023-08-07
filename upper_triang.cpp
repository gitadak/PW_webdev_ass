//Upper triangular matrix
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

void upper_triangular(int a[50][50],int m,int n)
{
	int i,j,b[50][50];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>=i)
				b[i][j]=a[i][j];
			else
				b[i][j]=0;
		}
	}
	printf("Upper triangular:");
	disp(b,m,n);
	return;
}

int main()
{
	int arr[50][50],m,n;
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
	if(m!=n)
	{
		printf("Input square matrix");
		return 0;
	}
	else
	{
		read(arr,m,n);
		disp(arr,m,n);
		upper_triangular(arr,m,n);
	}
	return 0;
}
