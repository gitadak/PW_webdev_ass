//Infix to Postfix
#include<stdio.h>

char stack[100],p[100];
int top=-1;

void push(char m)
{
	stack[++top]=m;
}

char pop()
{
	char r;
	if(top<0)
	{
		printf("Empty\n");
		return ('\0');
	}
	r=stack[top--];
	return r;
}

int precedence(char c)
{
	if(c=='^')
		return 1;
	if(c=='/' || c=='*')
		return 2;
	if(c=='+' || c=='-')
		return 3;
	if(c=='(' || c==')')
		return 4;
}

int chkpre(char p,char c)
{
	int a1,a2;
	a1=precedence(p);
	a2=precedence(c);
	if(a1<=a2 && a1!=4 && a2!=4)
		return 1;
	else
		return 0;
}

void postfix(char s[100])
{
	int i,j=0,g;
	char x,y;
	for(i=0;s[i]!='\0';i++)
	{
		x=s[i];
		if((x>=65 && x<=90) || (x>=97 && x<=122))
			p[j++]=x;
		else if(x=='(')
			push(x);
		else if(x==')')
		{
			while(1)
			{
				y=pop();
				if(y=='(' || y=='\0')
					break;
				else
					p[j++]=y;
			}
		}
		else if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		{
			while(top!=-1)
			{
				y=pop();
				if(chkpre(y,s[i])==1)
					p[j++]=y;
				else
				{
					push(y);
					break;
				}
			}
			push(x);
		}
		printf("\n");
		printf("%c\t",s[i]);
		for(g=0;g<=top;g++)
			printf("%c",stack[g]);
		printf("\t");
		puts(p);
		getche();
	}
	while(top!=-1)
	{
		y=pop();
		p[j++]=y;
	}
	p[j]='\0';
	printf("\n\t\t");
	puts(p);
	getche();
	return;
}

int main()
{
	char s[100];
	printf("Enter an equation:");
	gets(s);
	printf("\nSymbol\tStack\tExpression\n");
	postfix(s);
	printf("\nPostfix: ");
	puts(p);
	return 0;
}
