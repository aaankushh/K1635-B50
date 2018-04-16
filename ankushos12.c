#include<stdio.h>

struct p
{
	char name;
	int at,bt,ct,wt,turn_t,priority;
	int status;
	
}p_queue[10];

int limit;
void at_sorting()
{
	struct p temp;
	int i,j;
	for(i=0;i<limit-1;i++)
	{
		for(j=0;j<limit;j++)
		{
			if(p_queue[i].at>p_queue[j].at)
			{
				temp=p_queue[i];
				p_queue[i]=p_queue[j];
				p_queue[j]=temp;
			}
		}
	}
}
int main()
{
	int i,time=0,bt=0,largest;
	char c;
	float wt=0,turn_t=0;
	printf("\n\n ENTER TOTAL NUMBER OF PROCESSES\n");
	scanf("%d",&limit);
	for(i=0,c='A';i<limit;i++,j++)
	{
		p_queue[i].name=c;
		printf("\nENTER DETAILS FOR PROCESS[%c]:\n",p_queue[i].name);
		printf("ENTER ARRIVAL TIME:\t");
		scanf("%d",&p_queue[i].at);
		printf("ENTER BURST TIME:\t");
		scanf("%d",&p_queue[i].bt);
		printf("ENTER PRIORITY:\t");
		scanf("%d",&p_queue[i].priority);
		p_queue[i].status=0;
		bt=bt + p_queue[i].bt;
		
	}
	at_sorting();
	p_queue[9].priority=-9999;
	printf("\n NAME\t ARRIVAL TIME\t BURST TIME\t PRIORITY\t WAITING TIME");
	for(time=p_queue[0].at;time<bt;)
	{
		largest=9;
		for(i=0;i<limit;i++)
		{
			if(p_queue[i].at<=time && p_queue[i].status!=1 &&p_queue[i].priority>p_queue[largest].priority);
			{
				largest=i;
			}
		}
		time=time+p_queue[largest].bt;
		p_queue[largest].ct=time;
		p_queue[largest].wt=p_queue[largest].ct-p_queue[largest].at-p_queue[largest].bt;
		p_queue[largest].turn_t=p_queue[largest].ct-p_queue[largest].at;
		p_queue[largest].status=1;
		wt=wt+p_queue[largest].wt;
		turn_t=turn_t+p_queue[largest].turn_t;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",p_queue[largest].name,p_queue[largest].at,p_queue[largest].bt,p_queue[largest].priority,p_queue[largest].wt);
		
	}
	
}









