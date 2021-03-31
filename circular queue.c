#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int cqueue[MAX];
int front = -1;
int rear = -1;
void insert(int item)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("Queue Overflow n");
		return;
	}
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1)
			rear = 0;
		else
			rear = rear+1;
	}
	cqueue[rear] = item ;
}
void delete()
{
	if(front == -1)
	{
		printf("Queue Underflow n");
		return ;
	}
	printf("Element deleted from queue is : %d",cqueue[front]);
	if(front == rear)
	{
		front = -1;
		rear=-1;
	}
	else
	{
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
	}
}
void display()
{
	int front_pos = front,rear_pos = rear;
	if(front == -1)
	{
		printf("Queue is empty");
		return;
	}
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",cqueue[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue[front_pos]);
			front_pos++;
		}
	}
	printf("n");
}
int search()
{
	int item,i,c=0;
	printf("enter the element want to be searched");
	scanf("%d",&item);
	for(i=front;i<=rear;i++)
	{
		if(item==cqueue[i])
		{
			printf("item found at location %d",i+1);
			c++;
		}
	}
	if(c==0)
	{
	printf("item not found");
	}
	return(0);
}
int main()
{
	int choice,item;
	setbuf(stdout,NULL);
	do
	{
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.search\n");
		printf("5.Quit");
		printf("\nEnter your choice : \n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 :
			printf("Input the element for insertion in queue : ");
			scanf("%d", &item);
			insert(item);
			break;
		case 2 :
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			search();
			break;
		case 5:
			exit(0);
		default:
			printf("Wrong choice");
		}
	}
	while(choice!=4);
	return 0;
}