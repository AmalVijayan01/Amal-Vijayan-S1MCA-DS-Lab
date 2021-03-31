#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch,l1,i,s1[10],l2,s2[10],s3[30];
	setbuf(stdout,NULL);
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("\n1.Union\n2.Intersection\n3.Difference\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the limit of set 1\n");
				scanf("%d",&l1);
				printf("Enter the elements of the set 1\n");
				for(i=0;i<l1;i++)
				{
					scanf("%d",&s1[i]);
				}
				printf("Enter the limit of set 2\n");
				scanf("%d",&l2);
				printf("Enter the elements of set 2\n");
				for(i=0;i<l2;i++)
				{
					scanf("%d",&s2[i]);
				}
				if(l1==l2)
				{
					for(i=0;i<l2;i++)
					{
						s3[i]=s1[i]||s2[i];
					}
					for(i=0;i<l2;i++)
					{
						printf("%d",s3[i]);
					}
				}
				else
				{
					printf("The size of the set are not equal\n");
				}
				break;
			case 2:
				printf("Enter the limit of set 1\n");
				scanf("%d",&l1);
				printf("Enter the elements of the set 1\n");
				for(i=0;i<l1;i++)
				{
					scanf("%d",&s1[i]);
				}
				printf("Enter the limit of set 2\n");
				scanf("%d",&l2);
				printf("Enter the elements of set 2\n");
				for(i=0;i<l2;i++)
				{
					scanf("%d",&s2[i]);
				}
				if(l1==l2)
				{
					for(i=0;i<l2;i++)
					{
						s3[i]=s1[i]&&s2[i];
					}
					for(i=0;i<l2;i++)
					{
						printf("%d",s3[i]);
					}
				}
				else
				{
					printf("The size of the set are not equal\n");
				}
				break;
			case 3:
				printf("Enter the limit of set 1\n");
				scanf("%d",&l1);
				printf("Enter the elements of the set 1\n");
				for(i=0;i<l1;i++)
				{
					scanf("%d",&s1[i]);
				}
				printf("Enter the limit of set 2\n");
				scanf("%d",&l2);
				printf("Enter the elements of set 2\n");
				for(i=0;i<l2;i++)
				{
					scanf("%d",&s2[i]);
				}
				if(l1==l2)
				{
					for(i=0;i<l2;i++)
					{
						s3[i]=s1[i]&&!s2[i];
					}
					for(i=0;i<l2;i++)
					{
						printf("%d",s3[i]);
					}
				}
				else
				{
					printf("The size of the set are not equal\n");
				}
				break;
			case 4:exit(0);
			default:
				printf("\n Invalid choice");
		}
	}
	return 0;
}
