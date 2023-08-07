//Transpose of a matrix
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

void transpose(int a[50][50],int m,int n)
{
	int i,j,b[50][50];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			b[j][i]=a[i][j];
	}
	printf("Transpose:");
	disp(b,n,m);
	return;
}

int main()
{
	int m,n,arr[50][50];
	printf("Enter the number or rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
	read(arr,m,n);
	disp(arr,m,n);
	transpose(arr,m,n);
	return 0;
}
