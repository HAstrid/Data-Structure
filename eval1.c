#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int a[100],top=-1;

void push(int p)
{
 a[++top]=p;
}

int pop()
{
 return a[top--];
}

int display()
{
 printf("Evaluated expression is: %d\n",a[top]);
}

void main()
{
  char s[100];
  int i,j,check=0,check1=0,m=1,n,op1,op2;
  printf("Enter the Expression\n");
  scanf("%s",s);
  for(i=0;i<strlen(s);i++)
  {
   switch(s[i])
   {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':check++;
	     break;
    default:check1++;
   }
  }
  if((check==check1-1) && (isalpha(s[0]) || isdigit(s[0])) && (isalpha(s[1]) || isdigit(s[1])))
  {
   for(i=0;i<strlen(s);i++)
   {
    if(isalpha(s[i])!=0)
    {
     printf("Enter the value for the charecter %c \n",s[i]);
     scanf("%d",&n);
     push(n);
    }
    else if(isdigit(s[i])!=0)
    {
     n=s[i]-'0';
     push(n);
    }
    else
    {
     op1=pop();
     op2=pop();
     switch(s[i])
     {
      case '+':push(op2+op1);
	       break;
      case '-':push(op2-op1);
	       break;
      case '*':push(op2*op1);
	       break;
      case '/':push(op2/op1);
	       break;
      case '$':for(j=0;j<op1;j++)
		m=m*op2;
	        push(m);
	       break;
     }
    }
   }
  display();
  }
 else
  printf("Enter a valid expression\n");
}
