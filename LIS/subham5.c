/*Ques. 5. CPU schedules N processes which arrive at different time intervals and each process is allocated the CPU for a specific user input time unit, processes are scheduled using a preemptive round robin scheduling algorithm. 
Each process must be assigned a numerical priority, with a higher number indicating a higher relative priority.
In addition to the processes one task has priority 0. 
The length of a time quantum is T units, where T is the custom time considered as time quantum for processing. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.
Design a scheduler so that the task with priority 0 does not starve for resources and gets the CPU at some time unit to execute. 
Also compute waiting time, turn around.
*/

#include<stdio.h>
#include<windows.h>
int i,totalwait,totalturn;
int nop=1;
int avgwt,avgtat;
int pr[20],order[20],burst[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	printf("\t\t\tRound Robin Scheduling\t\t\t");
	printf("\nEnter the no of processes you want to perform scheduling: ");
	scanf("%d",&nop); 	//total no of processes
	
	for(i=0;i<nop;i++)		//input for processes
	{
		pr[i]=i;
	}
	
	for(i=0;i<nop;i++) 				//input for arrival time
	{
		printf("\nOrder for Process-ID %d:",i+1);
		scanf("%d",&order[i]);
	}
	
	for(i=0;i<nop;i++) 				//input for burst time
	{
		printf("\nEnter burst time quantum for Process-ID %d:",i+1);
		scanf("%d",&burst[i]);
	}
/////////////////////implementing RRS/////////////////////////

	for(i=0;i<nop;i++)
	{
		
		if(order[i]<order[i+1])
		{
			printf("\n\nProcess %d running for time quantum %d:\n",i+1,burst[i]);
			while(i<burst[i])
				{
					printf("Time Quantum %d\n",i+1);
					i++;
				}
		}
		else if(order[i+1]<order[i])
		{
			printf("\n\nProcess %d running for time quantum %d:\n",i,burst[i+1]);
			while(i<burst[i+1)
				{
					printf("Time Quantum %d\n",i+1);
					i++;
				}
		}
	}
	for (i=0;i<nop;i++)  
        order[i] =  burst[i-1] + order[i-1] ;  //waiting time
	
	for (i=0;i<nop;i++)  
    	order[i] = burst[i] + order[i];  
    for(i=0;i<nop;i++)
    {
		totalwait = totalwait + order[i];  
	    totalturn = totalturn + burst[i];  
	}
	avgwt=(float)totalwait / (float)nop; 
    avgtat=(float)totalturn / (float)nop; 
    printf("\nTotal waiting time = %d",totalwait); 
    printf("\nTotal turnaround time = %d",totalturn); 
	printf("\nAverage waiting time = %d",avgwt); 
    printf("\n"); 
    printf("\nAverage turn around time = %d ",avgtat); 

	
	return 0;
}
