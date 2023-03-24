/*
NAME     : YASH GANDHI
BRANCH:FE IT
BATCH   :C1
ROLLNO:14
AIM:To use concepts of linked lists

Q. Imagine an IPL coach is maintaining the records for the all batsman in his team. The data
which he needs is players name, country and his score. The coach can have 10 to 15 standby
batsman. Out of this standby coach needs to identify candidate batsman which can play in the
tournament. The condition for selection is that the batsman has better score than average of
all standby batsman. Write a program such that coach should be able to add new batsman,
remove a batsman, display all batsman, display average score and display list of batsman
who qualify based on condition from list.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct batsman //defining a struct for batsman details
{
        char name[20];//name of the player
        char country[20];//country of the player
        double score;//score of the player
        struct batsman *next;//self referencing struct for linked list
}*head,*head2,*temp,*head1,*head3,*temp1;
struct batsman* alloc(char a[], char b[], double c)//function to allocate memory for struct
{
        struct batsman *p= (struct batsman*)malloc(sizeof(struct batsman));
        if (p != NULL)//if address does have something
        {
                strcpy(p->name,a);//to copy the details of the player
                strcpy(p->country,b);
                p->score = c;
                p->next = NULL;
        }
        return p;
}
void display() //to display the player details
{
        struct batsman *p= head2;
        while (p != NULL)
        {
                        printf("%s\t%s\t%lf\n",p->name,p->country,p->score);
                p = p->next;//to go to the next element
        }
}
void removal(char m[])//to remove a particular player from list
{
        struct batsman * p = head2;
        struct batsman * q = head2;
        while(p->next != NULL)
        {
                if(strcmp(head2->name,m)==0)
                {
                  p=p->next;//to go one element behind if above condition is true
                        free(head2);//to free the alloted space
                        head2 = p;
                        break;
                }
                p = p->next;
                if(strcmp(p->name,m)==0)
                {
                        q->next = p->next;
                        q=p->next;
                        free(p);
                        p=q;
                        break;
                }
                q = q->next;
        }
        display();
}
double average()//function to calculate the average of all scores
{
        double y=0, i=0,average; 
        struct batsman * x = head2;
        while(x!= NULL)
        {
                        y= y + x->score;//to compute entire score
                        i++;
                        x= x->next;
        }
        average = y/i;
        printf("The average score of all the batsmen : %lf\n", average);
        return (average);
}
void display1() 
{
        struct batsman *m= head3;
        while (m != NULL)
        {
                printf("%s\t%s\t%lf\n",m->name,m->country,m->score);
                m = m->next;
        }
}
void newlist(double sc)//to create a new list if player score greater than average
{
        int count = 0;
        struct batsman* y= head2;
        printf("Batsmen in the playing list : \n");
        while(y != NULL)
        {
                if((y->score) > sc)
                {
                        if (count==0)// for first player
                        {
                                head1= alloc(y->name,y->country,y->score);
                                head3 = head1;
                        }
                        else //for other players
                        {
                                temp1= alloc(y->name,y->country,y->score);
                                head1->next = temp1;
                                head1= temp1;
                        }
                        count++;
                }
                y= y->next;
        }
        display1();
        
}
void oldlist(double sc)
{
        int count = 0;
        struct batsman* y= head2;
        printf("Batsmen not in the playing list : \n");
        while(y != NULL)
        {
                if((y->score) < sc)
                {
                        if (count==0)// for first player
                        {
                                head1= alloc(y->name,y->country,y->score);
                                head3 = head1;
                        }
                        else //for other players
                        {
                                temp1= alloc(y->name,y->country,y->score);
                                head1->next = temp1;
                                head1= temp1;
                        }
                        count++;
                }
                y= y->next;
        }
        display1();
}

void main()
{
        char name[20], country[20];
        double score,avg;
        int query = 0, i = 0,t;
        while(query==0)//to check if user wants to add more players
        {
                printf("Enter the name of the player\n");
                scanf("%s", name);
                printf("Enter the country\n");
                scanf("%s", country);
                printf("Enter the score of the player\n");
                scanf("%lf",&score);
                if(i == 0)
                {
                        head = alloc (name, country, score);
                        head2 = head;
                }
                else
                {
                        temp = alloc(name, country, score);
                        head->next = temp;
                        head = temp;
                }
                i++;
                printf("If you wish to add another player press 0, else press 1\n");
                scanf("%d",&query);
        }
        display();
        do
        {
                printf("To add a player, press 1\n");
                printf("To remove a player, press 2\n");
                printf("To display average, press 3\n");
                printf("To display players above average, press 4\n");
                int x;
                scanf("%d",&x);
                switch (x)
                {
                        case 1: printf("Enter the name of the player\n");
                                        scanf("%s", name);
                                        printf("Enter the country\n");
                                        scanf("%s", country);
                                        printf("Enter the score\n");
                                        scanf("%lf",&score);
                                        temp=alloc(name, country, score);
                                        head->next = temp;
                                        head = temp;
                                        display();
                                        break;
                        case 2: printf("Enter the name of player to be removed\n");
                                        char m[20];
                                        scanf("%s", m);
                                        removal(m);
                                        break;
                        case 3: avg = average();
                                        break;
                        case 4: avg =average();
                                        newlist(avg);
                                        oldlist(avg);
                                        break;
                }
                printf("To continue, press 1 or to exit, press 2\n");
                scanf("%d", &t);
        }while(t==1);//to execute different switch cases until user wants to end the program
}

/*OUTPUT :
Enter the name of the player
ABC
Enter the country
ASD
Enter the score of the player
123
If you wish to add another player press 0, else press 1
0
Enter the name of the player
QWE
Enter the country
FHJ
Enter the score of the player
233 
If you wish to add another player press 0, else press 1
0
Enter the name of the player
RYH
Enter the country
EYY
Enter the score of the player
168       
If you wish to add another player press 0, else press 1
1
ABC	ASD	123.000000
QWE	FHJ	233.000000
RYH	EYY	168.000000
To add a player, press 1
To remove a player, press 2
To display average, press 3
To display players above average, press 4
3
The average score of all the batsmen : 174.666667
To continue, press 1 or to exit, press 2
4


Enter the name of the player
ABC
Enter the country
QWE
Enter the score of the player
123
If you wish to add another player press 0, else press 1
0
Enter the name of the player
ABFJ
Enter the country
TRUU
Enter the score of the player
749
If you wish to add another player press 0, else press 1
0
Enter the name of the player
FGER
Enter the country
TSRH
Enter the score of the player
41
If you wish to add another player press 0, else press 1
1
ABC	QWE	123.000000
ABFJ	TRUU	749.000000
FGER	TSRH	41.000000
To add a player, press 1
To remove a player, press 2
To display average, press 3
To display players above average, press 4
4
The average score of all the batsmen : 304.333333
Batsmen in the playing list : 
ABFJ	TRUU	749.000000
Batsmen not in the playing list : 
ABC	QWE	123.000000
FGER	TSRH	41.000000
To continue, press 1 or to exit, press 2
2
*/
