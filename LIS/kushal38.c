/*Q38. consider the following set of processes, assumed to have arrived at time 0, in the orderP1, P2, o o o , P5, with the length of the CPU burst given in milliseconds:
Write a C program to schedule the processes using priority scheduling and calculate average waiting time. Consider Lower the number higher the priority.
*/

#include<stdio.h> 	//header file for standard input-output
#include<windows.h> //header file for sleep 
int i,tat[20],wt[20],totalwait,totalturn;
int nop=1;
int avgwt,avgtat;
int pr[20],bur[20],prior[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	Sleep(1000);
	printf("\t\t\tPreemtive Priority Scheduling\t\t\t");
	printf("\nEnter the no of processes you want to perform scheduling: ");
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
	printf("\n.......................................................\n");
//...................printing the table...............................	
	
//............applying conditions of preemptive priority sceduling..........
	
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
		Sleep(1000);			//initializing sleep
	}
	
	printf("\n\nScheduling Operation Successfully Terminated!!");
//....................calculating avg. waiting time and avg. turnaround time............
	//turnaroundtime= completiontime-arrivaltime
	//waitingtime= turnaroundtime-bursttime
	for (i=0;i<nop;i++)  
        wt[i] =  bur[i-1] + prior[i-1] ;  //waiting time
	
	for (i=0;i<nop;i++)  
    	tat[i] = bur[i] + wt[i];  
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
//..................................................................................
	return 0;
} 			//end of main

