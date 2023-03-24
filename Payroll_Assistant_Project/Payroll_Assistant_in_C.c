/*
Name : Jaynil,Yash,Shubham,Mihir
Roll no : 13,14,15,16
Branch : FE-IT
Batch : C1
Question : Write a program to process a simple company payroll. The foll. details are stored for each employee: name, rate of pay per hour and normal work week (in hours). The program is to read these details and one similar list containing the no. of hours worked by each employee in the current week; assume that employees are paid overtime at twice the normal rates. Arrange that the program, using simple tables, computes the income tax applicable and outputs a statement for each employee showing gross pay, net pay and tax withheld. Design a simple user interface using C graphics.
*/

#include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include<io.h>
#include<fcntl.h> 

typedef struct PayRoll{                                      /*Defining a structure PayRoll*/
	char Name [20];
	int HourlyPay;
	int WorkHours;
	int HoursWorked;
	int IncomeTax;
	int GrossPay;
	int NetPay;
}PayRoll;


void getRecord()                                                /*function to accept new records*/
{
	PayRoll p;
	wprintf(L"ENTER THE RECORD");
	wprintf(L"\n Enter the Name :");
	scanf("%s",p.Name);
	getchar();
	wprintf(L"\n Enter the Hourly Pay :");
	scanf("%d",&p.HourlyPay);
	wprintf(L"\n Enter the No of Work Hours :");
	scanf("%d",&p.WorkHours);
	wprintf(L"\n Enter the No of Hours Worked:");
	scanf("%d",&p.HoursWorked);
	getchar();
	if(p.HoursWorked>p.WorkHours)                                   /*check the condition for extra time of work*/
	{
		p.GrossPay=p.HourlyPay*(2*p.HoursWorked-p.WorkHours);
	}
	else
		p.GrossPay=p.HourlyPay*p.HoursWorked;
	p.IncomeTax=p.GrossPay*0.2;
	p.NetPay=p.GrossPay-p.IncomeTax;
	wprintf(L"╔══════════════════════════════════════════════════════════╗\n");
	wprintf(L"║Employee  pay per Work    Hours   Gross   Income  Net     ║\n");
	wprintf(L"║          Hour    Hours   Worked  pay(RS) Tax(RS) Pay(RS) ║\n");
	wprintf(L"╠══════════════════════════════════════════════════════════╣\n");
	wprintf(L"║%-10S%-8d%-8d%-8d%-8d%-8d%-8d║\n",p.Name,p.HourlyPay,p.WorkHours,p.HoursWorked,p.GrossPay,p.IncomeTax,p.NetPay);
	wprintf(L"╚══════════════════════════════════════════════════════════╝\n");
	getchar();
	FILE *fp;
	fp=fopen("Database","ab");
	if(fp == NULL)
    {
        wprintf(L"Error opening file\n");
        exit(1);
    }
	fwrite(&p,sizeof(PayRoll),1,fp);
	fclose(fp);
}

void ShowRecords()                                      /*function to show records*/
{
	PayRoll p;
	int Tax=0,GrossPay=0,NetPay=0;
	FILE *fp;
	fp=fopen("Database","rb");
	if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
	wprintf(L"╔══════════════════════════════════════════════════════════╗\n");
	wprintf(L"║Employee  pay per Work    Hours   Gross   Income  Net     ║\n");
	wprintf(L"║          Hour    Hours   Worked  pay(RS) Tax(RS) Pay(RS) ║\n");
	wprintf(L"╠══════════════════════════════════════════════════════════╣\n");
	while(fread(&p,sizeof(PayRoll),1,fp)==1)
	{
		GrossPay+=p.GrossPay;
		Tax+=p.IncomeTax;
		NetPay+=p.NetPay;
		wprintf(L"║%-10S%-8d%-8d%-8d%-8d%-8d%-8d║\n",p.Name,p.HourlyPay,p.WorkHours,p.HoursWorked,p.GrossPay,p.IncomeTax,p.NetPay);
	}
	wprintf(L"╠══════════════════════════════════════════════════════════╣\n");
	wprintf(L"║TOTAL-----------------------------%-8d%-8d%-8d║\n",GrossPay,Tax,NetPay);
	wprintf(L"╚══════════════════════════════════════════════════════════╝\n");
	fclose(fp);
	getchar();
	getchar();
}

void SearchRecord(char *s)                                                       /*function to search records*/
{
	PayRoll p;
	FILE *fp;
	fp=fopen("Database","rb");
	if(fp == NULL)
    {
        wprintf(L"Error opening file\n");
        exit(1);
    }
	int flag=0;
	wprintf(L"╔══════════════════════════════════════════════════════════╗\n");
	wprintf(L"║Employee  pay per Work    Hours   Gross   Income  Net     ║\n");
	wprintf(L"║          Hour    Hours   Worked  pay(RS) Tax(RS) Pay(RS) ║\n");
	wprintf(L"╠══════════════════════════════════════════════════════════╣\n");
	while(fread(&p,sizeof(PayRoll),1,fp)==1)
	{
		
	
		if(!strncmp(s,p.Name,strlen(s)))
		{
		wprintf(L"║%-10S%-8d%-8d%-8d%-8d%-8d%-8d║\n",p.Name,p.HourlyPay,p.WorkHours,p.HoursWorked,p.GrossPay,p.IncomeTax,p.NetPay);
		flag=1;
		}
	}
	if (flag==0)
		wprintf(L"║                    No such Record Exists                 ║\n");
	fclose(fp);
	    wprintf(L"╚══════════════════════════════════════════════════════════╝\n");

	getchar();
	getchar();
}

