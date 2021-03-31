#include <stdio.h>
#include <stdlib.h>
void insert_at_beginning();
void insert_at_end();
void insert_After(int,int);
void delete_from_beginning();
void delete_from_end();
void delete_after(int);
void display();
void search();
struct node
{
    struct node *prev;
    struct node *next;

    int data;
}*head=NULL;
int main()
{
	int ch,opt,value,pos;
	setbuf(stdout,NULL);
	while(1)
	{
		printf("choose your option from following \n1.Insertion\n2.deletion\n3.search\n4.Display\n5.Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("choose an insert option \n1.At beginning\n2.At end\n3.After a specific node\n4.exit");
				scanf("%d",&opt);
					switch(opt)
					{
						case 1:
							insert_at_beginning();
							break;
						case 2:
							insert_at_end();
						break;
						case 3:
							printf("enter the position after which you want to insert\n");
							scanf("%d",&pos);
							insert_After(value,pos);
							break;
						case 4:exit(0);
						break;
						default:
							printf("enter a valid choice\n");
					}

				break;
			case 2:
				printf("choose a delete option \n1.At beginning\n2.At end\n3.After a specific node\n4.exit");
				scanf("%d",&opt);
					switch(opt)
					{
						case 1:
							delete_from_beginning();
							break;
						case 2:
							 delete_from_end();
							break;
						case 3:
							printf("enter the value after which you want to delete\n");
							scanf("%d",&value);
							delete_after(value);
							break;
						case 4:exit(0);
						break;
						default:
							printf("enter a valid choice\n");

					}
			break;
			case 3:
				search();
			break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
				default:
				printf("enter a valid choice\n");

		}
	}

}
void insert_at_beginning()
{
	struct node *new;
	int value;
	new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value to be insert");
    scanf("%d",&value);
    if(head==NULL)
    {
    	new->next = NULL;
    	new->prev=NULL;
    	new->data=value;
    	head=new;
    }
    else
    {
    	new->data=value;
    	new->prev=NULL;
    	new->next = head;
    	head=new;
    }
    printf("\nNode inserted successfully\n");
}
void insert_at_end()
{
	struct node *new;
	int value;
	new = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter value to be inserted");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    if(head == NULL)
    {
    	new->prev = NULL;
        head = new;
    }
    else
    {
    	struct node*temp;
        temp = head;
        while(temp->next!=NULL)
        {
        	temp = temp->next;
        }
        temp->next = new;
        new ->prev=temp;
    }
    printf("\n node inserted successfully\n");
}
void insert_After(int value,int pos)
{
	printf("\nEnter value to be inserted");
	scanf("%d",&value);
   struct node *new;
   new=(struct node*)malloc(sizeof(struct node));
   new->data=value;
   if(head==NULL)
   {
      new->prev=new->next=NULL;
      head=new;
   }
   else
   {
      struct node *temp1=head,*temp2;
      while(temp1->data!=pos)
      {
         if(temp1->next==NULL)
         {
            printf("Given node is not found in the list!!!");
         }
         else
         {
            temp1=temp1->next;
         }
      }
      temp2=temp1->next;
      temp1->next=new;
      new->prev=temp1;
      new->next=temp2;
      temp2->prev=new;
      printf("\nInsertion success!!!");
   }
}
void delete_from_beginning()
{
    if(head == NULL)
    {
        printf("\n list is empty nothing to delete");
    }
    else
    {
    	struct node *temp=head;
    	if(temp->prev==temp->next)
    	{
        head = NULL;
        free(temp);
    	}
    	else
    	{
    		head=temp->next;
    		head->prev=NULL;
    		free(temp);
    	}
        printf("\n Node deleted successfully\n");
    }
}
void delete_from_end()
{
	if(head==NULL)
	{
		printf("list is empty nothing to delete");

	}
	else
	{
		struct node*temp=head;
		if(temp->prev==temp->next)
		{
		    head = NULL;
		     free(temp);
		 }
		else
		{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->prev->next=NULL;
			free(temp);
		}
		printf("\n Node deleted successfully\n");
	}
}
void delete_after(int value)
{
   if(head==NULL)
   printf("list is empty nothing to delete");
   else
   {
      struct node *temp=head;
      while(temp->data!=value)
      {
         if(temp->next==NULL)
         {
            printf("\n given node not found");
         }
         else
         {
            temp=temp->next;
         }
      }
      if(temp==head)
      {
         head = NULL;
         free(temp);
      }
      else
      {
         temp->prev->next=temp->next;
         free(temp);
      }
      printf("\n node deleted successfully\n");
   }
}
void display()
{
    struct node *temp;
    printf("\n the elements in the node are...\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void search()
{
    struct node *temp;
    int item,i=0,flag;
    temp = head;
    if(temp == NULL)
    {
       printf("\n List is empty nothing to delete\n");
    }
    else
    {
       printf("\nEnter item which you want to search?\n");
       scanf("%d",&item);
       while (temp!=NULL)
       {
           if(temp->data == item)
           {
                printf("\n item found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
             }
             i++;
             temp = temp -> next;
          }
          if(flag==1)
          {
              printf("\n Item not found in the list \n");
          }
      }
}


