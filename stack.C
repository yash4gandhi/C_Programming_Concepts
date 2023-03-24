/*
NAME  :YASH GANDHI
BRANCH:FE IT
BATCH :C1
Rollno:14

Aim:  To explore the concept of application of Stack as a linear data structure

Q.Write a program to evaluate a postfix expression using a stack.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE     //Structure for node of linked list
{
	int data;
	struct NODE *next;
}node;
typedef struct STACK    //Structure for stack
{
	node *last;
}stack;
void init(stack *p)     //Function for initialization of stack
{
	p->last=NULL;
}
void push(stack *p,int data)    //Function to push data on to the stack
{
	node *newnode;          //Creates a node pointer
	newnode=(node*)malloc(sizeof(node));    // dynamic Memory allocation
	if(newnode==NULL)       //Checks if stack is full
		printf("Stack is full\n");
	else
	{
		newnode->data=data;
		newnode->next=p->last;
		p->last=newnode;
	}
}
int pop(stack *p)               //Function to pop data from the stack
{
	if(p->last==NULL)       //Checks if stack is empty
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		node *temp;
		temp=p->last;
		int v=temp->data;
		p->last=temp->next;
		free(temp);
		return v;
	}
}
int main(void)
{
	int i;
	stack s;
	init(&s);               //Initialization function call
	char a[20];
	printf("Enter an expression in postfix form\n");        //Message prompt
	scanf("%s",a);                          //Takes input of postfix expression
	int result,x,y;
	for(i=0;a[i];i++)               //Loop to access all elements of stack
	{
		if(a[i]<='9' && a[i]>='0')      //Checks for numbers
		{
			push(&s,a[i]-48);               //Push function call
		}
		if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')    //Checks for operators    
		{
			x=pop(&s);                      //Pop function call
			y=pop(&s);                      //Pop function call
			switch(a[i])
			{
				case '+':                       //If '+' then add two operators
					result=y+x;
					break;
				case '-':                       //If '-' then Subtract two operators
					result=y-x;
					break;
				case '*':                       //If '*' then multiply two operators
					result=y*x;
					break;
				case '/':                       //If '/' then divide two operators
					result=y/x;
					break;
			}
			push(&s,result);        //Pushes the result in the stack after one operation
		}
	}
	printf("Result is %d\n",pop(&s));       //prints result
return 0;
}
/*
Enter an expression in postfix form
87+6*
Result is 90
*/
