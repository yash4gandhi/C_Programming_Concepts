/*
Name   :YASH GANDHI
Branch:FE IT
Batch  :C1
Rollno:14

Aim: ? To explore files as data structure

Q.Set up a file containing vehicle records which hold registration number
and owner information (name and address). Write a program which, given a vehicle’s
registration number, will rapidly retrieve and print the owner information.
*/

#include<stdio.h>
#include<string.h>
typedef struct                                                         /*Defining the structure variables*/
{
  char reg_no[20];
  char name[20];
  char address[20];
}Vehicle;

void vehicle_details(char fname[20],int n)    /*function declaration*/ 
{                                                                              /*function definition for input*/
  Vehicle v;
  FILE *fp;                                                                /*initializing file pointer*/
  int i;
  fp=fopen(fname,"w");                                        /*new file opened in the write mode*/
  for(i=0;i<n;i++)
  {
    printf("\nEnter the Name of the Owner\n");
    scanf("%s",v.name);
    printf("Enter the Address of the Owner\n");
    scanf("%s",v.address);
    printf("Enter the Registration Number of the vehicle\n");
    scanf("%s",v.reg_no);
    fprintf(fp,"%s %s %s\n",v.name,v.address,v.reg_no);
  }
  fclose(fp);
}

int search(char fname[20],int n,char regno[20])     /*function declaration*/    
{                                                                                      /*function definition for search*/    
  Vehicle v;
  FILE *fp;
  int i,m;
  int flag=0;
  fp=fopen(fname,"r");                                            /*open the previously formed file*/
  for(i=0;i<n;i++)
  {
    fscanf(fp,"%s %s %s\n",v.name,v.address,v.reg_no);
    m=strcmp(v.reg_no,regno);                                         /*find the reg number in file*/  
    if(m==0)
    {
      printf("\nThe name of the owner is %s\n",v.name);
      printf("The address of the owner is %s\n",v.address);
      printf("The registration number of the vehicle is %s\n",v.reg_no);
      flag=1;
      break;
    }
  }
  fclose(fp);
  return flag;
}

int main()
{
  int n,ans;
  char regno[20];
  char filename[20];
  printf("Enter the number of owners\n");
  scanf("%d",&n);
  printf("Enter the filename\n");
  scanf("%s",filename);
  vehicle_details(filename,n);                                                       /*function call*/
  printf("\nEnter the registration number to be checked\n");
  scanf("%s",regno);
  ans=search(filename,n,regno);                                                /*function call*/
  if (ans==0)
  printf("Registration number not found");
  return(0);
}

/*

OUTPUT-

Enter the number of owners
3
Enter the filename
registration

Enter the Name of the Owner
YASH
Enter the Address of the Owner
MUMBAI
Enter the Registration Number of the vehicle
MH-12-345

Enter the Name of the Owner
VIR
Enter the Address of the Owner
PUNE
Enter the Registration Number of the vehicle
MH-23-456

Enter the Name of the Owner
JAME
Enter the Address of the Owner
MUMBAI
Enter the Registration Number of the vehicle
MH-34-567

Enter the registration number to be checked
MH-23-456

The name of the owner is VIR
The address of the owner is PUNE
The registration number of the vehicle is MH-23-456

OUTPUT2-

Enter the number of owners
3
Enter the filename
REGISTRATION

Enter the Name of the Owner
YASH
Enter the Address of the Owner
MUM
Enter the Registration Number of the vehicle
MH-12-34

Enter the Name of the Owner
VIR
Enter the Address of the Owner
PUN
Enter the Registration Number of the vehicle
MH-23-45

Enter the Name of the Owner
JAME
Enter the Address of the Owner
MUM
Enter the Registration Number of the vehicle
MH-34-56

Enter the registration number to be checked
MH-27-78
Registration number not found

*/








