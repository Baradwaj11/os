#include<stdio.h>
int main()c
{
	printf("Enter the number of PROCESS  in the queue:  ");
	int n;
	scanf("%d",&n);
	int ts[n], p[n], arrival_time[n], burst_time[n], completion_time[n], waiting_time[n], turn_around_time[n], i, k, temp;


	float wtavg, tatavg;
	for(i=1; i<n+1;i++)
	{
		p[i] = i;
		printf("Teacher/Student process (0/1) ?: ");
		scanf("%d",&ts[i]);
		printf("Arrival Time of process %d: ", i);
		scanf("%d",&arrival_time[i]);
		printf("Burst Time of process  %d:   ", i);
		scanf("%d",&burst_time[i]);
	}
	
	for(i=1;i<n+1;i++)
	{
		for(k=i+1;k<n+1;k++)
		{
			if((arrival_time[i]==arrival_time[k])&&(ts[i] > ts[k]))
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
					
				temp=arrival_time[i];
				arrival_time[i]=arrival_time[k];
				arrival_time[k]=temp;
				
				temp=burst_time[i];
				burst_time[i]=burst_time[k];
				burst_time[k]=temp;
				
				temp=ts[i];
				ts[i]=ts[k];
				ts[k]=temp;
			}
			else if(arrival_time[i] > arrival_time[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=arrival_time[i];
				arrival_time[i]=arrival_time[k];
				arrival_time[k]=temp;
							
				temp=burst_time[i];
				burst_time[i]=burst_time[k];
				burst_time[k]=temp;
			
				temp=ts[i];
				ts[i]=ts[k];
				ts[k]=temp;			
			}
		}
	}
	completion_time[1] = burst_time[1] + arrival_time[1];
	tatavg = wtavg = waiting_time[1] = 0;
	turn_around_time[1] = completion_time[1];
	for(i=1;i<n+1;i++)
	{
		if(completion_time[i] < arrival_time[i+1]) completion_time[i+1] = burst_time[i+1] + arrival_time[i+1];
		else completion_time[i+1] = completion_time[i] + burst_time[i+1];
		turn_around_time[i] = completion_time[i] - arrival_time[i];
		waiting_time[i] = turn_around_time[i] - burst_time[i];
		wtavg = wtavg + waiting_time[i];
		tatavg = tatavg + turn_around_time[i];
	}
	printf("\nPROCESS\t TEACH/STU PROCESS\t ARRIVAL TIME\t BURST TIME\t COMP_TIME\t TURNAROUND TIME\t WAITING TIME");
	
	for(i=1; i<n+1;i++)
	{
		printf("\n%d \t\t %d \t\t\t %d \t\t %d \t\t %d \t\t %d \t\t %d",p[i],ts[i],arrival_time[i],burst_time[i],completion_time[i],turn_around_time[i],waiting_time[i]);
	}
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);
	printf("\nAverage Waiting Time is --- %f",wtavg/n);

	retureturn 0;
}

