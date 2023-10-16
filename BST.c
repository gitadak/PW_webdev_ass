//BINARY SEARCH TREE
#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
};
typedef struct tree tree;

void insert(tree *root, tree *p,int v)
{
	tree *cur;
	if(root!=NULL)
	{
		if(v>root->key)
			insert(root->right,root,v);
		else
			insert(root->left,root,v);
	}
	else
	{
		cur=(tree*)malloc(sizeof(tree));
		cur->key=v;
		cur->left=NULL;
		cur->right=NULL;
		if(v>p->key)
			p->right=cur;
		else
			p->left=cur;
	}
}

void preorder(tree *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);	
	}	
}

void inorder(tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}

void postorder(tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}

int main()
{
	int c,v,k=0;
	tree *root,*m;
	m=root;
	root=(tree*)malloc(sizeof(tree));
	printf("\nEnter the data: ");
	scanf("%d",&root->key);
	root->left=NULL;
	root->right=NULL;
	do
	{
		printf("\n\n1. Insert\n2. PREorder\n3. INorder\n4. POSTorder\n5. EXIT\nEnter your choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nValue: ");
				scanf("%d",&v);
				insert(root,m,v);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
		}
	}while(c!=5);
}
