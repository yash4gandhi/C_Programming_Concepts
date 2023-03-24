/*
NAME      : YASH GANDHI
ROLL NO: 14
BRANCH: FE IT
BATCH   :C1

3. Write a program which reads the current year followed by N followed by a list of N employee
numbers and their current ages. Produce a list showing the years in which the employees retire
(become 65 years old). If more than one employee retires in given year then include them all
under the same heading.
*/

#include<stdio.h>
int main()
{
int y,n,emp[15],age[15],ry[15],temp,ctr,i,j,k;       /*Initializing variables and arrays*/
printf("\nenter the number of employees\n");
scanf("%d",&n);
printf("enter the current year\n");
scanf("%d",&y);

 for(i=0;i<n;i++)                                     /*Input of data*/
  {
   printf("enter employee number\n");
   scanf("%d",&emp[i]);
   printf("enter age\n");
   scanf("%d",&age[i]);
  }

  for(i=0;i<n;i++)                                    /*calculating retirement age*/
  {
    ry[i]=y+65-age[i];
  }

  for(j=0;j<(n-1);j++)                           /*sorting retirementage in ascending order&*/ 
  {
   for(i=0;i<(n-1-j);i++)
  {
   if(ry[i]>ry[i+1])
    {
     temp=ry[i];
     ry[i]=ry[i+1];
     ry[i+1]=temp;
     temp=emp[i];
     emp[i]=emp[i+1];
     emp[i+1]=temp;
    }
   }
  }

  printf("\nyear\t");
  printf("employee number\n");
  k=0;
  while(k<n)                                            /*output loop*/
  {
   printf("\n%d",ry[k]);
   ctr=0;
   for(j=0;j<n;j++)
  {
   if(ry[k]==ry[j])
    {
     printf("\t%d\n",emp[j]);
     ctr=ctr+1;
    }
   }
    k=k+ctr;
  }
return 0;
}

/*
OUTPUT

enter the number of employees
4
enter the current year
2000
enter employee number
1
enter age
25
enter employee number
2
enter age
24
enter employee number
3
enter age
23
enter employee number
4
enter age
25

year	employee number

2040	1
	4

2041	2

2042	3

*/

