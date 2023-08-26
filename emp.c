#include<stdio.h>

typedef struct
{
	int id;
	int age;
	char name[20];
	char dept[20];
}emp;

int main()
{
	emp e[20];
	int i,n;
	printf("How many records: ");
	scanf("%d",&n);
	printf("Enter the employee details:\n");
	for(i=0;i<n;i++)
	{
		printf("Employee %d:",i+1);
		printf("\nID: ");
		scanf("%d",&e[i].id);
		printf("Age: ");
		scanf("%d",&e[i].age);
		printf("Name: ");
		fflush(stdin);
		scanf("%[^\n]",e[i].name);
		printf("Department: ");
		fflush(stdin);
		scanf("%[^\n]",e[i].dept);
	}
	printf("\nRetirement coming soon...");
	for(i=0;i<n;i++)
	{
		if(e[i].age>=58 && e[i].age<=60)
		{
			printf("\nEmployee %d\nID = %d\nAge = %d\nName = %s\nDepartment = %s",i+1,e[i].id,e[i].age,e[i].name,e[i].dept);
		}
	}
	return 0;
}
