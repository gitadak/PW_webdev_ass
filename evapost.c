//Postfix Evaluation
#include<stdio.h>
#include<ctype.h>
#include<math.h>

int stack[100];
int top=-1;

void push(int m)
{
	stack[++top]=m;
}

int pop()
{
	int r;
	if(top==-1)
	{
		printf("Empty\n");
		return 0;
	}
	r=stack[top--];
	return r;
}

int evapostfix(char s[100])
{
	int i,op1,op2;
	for(i=0;s[i]!='\0';i++)
	{
		while(isdigit(s[i]))
			push(s[i++]-48);
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
		{
			op1=pop();
			op2=pop();
			switch(s[i])
			{
				case '+':
					push(op2+op1);
					break;
				case '-':
					push(op2-op1);
					break;
				case '*':
					push(op2*op1);
					break;
				case '/':
					push(op2/op1);
					break;
				case '^':
					push(pow(op2,op1));
					break;
			}
		}
	}
	return (pop());
}

int main()
{
	int n;
	char s[100];
	printf("\nPostfix: ");
	gets(s);
	n=evapostfix(s);
	printf("\nValue=%d",n);
	return 0;
}
