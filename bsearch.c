#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX],n,i,j,ele;

void getdata()
{
 printf("Enter the size of array\n");
 scanf("%d",&n);
 if(MAX<n)
 {
  printf("Array out of bound\n");
  exit(0);
 }
 printf("Enter the elements\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 printf("Enter the search element\n");
 scanf("%d",&ele);
}

void linear()
{
 int flag=0;
 getdata();
 for(i=0;i<n;i++)
 {
  if(a[i]==ele)
  {
   flag=1;
   break;
  }
 }
 if(flag==1)
  printf("Found at %d postion\n",i+1);
 else
  printf("Not Found\n");
}

void binary()
{
 int flag=0,temp;
 getdata();
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("Sorted array is:\n");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 printf("\n");
 int high=n-1,low=0,mid;
 while(high>low)
 {
  mid=(low+high)/2;
  if(a[mid]==ele)
  {
   flag=1;
   break;
  }
  else if(a[mid]<ele)
  {
   low=mid+1;
   high=n-1;
  }
  else
  {
   high=mid+1;
   low=0;
  }
 }
 if(flag==1)
  printf("Found at %d position\n",mid+1);
 else
  printf("Not found\n");
}

void main()
{
 int ch;
 do
 {
  printf("1.Linear Search\n2.Binary Search\n3.Exit\n");
  printf("Enter the choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:linear();
	  break;
   case 2:binary();
	  break;
   default:exit(0);
  }
 }while(1);
}
