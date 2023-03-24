/*
Name  :YASH GANDHI
BRANCH:FE IT
BATCH : C1
Rollno:14
*/
/*
Aim: To explore the concept of application of Queue as linear data structure.
1. Consider a single queueing system for a food joint. There is a single queue of customers.
The customers however, are served by three different counters. The moment a counter is
free, the first customer in the queue is serviced at the counter. It is possible that at a
particular time instant only 2 counters are free to serve customers, so at that point the first
2 customers are removed from the queue for servicing. Simulate this system’s behavior.
Your program must:
i. Create a queue for n customers
ii. At every instant of time ask for how many counters are free(k) and then remove
k customers from the queue accordingly. (Do this till all n customers are serviced.
Assume: There are no new customers adding to the queue.)
iii. Display the queue contents at each instant after removing customer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int customer;
    struct node *next;
}node;

void enqueue(int c,int *nodeCount,node **front,node **rear)	
                    /*Function to Add element to queue*/
{
        node *newnode =(node*)malloc(sizeof(node));
        if(newnode==NULL)/*if memory could not be allotted*/
    {
        printf("Unable to allocate node\n");
        return;
    }
    newnode->customer=c;
    newnode->next=NULL;
    if(*nodeCount==0)/*if the node is the first node*/
         {
                *front=newnode;/*head and tail are both the newnode node as list has only one element*/
                *rear=newnode;
         }
    else
        {
                (*rear)->next = newnode;/*previous tail now points to newnode node*/
                *rear = newnode;/*newnode node now becomes the new tail*/
        }
    (*nodeCount)++;
}
void dequeue(node **front,int *nodeCount)		/*Function to remove element from queue*/
{       
        node *newnode=*front;
        printf("customer %d is served\n",newnode->customer);
        *front=newnode->next;
        free(newnode);
        (*nodeCount)--;
        
}
void display(node *front)	/*Function to display queuedata*/
{
        node* newnode=front;
        printf("Queue from front:\n");
        while(newnode!=NULL)
        {
                printf("%d\n",newnode->customer);
                newnode=newnode->next;
        }
}

int main()
{       
	node *rear, *front;
        int nodeCount=0;
        int n,i,quit=1,counters;
        int invalid;
        printf("How many customers?\n");
        scanf("%d",&n);		/*Gets initial number of customers*/
        for(i=1;i<=n;i++)
        {
                enqueue(i,&nodeCount,&front,&rear);	/*Enqueues the customers Token number*/
        }
        display(front);		/*Displays the Token numbers in order*/
        while(quit)
        {       
		invalid=1;
                printf("Enter 0 to quit and 1 to continue\n");
                scanf("%d",&quit);	
                if(quit==1)
                {
                        
                       while(invalid)
                       {       
			       printf("How many counters are free?\n");
                               scanf("%d",&counters);	/*Asks for number of counters empty*/
                                 if(counters>3)		/*Checks for limit of counters*/
                                {
                                        printf("Invalid input!There are only 3 counters!\n");
                                }
                                 else
                                 {
                                        invalid=0;
                                 	for(i=0;i<counters;i++)
                               		 { 
                                 	     if(nodeCount==0)	
/*Checks if queue is empty*/
                                 	     {
                                 	     	  printf("Queue is already empty!\n");
                                  	    	  break;
                                   	     }
                                   	     dequeue(&front,&nodeCount);    	/*Dequeues the customer and is served*/
                                	 }
                                 }
                       }
               		 if(nodeCount!=0)	/*Checks if queue is empty or not*/
                		display(front);	/*Displays queue present*/
                }
        
        }
return 0;
}
/*OUTPUT
How many customers?
10
Queue from front:
1
2
3
4
5
6
7
8
9
10
Enter 0 to quit and 1 to continue
1
How many counters are free?
3
customer 1 is served
customer 2 is served
customer 3 is served
Queue from front:
4
5
6
7
8
9
10
Enter 0 to quit and 1 to continue
1
How many counters are free?
2
customer 4 is served
customer 5 is served
Queue from front:
6
7
8
9
10
Enter 0 to quit and 1 to continue
1
How many counters are free?
4
Invalid input!There are only 3 counters!
How many counters are free?
3
customer 6 is served
customer 7 is served
customer 8 is served
Queue from front:
9
10
Enter 0 to quit and 1 to continue
1
How many counters are free?
3
customer 9 is served
customer 10 is served
Queue is already empty!
Enter 0 to quit and 1 to continue
0
*/
