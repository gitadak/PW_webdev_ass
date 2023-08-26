//Matrix Multiplication
#include<stdio.h>

void read(int a[50][50],int m,int n)
{
	int i,j;
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
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	return;
}

void multiplication(int a[50][50],int b[50][50],int r1,int c1,int r2,int c2)
{
	int i,j,k,c[50][50];
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			c[i][j]=0;
			for(k=0;k<c1;k++)
				c[i][j]+=(a[i][k]*b[k][j]);
		}
	}
	printf("\nNew matrix:\n");
	disp(c,r1,c2);
	return;
}

int main()
{
	int arr1[50][50],arr2[50][50],r1,c1,r2,c2;
	printf("Enter the rows and columns of 1st matrix:\n");
	scanf("%d%d",&r1,&c1);
	printf("Enter the rows and columns of 1st matrix:\n");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2)
	{
		printf("Invalid input");
		return 0;
	}
	else
	{
		printf("\nEnter the 1st matrix elements:\n");
		read(arr1,r1,c1);
		printf("\nEnter the second matrix elements:\n");
		read(arr2,r2,c2);
		printf("\nThe 1st Matrix:\n");
		disp(arr1,r1,c1);
		printf("\nThe 2nd Matrix:\n");
		disp(arr2,r2,c2);
		multiplication(arr1,arr2,r1,c1,r2,c2);
	}
	return 0;
}
