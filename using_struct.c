
/*
NAME  :YASH GANDHI
BRANCH:FE IT
BATCH :C1
ROLLNO:14

AIM:To apply concepts of structures

Q 4. A record in an organisations payroll consists of one line for each employee consisting of:
NAME (20 characters), SEX (1 character M or F), SALARY (integer), DATE OF
BIRTH (3 integers YEAR MONTH DAY).
Write a program which will input 10 such records. Your program must then take in 5
amendments in the record set which will be in the same form as the record structure itself.The amendments can contain new employees to be added (name different from existing
ones), employees left (salary given as 0) and update of salary(more or less). Your program
must then incorporate these amendments and also remove those employees who have reached
retirement age(Age 60).

*/

#include<stdio.h>
#include<string.h>
struct record
{
 char name[20];
 char gender[1];
 int salary;
 struct birthdate
     {

      int year,month,day;

     }dob;
 int age;
};

void details(record emp[],int n,int y)
{
 int i;
 printf("Please enter the details of the %d employees\n",n);
 for(i=0;i<n;i++)
 {
   printf("\nEnter name\n");
   scanf("%s",emp[i].name);
   printf("Enter gender M/F\n");
   scanf("%s",emp[i].gender);
   printf("Enter salary\n");
   scanf("%d",&emp[i].salary);
   printf("Enter date of birth in the form y/m/d separated by spaces\n");
   scanf("%d %d %d",&emp[i].dob.year,&emp[i].dob.month,&emp[i].dob.day);
   emp[i].age=y-emp[i].dob.year;
 }

 return;

}

void amend(record cemp[],int m,int y)
{
 int i;
 printf("Enter amendments\n");
 for(i=0;i<m;i++)
 {
   printf("\nEnter name,  gender(M/F), salary, birthdate(y m d) separated by spaces\n");
   scanf("%s %s %d %d %d %d",cemp[i].name,&cemp[i].gender,&cemp[i].salary,&cemp[i].dob.year,&cemp[i].dob.month,&cemp [i].dob.day);
   cemp[i].age=y-cemp[i].dob.year;
 }

 return;
}


void change(record emp[],int n,record cemp[],int m)
{
 int i,j,k,h=0;
 int ctr=0;
 int x;

 for(j=0;j<n;j++)
 {
  for(i=0;i<m;i++)
   {
    if(strcmp(emp[j].name,cemp[i].name)==0)
    emp[j]=cemp[i];

   else
    {
      emp[n+ctr]=cemp[i];
      ctr=ctr+1;
    }
   }

}
 x=n+ctr;
for(i=0;i<(x-h);i++)
{
  if((emp[i].salary==0)||(emp[i].age>=60))
    {
     for(j=i;j<(x-h);j++)
      {
      emp[j]=emp[j+1];
      }
      h=h+1;
    }

}
  for(j=0;j<(n+ctr-h);j++)
  {
    printf("\nNumber %d\n",j);
    printf("Name-%s  Gender-%s  Salary-%d  Age-%d  Byear-%d  Bmonth-%d  Bday-%d\n",emp[j].name,emp[j].gender,emp[j].salary,emp[j].age,emp[j].dob.year,emp[j].dob.month,emp[j].dob.day);
  }

return;
}

int main()
{
  struct record emp[50];
  struct record cemp[50];
  int m,n,y,;

  printf("Enter number of employees\n");
  scanf("%d",&n);
  printf("Enter current year\n");
  scanf("%d",&y);
  details(emp,n,y);

  printf("\nEnter number of amendments\n");
  scanf("%d",&m);
  amend(cemp,m,y);

  printf("\nAfter changes\n");
  change(emp,n,cemp,m);
return 0;
}

/*
OUTPUT-
Enter number of employees
5
Enter current year
100
Please enter the details of the 5 employees

Enter name
YASH
Enter gender
M
Enter salary
20000
Enter date of birth in the form y/m/d separated by spaces
70 1 4

Enter name
JAMES
Enter gender
M
Enter salary
30000
Enter date of birth in the form y/m/d separated by spaces
60 2 3

Enter name
DEV
Enter gender
M
Enter salary
35000
Enter date of birth in the form y/m/d separated by spaces
55 3 4

Enter name
DAVID
Enter gender
M
Enter salary
20000
Enter date of birth in the form y/m/d separated by spaces
50 1 2

Enter name
JOY
Enter gender
F
Enter salary
40000
Enter date of birth in the form y/m/d separated by spaces
60 1 4

Enter number of amendments
3
Enter amendments

Enter name, gender, salary, birthdate(y m d) separated by spaces
YASH M 0 70 1 4

Enter name, gender, salary, birthdate(y m d) separated by spaces
JAMES M 20000 30 1 2

Enter name, gender, salary, birthdate(y m d) separated by spaces
SRI F 30000 70 1 2

After changes

Number 0
Name-DEV Gender-M Salary-35000 Age-45 Byear-55 Bmonth-3 Bday-4

Number 1
Name-DAVID Gender-M Salary-20000 Age-50 Byear-50 Bmonth-1 Bday-2

Number 2
Name-JOY Gender-F Salary-40000 Age-40 Byear-60 Bmonth-1 Bday-4

Number 3
Name-SRI Gender-F Salary-30000 Age-30 Byear-70 Bmonth-1 Bday-2


*/

