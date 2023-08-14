#include<stdio.h>
#include<time.h>

int insert(int a[50])
{
	int i,n;
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i+1);
		scanf("%d",&a[i]);
	}
	return n;
}

void display(int a[50],int n)
{
	int i;
	printf("\nThe array:\n");
	for(i=0;i<n;i++)
		printf("%3d",a[i]);
	return;
}

void bubble_sort(int a[50],int n)
{
	int i,j,flag,t;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
		if(flag==0)
			return;
	}
	return;
}

void selection_sort(int a[50],int n)
{
	int i,j,mindex,t;
	for(i=0;i<n-1;i++)
	{
		mindex=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[mindex])
				mindex=j;
		}
		if(mindex!=i)
		{
			t=a[mindex];
			a[mindex]=a[i];
			a[i]=t;
		}
	}
	return;
}

void insertion_sort(int a[50],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	return;
}

void merge(int a[50],int lb,int mid,int ub)
{
	int i=lb,j=mid+1,b[50],k=lb;//k=0
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;	
		}
		else
		{
			b[k]=a[j];
			j++;	
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;	
	}
	while(j<=ub)
	{
		b[k]=a[j];	
		j++;
		k++;
	}
	/*i=lb;
	for(j=0;j<k;j++)
	{
		a[i]=b[j];
		i++;	
	}*/
	k=lb;
	while(k<=ub)
	{
		a[k]=b[k];
		k++;
	}
	return;
}

void merge_sort(int a[50],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
	return;
}

int main()
{
	int n,arr[50],x;
	double duration;
	clock_t start,end;
	do
	{
		printf("\n1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Merge Sort\n5. Exit\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				n=insert(arr);
				start=clock();
				bubble_sort(arr,n);
				end=clock();
				duration=(((double)end-start)/CLOCKS_PER_SEC);
				printf("Time taken = %lf",duration);
				display(arr,n);
				break;
			case 2:
				n=insert(arr);
				start=clock();
				selection_sort(arr,n);
				end=clock();
				duration=(((double)end-start)/CLOCKS_PER_SEC);
				printf("Time taken = %lf",duration);
				display(arr,n);
				break;
			case 3:
				n=insert(arr);
				start=clock();
				insertion_sort(arr,n);
				end=clock();
				duration=(((double)end-start)/CLOCKS_PER_SEC);
				printf("Time taken = %lf",duration);
				display(arr,n);
				break;
			case 4:	
				n=insert(arr);
				start=clock();
				merge_sort(arr,0,n-1);
				end=clock();
				duration=(((double)end-start)/CLOCKS_PER_SEC);
				printf("Time taken = %lf",duration);
				display(arr,n);
				break;			
		}
	}while(x!=5);
	return 0;
}
