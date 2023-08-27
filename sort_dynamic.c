#include<stdio.h>
#include<stdlib.h>

int size()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    return n;
}

int* create(int n)
{
    int i,*a;
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i+1);
        scanf("%d",(a+i));
    }
    return a;
}

void display(int *a,int n)
{
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++)
        printf("%3d",*(a+i));
}

void swap(int *a, int *b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void bubble_asc(int *a,int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(*(a+j)>*(a+j+1))
            {
                swap((a+j),(a+j+1));
                flag=1;
            }
        }
        if(flag==0)
            return;
    }
}

void bubble_dsc(int *a,int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(*(a+j)<*(a+j+1))
            {
                swap((a+j),(a+j+1));
                flag=1;
            }
        }
        if(flag==0)
            return;
    }
}

void selection_asc(int *a,int n)
{
    int i,j,mindex;
    for(i=0;i<n-1;i++)
    {
        mindex=i;
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+mindex))
                mindex=j;
        }
        if(mindex!=i)
            swap((a+mindex),(a+i));
    }
}

void selection_dsc(int *a,int n)
{
    int i,j,maxdex;
    for(i=0;i<n-1;i++)
    {
        maxdex=i;
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)>*(a+maxdex))
                maxdex=j;
        }
        if(maxdex!=i)
            swap((a+maxdex),(a+i));
    }
}

void insertion_asc(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=*(a+i);
        j=i-1;
        while(j>=0 && temp<*(a+j))
        {
            *(a+j+1)=*(a+j);
            j--;
        }
        *(a+j+1)=temp;
    }
}

void insertion_dsc(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=*(a+i);
        j=i-1;
        while(j>=0 && temp>*(a+j))
        {
            *(a+j+1)=*(a+j);
            j--;
        }
        *(a+j+1)=temp;
    }
}

void merge_asc(int *a,int n,int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb,*b;
    b=(int*)malloc(n*sizeof(int));
    while(i<=mid && j<=ub)
    {
        if(*(a+i)<=*(a+j))
            *(b+k++)=*(a+i++);
        else
            *(b+k++)=*(a+j++);       
    }
    while(i<=mid)
        *(b+k++)=*(a+i++);
    while(j<=ub)
        *(b+k++)=*(a+j++);
    for(k=lb;k<=ub;k++)
        *(a+k)=*(b+k);
}

void merge_dsc(int *a,int n,int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb,*b;
    b=(int*)malloc(n*sizeof(int));
    while(i<=mid && j<=ub)
    {
        if(*(a+i)<=*(a+j))
            *(b+k++)=*(a+j++);
        else
            *(b+k++)=*(a+i++);       
    }
    while(i<=mid)
        *(b+k++)=*(a+i++);
    while(j<=ub)
        *(b+k++)=*(a+j++);
    for(k=lb;k<=ub;k++)
        *(a+k)=*(b+k);
}

void merge_sort_asc(int *a,int n,int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort_asc(a,n,lb,mid);
        merge_sort_asc(a,n,mid+1,ub); 
        merge_asc(a,n,lb,mid,ub); 
    }
}

void merge_sort_dsc(int *a,int n,int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort_dsc(a,n,lb,mid);
        merge_sort_dsc(a,n,mid+1,ub); 
        merge_dsc(a,n,lb,mid,ub); 
    }
}

int main()
{
    int x,*a,n;
    char y;
    do
    {
        printf("\n1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Merge sort\n5. Exit\nEnter your choice: ");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                do
                {
                    fflush(stdin);
                    printf("\na. Asscending Bubble sort\nb. Descending Bubble sort\nc. Exit\nEnter your choice: ");
                    scanf("%c",&y);
                    switch (y)
                    {
                        case 'a':
                            n=size();
                            a=create(n);
                            bubble_asc(a,n);
                            display(a,n);
                            break;
                        case 'b':
                            n=size();
                            a=create(n);
                            bubble_dsc(a,n);
                            display(a,n);
                            break;                           
                    }
                } while (y!='c');
                break;
            case 2:
                do
                {
                    fflush(stdin);
                    printf("\na. Asscending Selection sort\nb. Descending Selection sort\nc. Exit\nEnter your choice: ");
                    scanf("%c",&y);
                    switch (y)
                    {
                        case 'a':
                            n=size();
                            a=create(n);
                            selection_asc(a,n);
                            display(a,n);
                            break;
                        case 'b':
                            n=size();
                            a=create(n);
                            selection_dsc(a,n);
                            display(a,n);
                            break;                           
                    }
                } while (y!='c');
                break; 
            case 3:
                do
                {
                    fflush(stdin);
                    printf("\na. Asscending Insertion sort\nb. Descending Insertion sort\nc. Exit\nEnter your choice: ");
                    scanf("%c",&y);
                    switch (y)
                    {
                        case 'a':
                            n=size();
                            a=create(n);
                            insertion_asc(a,n);
                            display(a,n);
                            break;
                        case 'b':
                            n=size();
                            a=create(n);
                            insertion_dsc(a,n);
                            display(a,n);
                            break;                           
                    }
                } while (y!='c');
                break;
            case 4:
                do
                {
                    fflush(stdin);
                    printf("\na. Asscending Merge sort\nb. Descending Merge sort\nc. Exit\nEnter your choice: ");
                    scanf("%c",&y);
                    switch (y)
                    {
                        case 'a':
                            n=size();
                            a=create(n);
                            merge_sort_asc(a,n,0,n-1);
                            display(a,n);
                            break;
                        case 'b':
                            n=size();
                            a=create(n);
                            merge_sort_dsc(a,n,0,n-1);
                            display(a,n);
                            break;                           
                    }
                } while (y!='c');
                break;                      
        }
    } while (x!=5);
    return 0;
}