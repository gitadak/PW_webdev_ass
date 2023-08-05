//Linear search, binary search (recursive & non-recursive)
#include<stdio.h>

int linear_search(int arr[50],int n,int item)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==item)
            return i;
    }
    return -1;
}

int binary_search(int arr[50],int n,int item)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
            return mid;
        else if(item>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int rec_binary_search(int arr[50],int item,int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
            return mid;
        else if(item>arr[mid])
            return rec_binary_search(arr,item,mid+1,high);
        else
            return rec_binary_search(arr,item,low,mid-1);
    }
    return -1;
}

void bubble_sort(int arr[50],int n)
{
    int i,j,t,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                flag=1;
            }
        }
        if(flag==0)
            return;
    }
    return;
}

void display(int arr[50],int n)
{
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++)
        printf("%3d",arr[i]);
    return;
}

void status(int pos,int item)
{
    if(pos!=-1)
        printf("Position of %d is %d",item,pos+1);
    else
        printf("Not Found");
    return;
}

int main()
{
    int a[50],n,i,d,x,pos;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    display(a,n);
    do
    {
        printf("\n1. Linear search\n2. Binary search\n3. Recursive Binary search\n4. Exit\nEnter your choice: ");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                display(a,n);
                printf("\nEnter the element to be searched: ");
                scanf("%d",&d);
                pos=linear_search(a,n,d);
                status(pos,d);
                break;
            case 2:
                bubble_sort(a,n);
                display(a,n);
                printf("\nEnter the element to be searched: ");
                scanf("%d",&d);
                pos=binary_search(a,n,d);
                status(pos,d);
                break;
            case 3:
                bubble_sort(a,n);
                display(a,n);
                printf("\nEnter the element to be searched: ");
                scanf("%d",&d);
                pos=rec_binary_search(a,d,0,n-1);
                status(pos,d);
                break;
        }
    } while (x!=4);
    return 0;
}