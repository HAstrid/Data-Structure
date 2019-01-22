#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

int top=-1,n;

void push(char a[n][10],char e[10])
{
 if(top==n-1)
 {
  printf("Stack Overflow\n");
 }
 else
  strcpy(a[++top],e);
}

void pop(char a[n][10])
{
 if(top==-1)
  printf("Stack underflow\n");
 else
  printf("\n %s is popped from stack \n",a[top--]);
}

void display(char a[n][10])
{
 if(top==-1)
  printf("Stack is empty\n");
 else
 {
  int j;
  for(j=top;j>-1;j--)
   printf("\n%s\n",a[j]);
 }
}

void peep(char a[n][10])
{
 if(top==-1)
  printf("Stack is empty\n");
 else
  printf("%s is the top most string \n",a[top]);
}

void main()
{
 int ch,j;
 char a[MAX][10],e[10];
 printf("Enter the size: \n");
 scanf("%d",&n);
 if(MAX<n || n==0)
 {
  printf("Give valid size\n");
  exit(0);
 }
 do
 {
  printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n");
  printf("Enter the choice: \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("Enter the string\n");
	  scanf("%s",e);
	  push(a,e);
	  break;
   case 2:pop(a);
	  break;
   case 3:peep(a);
	  break;
   case 4:display(a);
	  break;
   default:exit(0);
  }
 }while(1);
}

