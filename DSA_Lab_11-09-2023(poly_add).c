//Polynomial addition
#include<stdio.h>
#include<stdlib.h>

struct poly
{
	int coef;
	int exp;
	struct poly *next;
};
typedef struct poly poly;

poly* create(int cf,int pw)
{
	poly *newpoly = (poly*)malloc(sizeof(poly));
	newpoly->coef=cf;
	newpoly->exp=pw;
	newpoly->next=NULL;
	return newpoly;
}

void display(poly *f)
{
	poly *c;
	if(f==NULL)
	{
		printf("No polynomial\n");
		return;
	}
	c=f;
	while(c!=NULL)
	{
		printf("%3d^%d + ",c->coef,c->exp);
		c=c->next;
	}
	printf("\b\b ");
}

poly* insert(poly *f,poly *newpoly)
{
	poly *c;
	if(f==NULL)
	{
		f=newpoly;
		return f;
	}
	c=f;
	while(c->next!=NULL)
		c=c->next;
	c->next=newpoly;
	return f;
}

poly* add(poly *f1,poly *f2)
{
	poly *f3=NULL,*newpoly;
	if(f1==NULL && f2==NULL)
	{
		f3=NULL;
		return f3;
	}
	while(f1!=NULL && f2!=NULL)
	{
		if(f1->exp==f2->exp)
		{
			newpoly=create(((f1->coef)+(f2->coef)),f1->exp);
			f3=insert(f3,newpoly);
			f1=f1->next;
			f2=f2->next;
		}
		else if(f1->exp>f2->exp)
		{
			newpoly=create(f1->coef,f1->exp);
			f3=insert(f3,newpoly);
			f1=f1->next;
		}
		else
		{
			newpoly=create(f2->coef,f2->exp);
			f3=insert(f3,newpoly);
			f2=f2->next;	
		}
	}
	while(f1!=NULL)
	{
		newpoly=create(f1->coef,f1->exp);
		f3=insert(f3,newpoly);
		f1=f1->next;
	}
	while(f2!=NULL)
	{
		newpoly=create(f2->coef,f2->exp);
		f3=insert(f3,newpoly);
		f2=f2->next;
	}
	return f3;
}

int main()
{
	poly *newpoly,*f1=NULL,*f2=NULL,*f3;
	int n1,n2,i,cf,pw;
	printf("\nNo. of terms in first polynomial: ");
	scanf("%d",&n1);
	printf("Enter the terms of first polynomial:\n");
	for(i=0;i<n1;i++)
	{
		printf("Term %d:\n",i+1);
		printf("Enter the co-efficient: ");
		scanf("%d",&cf);
		printf("Enter the exponent: ");
		scanf("%d",&pw);
		newpoly=create(cf,pw);
		f1=insert(f1,newpoly);
	}
	printf("\nNo. of terms in second polynomial: ");
	scanf("%d",&n2);
	printf("Enter the terms of second polynomial:\n");
	for(i=0;i<n2;i++)
	{
		printf("Term %d:\n",i+1);
		printf("Enter the co-efficient: ");
		scanf("%d",&cf);
		printf("Enter the exponent: ");
		scanf("%d",&pw);
		newpoly=create(cf,pw);
		f2=insert(f2,newpoly);
	}
	f3=add(f1,f2);
	printf("\nPolynomial 1:\n");
	display(f1);
	printf("\nPolynomial 2:\n");
	display(f2);
	printf("\nResultant polynomial:\n");
	display(f3);
	return 0;
}
