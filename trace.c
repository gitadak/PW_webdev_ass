//Trace of a matrix (Sum of principal diagonal elements)
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

int trace(int a[50][50],int m,int n)
{
	int i,j,s=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				s+=a[i][j];	
		}
	}
	return s;
}

int main()
{
	int arr[50][50],m,n,sum;
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
	if(m!=n)
	{
		printf("Please input a square matrix");
		return 0;
	}
	else
	{
		read(arr,m,n);
		disp(arr,m,n);
		printf("\nTrace = %d",trace(arr,m,n));
	}
	return 0;
}
