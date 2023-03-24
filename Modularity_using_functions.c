/*
NAME:  YASH GANDHI
BRANCH:FE IT
BATCH :C1
ROLLNO:14

EXPERIMENT NUMBER 3
AIM:To apply concepts of functions to incorporate modularity

QUESTION 3:
  Write a function which takes as parameters two positive integers and returns true IF the numbers are amicable and FALSE otherwise.
  A pair of numbers is said to be amicable if the sum of the divisors of each of the numbers(excluding the number itself) is equal to the other number.ex 1184 and 1210 are amicable.
*/


#include<stdio.h>
int amicable(int m,int n)                /*function declaration*/
{
 int sum1=0,sum2=0,i;                    /*function definition*/
 for(i=1;i<=(m/2);i++)
  {
   if(m%i==0)
    sum1=sum1+i;                         /*adding divisors of the number*/
  }
 for(i=1;i<=(n/2);i++)
  {
   if(n%i==0) 
    sum2=sum2+i;                         /*adding divisors of second number*/
  }
 if(sum1==n&&sum2==m)                    /*checking condition for amicable numbers*/
  return 1;
 else
  return 0;
}
 
int main()
 {
  int num1,num2,z;
  printf("Enter number 1:");
  scanf("%d",&num1);
  printf("\nEnter number 2:");
  scanf("%d",&num2);
  z=amicable(num1,num2);                 /*function call*/
  if(z==1)
   printf("\nNumbers are Amicable");
  if(z==0)
   printf("\nNumbers are Not Amicable"); 
  return 0;
 } 

/*
OUTPUT:
Enter number 1:220

Enter number 2:284

Numbers are Amicable

Enter number 1:100

Enter number 2:50

Numbers are Not Amicable

*/
 
 
 
     
