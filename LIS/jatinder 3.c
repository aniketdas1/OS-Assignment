/*Ques. 3. Consider a scheduler which schedules the job by considering the arrival time of the processes where arrival time if given as 0 is discarded or displayed as error. The scheduler implements the shortest job first scheduling policy, but checks the queue of the processes after the every process terminates and time taken for checking and arranging the process according to the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting time and turnaround time of the processes. Also compute the total time taken by the processor to compute all the jobs.

The inputs for the number of requirements, arrival time and burst time should be provided by the user.

Consider the following units for reference.
Process    Arrival time    Burst Time
1   		 0   		 6
2    		3   		 2
3    		5   		 1
4    		9   		 7
5    		10   		 5
6    		12    		3
7   		 14   		 4
8    		16    		5
9    		17    		7
10    		19    		2
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
	printf("\t\t\tShortest Job First\t\t\t");
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
		sleep(2);
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
