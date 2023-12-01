//Insertion and Deletion(delete root element) into a MaxHeap
#include<stdio.h>

int heap[100],n;

void swap(int *a,int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void insert(int val)
{
    int pos,par;
    n++;
    pos = n;
    heap[n] = val;

    while(pos > 0)
    {
        par = (pos-1)/2;
        if(heap[pos] <= heap[par])
            return;
        else
        {
            swap(&heap[pos],&heap[par]);
            pos = par;
        }
    }
}

int delete_root_node()
{
    int last,ptr,left,right,del_root;

    if(n==-1)
        return 0;

    del_root = heap[0];
    last = heap[n];
    n--;
    ptr = 0, left = 1, right = 2;
    heap[ptr] = last;

    while(left <= n)
    {
        if((heap[ptr] >= heap[left]) && (heap[ptr] >= heap[right]))
            return del_root;
        
        if(heap[right] <= heap[left])
        {
            swap(&heap[ptr],&heap[left]);
            ptr = left;
        }
        else
        {
            swap(&heap[ptr],&heap[right]);
            ptr = right;
        }

        left = 2*ptr+1;
        right = 2*ptr+2;
    }

    return del_root;
}

void display()
{
    int i;
    if(n==-1)
    {
        printf("\nEmpty array\n");
        return;
    }
    printf("\nThe array:\n");
    for(i=0;i<=n;i++)
        printf("%5d",heap[i]);
}

int main()
{
    n=-1;
    int ch,data,del;

    do
    {
        printf("\n1. Insert into MAXHEAP\n2. Delete root element from MAXHEAP\n3. Disaplay\n4. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&data);
            insert(data);
            display();
            break;
        case 2:
            del = delete_root_node();
            printf("\nDeleted root element: %d",del);
            display();
            break;
        case 3:
            display();
            break;
        }
    } while (ch!=4);
    
    return 0;
}