void DeleteRecord(char *s)                                               /*function to delete records*/
{
	PayRoll p;
	FILE *fp,*tmpfile;
	fp=fopen("Database","rb");
	if(fp == NULL)
    {
        wprintf(L"Error opening file\n");
        return;
    }
	tmpfile=fopen("TDatabase","wb");
	if(tmpfile == NULL)
    {
        wprintf(L"Error opening file\n");
        return;
    }
	int flag=0;
	while(fread(&p,sizeof(PayRoll),1,fp)==1)
	{
		if(!strncmp(s,p.Name,strlen(s)))
		{
			flag=1;
		}
		else
		{
			fwrite(&p,sizeof(PayRoll),1,tmpfile);
		}
	}
	if (flag==0)
		wprintf(L"No such Record Exists");
	else
		wprintf(L"Record has been Deleted");
	fclose(fp);
	fclose(tmpfile);
	remove("Database");
	rename("TDatabase","Database");
	getchar();
	getchar();
}
void modifyRecord(char *s)                                              /*function to modify records*/
{
	PayRoll p;
	FILE *fp,*tmpfile;
	fp=fopen("Database","rb");
	if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }
	tmpfile=fopen("TDatabase","wb");
	if(tmpfile == NULL)
    {
        printf("Error opening file\n");
        return;
    }
	int flag=0;
	while(fread(&p,sizeof(PayRoll),1,fp)==1)
	{
		if(!strncmp(s,p.Name,strlen(s)))
		{
			flag=1;
			wprintf(L"ENTER THE RECORD");
			wprintf(L"\n Enter the Name :");
			scanf("%s",p.Name);
			getchar();
			wprintf(L"\n Enter the Hourly Pay :");
			scanf("%d",&p.HourlyPay);
			wprintf(L"\n Enter the No of Work Hours :");
			scanf("%d",&p.WorkHours);
			wprintf(L"\n Enter the No of Hours Worked:");
			scanf("%d",&p.HoursWorked);
			getchar();
			if(p.HoursWorked>p.WorkHours)
			{
				p.GrossPay=p.HourlyPay*(2*p.HoursWorked-p.WorkHours);
			}
			else
				p.GrossPay=p.HourlyPay*p.HoursWorked;
			p.IncomeTax=p.GrossPay*0.2;
			p.NetPay=p.GrossPay-p.IncomeTax;
			wprintf(L"╔══════════════════════════════════════════════════════════╗\n");
			wprintf(L"║Employee  pay per Work    Hours   Gross   Income  Net     ║\n");
			wprintf(L"║          Hour    Hours   Worked  pay(RS) Tax(RS) Pay(RS) ║\n");
			wprintf(L"╠══════════════════════════════════════════════════════════╣\n");
			wprintf(L"║%-10S%-8d%-8d%-8d%-8d%-8d%-8d║\n",p.Name,p.HourlyPay,p.WorkHours,p.HoursWorked,p.GrossPay,p.IncomeTax,p.NetPay);
			wprintf(L"╚══════════════════════════════════════════════════════════╝\n");
			getchar();
			fwrite(&p,sizeof(PayRoll),1,tmpfile);

		}
		else
		{
			fwrite(&p,sizeof(PayRoll),1,tmpfile);
		}
	}
	if (flag==0)
		printf("No such Record Exists");
	else
		printf("Record has been Deleted");
	fclose(fp);
	fclose(tmpfile);
	remove("Database");
	rename("TDatabase","Database");
	getchar();
}

void main()
{
	system("mode 25,12");                                           /*Resizes the window */
	_setmode(_fileno(stdout),_O_U16TEXT);                              
	system("COLOR E4");                                             /*Applying colour on text */
	
	
	int c=0;
	while(c!=6){
	system("mode 25,12");
	wprintf(L"╔═══╦══════════════════╗\n");
	wprintf(L"║   ║     Main Menu    ║\n");
	wprintf(L"╠═══╬══════════════════╣\n");
	wprintf(L"║ 1 ║ Enter New Record ║\n");
	wprintf(L"║ 2 ║ Search record    ║\n");
	wprintf(L"║ 3 ║ Show all Records ║\n");
	wprintf(L"║ 4 ║ Delete Records   ║\n");
	wprintf(L"║ 5 ║ Modify Records   ║\n");
	wprintf(L"║ 6 ║ Exit             ║\n");
	wprintf(L"╚═══╩══════════════════╝\n");
	/*
	printf("+----------------------+\n");
	printf("|   |     Main Menu    |\n");
	printf("+---+------------------+\n");
	printf("| 1 | Enter New Record |\n");
	printf("| 2 | Search record    |\n");
	printf("| 3 | Show all Records |\n");
	printf("| 4 | Delete Records   |\n");
	printf("| 5 | Modify Records   |\n");
	printf("| 6 | Exit             |\n");
	printf("+---+------------------+\n");
	*/
	scanf("%d",&c);
	system("cls");
	char s [20];
	switch(c)                                                        /*function calls for each case*/
	{
		case 1:
		system("mode 61,16");                                    /*Applying width of 60, height of 16 */
		getRecord();
		break;
		
		case 2:
		system("mode 61,12");
		wprintf(L"Enter the Employee Name\n");
		scanf("%s",s);
		SearchRecord(s);
		break;
		
		case 3:
		system("mode 61,61");
		ShowRecords();
		break;
		
		case 4:
		system("mode 26,5");
		wprintf(L"Enter the Employee Name\n");
		scanf("%s",s);
		DeleteRecord(s);
		break;
		
		case 5:
		system("mode 61,18");
		wprintf(L"Enter the Employee Name\n");
		scanf("%s",s);
		modifyRecord(s);
		break;
		
		case 6 :
		system("mode 61,18");
		break;
	}
	
	system("cls");
	}
}
