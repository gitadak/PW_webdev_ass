//BST->Insertion,Traversal,Deleteion
#include <stdio.h>
#include <stdlib.h>
 
struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
};
typedef struct tree tree;

tree* create(int item)
{
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
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
 
tree* insert(tree* root,int data)
{
    if (root == NULL)
        return create(data);
    if (data < root->key)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}
 
tree* deletetree(tree* root, int data)
{
    if (root == NULL)
        return root;
    if (root->key > data) 
    {
        root->left = deletetree(root->left, data);
        return root;
    }
    else if (root->key < data)
    {
        root->right = deletetree(root->right, data);
        return root;
    }
    if (root->left == NULL)
    {
        tree* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        tree* temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        //Finding inorder successor
        tree* succParent = root;
        tree* succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->key = succ->key;
        free(succ);
        return root;
    }
}
 
int main()
{
    int c,v;
    tree *root=NULL;
	do
	{
		printf("\n1. Insert\n2. PREorder\n3. INorder\n4. POSTorder\n5. Delete\n6. EXIT\nEnter your choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the node to be inserted: ");
				scanf("%d",&v);
				root = insert(root,v);
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
            case 5:
                printf("Enter the node to be deleted: ");
                scanf("%d",&v);
                root = deletetree(root,v);
		}
	}while(c!=6);
    return 0;
}
