/* Ques. 2. Considering the arrival time and burst time requirement of 
the process the scheduler schedules the processes 
by interrupting the processor after every 6 units of time 
and does consider the completion of the process in this iteration. 
The scheduler than checks for the number of process waiting for the processor 
and allots the processor to the process but interrupting the processor every 
10 unit of time and considers the completion of the processes in this 
iteration. The scheduler checks the number of processes waiting in the queue 
for the processor after the second iteration and gives the processor to the 
process which needs more time to complete than the other processes to go in 
the terminated state.
The inputs for the number of requirements, arrival time and burst time should be provided by the user.
Consider the following units for reference.
Process    Arrival time    Burst time
P1   		 0    		20
P2   		 5    		36
P3    		13    		19
P4    		26    		42
Develop a scheduler which submits the processes to the processor in the defined scenario, and compute the scheduler performance by providing the waiting time for process, turnaround time for process and average waiting time and turnaround time.
*/

#include<stdio.h>
#include<windows.h>
int i,wt[20],tat[20],totalwait,totalturn;
int nop=1;
int avgwt,avgtat;
int pr[20],arrival[20],burst[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	printf("\nEnter the no of processes you want to perform scheduling: ");
	scanf("%d",&nop); 	//total no of processes
	
	for(i=0;i<nop;i++)		//input for processes
	{
		pr[i]=i;
	}
	
	for(i=0;i<nop;i++) 				//input for arrival time
	{
		printf("\nEnter arrival time for Process-ID %d:",i+1);
		scanf("%d",&arrival[i]);
	}
	
	for(i=0;i<nop;i++) 				//input for burst time
	{
		printf("\nEnter burst time for Process-ID %d:",i+1);
		scanf("%d",&burst[i]);
	}
//.............implementing operational logic................................
	for(i=0;i<nop;i++)
	{
		if(arrival[i]==0)
		{
			printf("Error!!");	
			break;
		}
		if(burst[i]<burst[i+1])
		{
			printf("\n\nProcess %d running\n",i+1);
		}
		else if(burst[i+1]<burst[i])
		{
			printf("\n\nProcess %d running\n",i+1);
		}
		sleep(6);
	}
//....................calculating avg. waiting time and avg. turnaround time............
	//turnaroundtime= completiontime-arrivaltime
	//waitingtime= turnaroundtime-bursttime
	for (i=0;i<nop;i++)  
        wt[i] =  burst[i-1] + wt[i-1] ;  //waiting time
	
	for (i=0;i<nop;i++)  
    	tat[i] = burst[i] + wt[i];  
    for(i=0;i<nop;i++)
    {
		totalwait = totalwait + wt[i];  
	    totalturn = totalturn + tat[i];  
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
