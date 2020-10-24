/*Ques 24. Design a scheduling program to implements a Queue with two levels:
Level 1 : Fixed priority preemptive Scheduling
Level 2 : Round Robin Scheduling
For a Fixed priority preemptive Scheduling (Queue 1), 
the Priority 0 is highest priority. If one process P1 is scheduled and running,
another process P2 with higher priority comes. The New process (high priority) 
process P2 preempts currently running process P1 and process P1 will go to 
second level queue. Time for which process will strictly execute must be 
considered in the multiples of 2.
All the processes in second level queue will complete their execution according to round
robin scheduling.
Consider: 1. Queue 2 will be processed after Queue 1 becomes empty.
3.	Priority of Queue 2 has lower priority than in Queue 1.
*/

#include<stdio.h> 	//header file for standard input-output
#include<windows.h> //header file for sleep 
int i,nop,bur[20],pr[20],q=4,prior[20];		//where time quanta = 4
int main()
{	
	printf("\nEnter the no of processes you want to perform RR scheduling: ");
	scanf("%d",&nop); 	//total no of processes
	
	for(i=0;i<nop;i++)		//oinput for processes
	{
		pr[i]=i;
	}
		
	for(i=0;i<nop;i++) 				//input for burst time
	{
		printf("\nEnter burst time for Process-ID %d:",i);
		scanf("%d",&bur[i]);
	}
	
	for(i=0;i<nop;i++) 				//input for priority
	{
		printf("\nEnter priority for Process-ID %d:",i);
		scanf("%d",&prior[i]);
	}
////////////////////////////////////////////////////////////////////	
	// RR Scheduling
		for(i=0;i<nop;i++)
	{
		for(int j=1;j<=q;j++)
		{
			printf("\n.......Process %d Running...... ",pr[i]);
			printf("\n.......Process %d Terminated...... ",pr[i]);		
			bur[i]--;
		}
		if(bur[i]==0)
		{
			continue;
		}
		
		Sleep(2000);			//initializing sleep
	}
////////////////////////////////////////////////////////////////////
	//priority Scheduling
	for(i=0;i<nop;i++)
	{
		if(prior[i]>prior[i+1])
		{
			printf("\n.......Process %d Running...... ",pr[i+1]);
			printf("\n.......Process %d Terminated...... ",pr[i]);		
			bur[i+1]--;
		}

		else if(prior[i]<prior[i+1])
		{
			bur[i]=0; 
			printf("\n....Process %d Teriminated...\n",pr[i+1]);
			printf("\n....Process %d Running....\n",pr[i]);
		}
		Sleep(2000);			//initializing sleep
	}
	
	printf("\n\nScheduling Operation Successfully Terminated!!");
	return 0;
}
