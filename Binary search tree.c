#include <stdio.h>
#include <stdlib.h>
struct tree {
	int data;
	struct tree*left;
	struct tree*right;
};
struct tree *insert(struct tree*,int);
struct tree *delete(struct tree*,int);
struct tree *search(struct tree*);
void inorder(struct tree*);


struct tree *insert(struct tree* root,int x)
{
	if(!root)
	{
		root=(struct tree*)malloc(sizeof(struct tree));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
		return(root);
	}
	if(root->data>x)
	{
		root->left=insert(root->left,x);
	}
	else
	{
		if (root->data<x)
		{
			root->right=insert(root->right,x);
		}
	}
	return(root);
}



struct tree *delete(struct tree *ptr,int x)
{
	struct tree *p1,*p2;
	if(!ptr)
	{
		printf("\nEntered node not found in tree\n");
		return(ptr);
	}
	else
	{
		if(ptr->data<x)
		{
			ptr->right=delete(ptr->right,x);
		}
		else if(ptr->data>x)
		{
			ptr->left=delete(ptr->left,x);
			return ptr;
		}
		else
		{
			if(ptr->data==x)
			{
				if(ptr->left==ptr->right)
				{
					free(ptr);
					return(NULL);
				}
				else if(ptr->left==NULL)
				{
					p1=ptr->right;
					free(ptr);
					return p1;
				}
				else if(ptr->right==NULL)
				{
					p1=ptr->left;
					free(ptr);
					return p1;
				}
				else
				{
					p1=ptr->right;
					p2=ptr->right;
					while(p1->left!=NULL)
					{
						p1=p1->left;
						p1->left=ptr->left;
						free(ptr);
						return p2;
					}
				}
			}
		}

	}
	return(ptr);
}



struct tree *search(struct tree*root)
{
	int ele;
	struct tree *ptr;
	ptr=root;
	printf("\nEnter the element to be search\n");
	scanf("%d",&ele);
	while(ptr)
	{
		if(ele>ptr->data)
		{
			ptr=ptr->right;
		}
		else if(ele<ptr->data)
		{
			ptr=ptr->left;
		}
		else
		{
			break;
		}
	}
	if(ptr)
	{
		printf("\n Element %d was found",ele);
	}
	else
	{
		printf("\n Element %d does not found in the tree",ele);
	}
	return(root);
}


void inorder(struct tree*root)
{
	if(root !=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
	return;
}
int main()
{
	struct tree*root;
	int ch,ele,item;
	root=NULL;
	setbuf(stdout,NULL);
	while(1)
	{
		printf("Enter your choice\n1.Insert\n2.Delete\n3.Search\n4.In-order Traversal\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter the element to insert\n");
			scanf("%d",&ele);
			root=insert(root,ele);
			break;
		case 2:
			printf("\nEnter the element to  delete\n");
			scanf("%d",&item);
			root=delete(root,item);
			break;
		case 3:
			printf("\nSearching:\n");
			root=search(root);
			break;
		case 4:
			printf("\nIn-order traversal is:\n");
			inorder(root);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nEnter a valid choice\n");
		}
	}
	return(0);
}

