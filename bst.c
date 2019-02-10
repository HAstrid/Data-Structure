#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* left;
 struct node* right;
};

 struct node* createnode(int v)
{
 struct node* newnode=malloc(sizeof(struct node));
 newnode->data=v;
 newnode->left=NULL;
 newnode->right=NULL;
 return newnode;
}

 struct node* insert(struct node* root,int data)
{
 if(root==NULL)
 {
  return createnode(data);
 }
 if(data < root->data)
  root->left=insert(root->left,data);
 else if(data > root->data)
  root->right=insert(root->right,data);
}

 void inorder(struct node* root)
{
 if(root==NULL)
  return;
 inorder(root->left);
 printf("%d\t",root->data);
 inorder(root->right);
}

 void preorder(struct node* root)
{
 if(root==NULL)
  return;
 printf("%d\t",root->data);
 preorder(root->left);
 preorder(root->right);
}

 void postorder(struct node* root)
{
 if(root==NULL)
  return;
 postorder(root->left);
 postorder(root->right);
 printf("%d\t",root->data);
}

 int height(struct node* root)
{
 if(root==NULL)
  return 0;
 else
 {
  int lheight=height(root->left);
  int rheight=height(root->right);
  if(lheight>rheight)
   return(lheight+1);
  else
   return(rheight+1);
 }
}

 void printlevel(struct node* ,int );

 void levelorder(struct node* root)
{
 int h=height(root);
 int i;
 for(i=1;i<=h;i++)
  printlevel(root,i);
}

 void printlevel(struct node* root,int level)
{
 if(root==NULL)
  return;
 if(level==1)
  printf("%d\t",root->data);
 else if(level>1)
 {
  printlevel(root->left,level-1);
  printlevel(root->right,level-1);
 }
}

 void main()
{
 int ch,val;
 struct node* root=NULL;
 printf("Enter the root node\t");
 scanf("%d",&val);
 root=insert(root,val);
 printf("Root node %d inserted to the tree\n",root->data);
 do
 {
  printf("\nBinary Search Tree\n");
  printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Level order\n6.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
	  printf("Enter the data\n");
	  scanf("%d",&val);
	  insert(root,val);
	  break;
   case 2:
	  printf("Inorder:\n");
	  inorder(root);
	  break;
   case 3:
	  printf("Preorder:\n");
	  preorder(root);
	  break;
   case 4:
	  printf("Postorder:\n");
	  postorder(root);
	  break;
   case 5:
	  printf("Level order:\n");
	  levelorder(root);
	  break;
   default:
	   exit(0);
  }
 }while(1);
}
