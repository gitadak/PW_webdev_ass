//DSA_Lab_07-08-2023
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
	int arr[50][50],arr1[50][50],arr2[50][50],x,m,n,r1,c1,r2,c2;
	do
	{
		printf("\n1. Trace\n2. Sum of all elements\n3. Transpose\n4. Matrix multiplication\n5. Upper triangular matrix\n6. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter the number of rows: ");
				scanf("%d",&m);
				printf("Enter the number of columns: ");
				scanf("%d",&n);
				if(m!=n)
					printf("Please input a square matrix");	
				else
				{
					read(arr,m,n);
					disp(arr,m,n);
					printf("\nTrace = %d",trace(arr,m,n));
				}
				break;
			case 2:
				printf("Enter the number of rows: ");
				scanf("%d",&m);
				printf("Enter the number of columns: ");
				scanf("%d",&n);
				read(arr,m,n);
				disp(arr,m,n);
				printf("\nSum of all elements = %d",sum(arr,m,n));
				break;
			case 3:
				printf("Enter the number or rows: ");
				scanf("%d",&m);
				printf("Enter the number of columns: ");
				scanf("%d",&n);
				read(arr,m,n);
				disp(arr,m,n);
				transpose(arr,m,n);
				break;
			case 4:
				printf("Enter the rows and columns of 1st matrix:\n");
				scanf("%d%d",&r1,&c1);
				printf("Enter the rows and columns of 1st matrix:\n");
				scanf("%d%d",&r2,&c2);
				if(c1!=r2)
					printf("Invalid input");
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
				break;
			case 5:
				printf("Enter the number of rows: ");
				scanf("%d",&m);
				printf("Enter the number of columns: ");
				scanf("%d",&n);
				if(m!=n)
					printf("Input square matrix");
				else
				{
					read(arr,m,n);
					disp(arr,m,n);
					upper_triangular(arr,m,n);
				}
				break;
		}		
	}while(x!=6);
	return 0;
}
