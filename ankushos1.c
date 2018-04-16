#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
}*head;

void create(int n)
{
	struct node*newnode,*temp;
	int data=0,i;
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to allocate memory");
	}
	else
	{
		head->data=data;
		head->next=NULL;
		temp=head;
		for(i=0;i<n;i++)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			if(newnode==NULL)
			{
				printf("unable to allocate memory");
				break;
			}
			else
			{
				newnode->data=i;
				printf("value: %d\t",newnode->data);
				newnode->next=NULL;
				temp->next=newnode;
				temp=temp->next;
			}
		}
	}
}

void traverse()
{
	int i;
	int n,count=0;
	int pre=125;
	int cur=143;
	struct node*prev;
	struct node*curr;
	struct node*temp;
	temp=head;
	while(temp->data!=pre)
	{
		temp=temp->next;
	}
	prev=temp;
	temp=head;
	while(temp->data!=cur)
	{
		temp=temp->next;
	}
	curr=temp;
	temp=head;
	for(i=0;i<=8;i++)
	{
		printf("enter the next pending request where to move\n");
		scanf("%d",&n);
		while(temp->data!=n)
		{
			temp=temp->next;
		}
		count=count + '|(curr->data)-(temp->data)|';
		printf("now the value of count is:%d\n",count);
		prev=curr;
		curr=temp;
		temp=head;
	}
	printf("\ntotal distance travelled by disk arm to satisfy all pending request is: %d",count);
}

int main()
{
	int n=5000;
	create(n);
	traverse();
	return 0;
}

















