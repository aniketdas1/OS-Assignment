/*Ques. 14. Write a program to implement priority scheduling algorithm with context switching time. 
Prompt to user to enter the number of processes and then enter their priority, burst time and 
arrival time also. Now whenever operating system preempts a process and shifts cpu’s control 
to some another process of higher priority assume that it takes 2 
seconds for context switching(dispatcher latency).Form a scenario, 
where we can give the processes are assigned with priority 
where the lower integer number is higher priority and then context switch .. 
as the process waits the priority of the process increase at rate of 
one per 2 time units of wait.
Calculate waiting time and turnaround time for each process.
*/

//......................................................................................................................
#include<stdio.h> 	//header file for standard input-output
#include<windows.h> //header file for sleep 
int i,temp,wt[20],tat[20],totalwait,totalturn,avgwt,avgtat;
int np=1;
int pr[20],ar[20],bur[20],prior[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	Sleep(1000);
	printf("\t\t\tPreemtive Priority Scheduling\t\t\t");
	printf("\nEnter the no of processes you want to perform scheduling: ");
scanf("%d",&np); 	//total no of processes
	
	for(i=0;i<np;i++)		//input for processes
	{
		pr[i]=i;
	}
	
	for(i=0;i<np;i++) 				//input for arrival time
	{
		printf("\nEnter arrival time for Process-ID %d:",i);
		scanf("%d",&ar[i]);
	}
	
	for(i=0;i<np;i++) 				//input for burst time
	{
		printf("\nEnter burst time for Process-ID %d:",i);
		scanf("%d",&bur[i]);
	}
	
	for(i=0;i<np;i++) 				//input for priority
	{
		printf("\nEnter priority for Process-ID %d:",i);
		scanf("%d",&prior[i]);
	}
	printf("\n.......................................................\n");
//...................printing the table...............................	
	
//............applying conditions of preemptive priority sceduling..........
	
	for(i=0;i<np;i++)
	{
		if(ar[i]<ar[i+1])
		{
			printf("\n.......Process %d Running........",pr[i+1]);
			bur[i]--;
		}
		Sleep(1000);			//initializing sleep
		if(prior[i+1]>prior[i+2]&&pr[i+2]!=0)
		{
			printf("\n.......Process %d Running...... ",pr[i+2]);
			bur[i+1]--;
		}
		Sleep(1000);			//initializing sleep
		if(prior[i+1]<prior[i+2])
		{
			bur[i]=0; 
			printf("\n....Process %d Terminated....\n",pr[i]);
		}
		Sleep(1000);			//initializing sleep
		temp=i+1;
	}
	
	printf("\n.......Process %d Running...... ",(temp));
	Sleep(1000);			//initializing sleep
	bur[temp]=0; 
	printf("\n....Process %d Terminated....\n",(temp));
	Sleep(1000);			//initializing sleep
	
	printf("\n\nScheduling Operation Successfully Terminated!!");
//....................calculating avg. waiting time and avg. turnaround time............
	//turnaroundtime= completiontime-arrivaltime
	//waitingtime= turnaroundtime-bursttime
	for (i=0;i<np;i++)  
        wt[i] =  bur[i-1] + wt[i-1] ;  //waiting time
	
	for (i=0;i<np;i++)  
    	tat[i] = bur[i] + wt[i];  
    for(i=0;i<np;i++)
    {
		totalwait = totalwait + wt[i];  
	    totalturn = totalturn + tat[i];  
	}
	avgwt=(float)totalwait / (float)np; 
    avgtat=(float)totalturn / (float)np; 
    printf("\nTotal waiting time = %d",totalwait); 
    printf("\nTotal turnaround time = %d",totalturn); 
	printf("\nAverage waiting time = %d",avgwt); 
    printf("\n"); 
    printf("\nAverage turn around time = %d ",avgtat); 

//..................................................................................
	
	return 0;

} 			//end of main
	
//..................................................................................................................................

	
	
		
	
		
	
