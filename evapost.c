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
	int i=0,j=0,op1,op2,g;
	char x,y,temp[10];
	for(i=0;s[i]!='\0';i++)
	{
		j=0;
		while(isdigit(s[i]))
			temp[i++]=s[i++];
		temp[j]='\0';
		if(j!=0)
			push(atoi(temp));
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' /*|| s[i]=='^'*/)
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
				/*case '^':
					push(math.pow(op2,op1));
					break;*/
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
