#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int ar[100],top=-1;

 void push(int p)
{
 ar[++top]=p;
}

 int pop()
{
 return ar[top--];
}

 void display()
{
 printf("Evaluated exprestion is: %d\n",ar[top]);
}

 void main()
{
 char str[100];
 int i,j,op1,op2,check=0,check1=0,n,m=1;
 printf("Enter the expression\n");
 scanf("%s",str);
 for(i=0;i<strlen(str);i++)
 {
  switch(str[i])
  {
   case '+':
   case '-':
   case '*':
   case '/':
   case '$':
	    check++;
	    break;
   default:
	    check1++;
  }
 }
 if((check==check1-1) && (isalpha(str[0])||isdigit(str[0])) && (isalpha(str[1])||isdigit(str[1])))
 {
  for(i=0;i<strlen(str);i++)
  {
   if(isalpha(str[i])!=0)
   {
    printf("Enter the value for the charecter %c: \n",str[i]);
    scanf("%d",&n);
    push(n);
   }
   else if(isdigit(str[i])!=0)
   {
    n=str[i]-'0';
    push(n);
   }
   else
   {
    op1=pop();
    op2=pop();
    switch(str[i])
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
     case '$':
	      for(j=0;j<op1;j++)
		m=m*op2;
		push(m);
		break;
    }
   }
  }
 display();
 }
 else
  printf("Enter valid expression\n");
 //display();
}
