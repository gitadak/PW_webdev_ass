#include<stdio.h>

void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
	return;
}

int main()
{
	int x,y;
	printf("Enter  the 1st number: ");
	scanf("%d",&x);
	printf("Enter  the 2nd number: ");
	scanf("%d",&y);
	swap(&x,&y);
	printf("After swapping...\na=%d\nb=%d",x,y);
	return 0;
}

