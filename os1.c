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
int i,temp,wt,tat,maxwt,maxtat;
int np=1;
int pr[20],ar[20],bur[20],prior[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	Sleep(1000);
	printf("\t\t\tPreemtive Priority Scheduling\t\t\t");
	printf("\nEnter the no of processes you want to perform scheduling: ");
scanf("%d",&np); 	//total no of processes
	
	for(i=1;i<=np;i++)		//input for processes
	{
		pr[i]=i;
	}
	
	for(i=1;i<=np;i++) 				//input for arrival time
	{
		printf("\nEnter arrival time for Process-ID %d:",i);
		scanf("%d",&ar[i]);
	}
	
	for(i=1;i<=np;i++) 				//input for burst time
	{
		printf("\nEnter burst time for Process-ID %d:",i);
		scanf("%d",&bur[i]);
	}
	
	for(i=1;i<=np;i++) 				//input for priority
	{
		printf("\nEnter priority for Process-ID %d:",i);
		scanf("%d",&prior[i]);
	}
	printf("\n.......................................................\n");
//...................printing the table...............................	
	
//............applying conditions of preemptive priority sceduling..........
	
	for(i=1;i<=np;i++)
	{
		if(ar[i]<ar[i+1])
		{
			printf("\n.......Process %d Running........",pr[i]);
			bur[i]--;
		}
		Sleep(1000);			//initializing sleep
		if(prior[i]>prior[i+1]&&pr[i+1]!=0)
		{
			printf("\n.......Process %d Running...... ",pr[i+1]);
			bur[i+1]--;
		}
		Sleep(1000);			//initializing sleep
		if(prior[i]<prior[i+1])
		{
			bur[i]=0; 
			printf("\n....Process %d Terminated....\n",pr[i]);
		}
		Sleep(1000);			//initializing sleep
		temp=i;
	}
	
	printf("\n.......Process %d Running...... ",(temp));
	Sleep(1000);			//initializing sleep
	bur[temp]=0; 
	printf("\n....Process %d Terminated....\n",(temp));
	Sleep(1000);			//initializing sleep
	
	printf("\n\nScheduling Operation Successfully Terminated!!");
//....................calculating avg. waiting time and avg. turnaround time............
	for(i=1;i<=np;i++)
	{
		wt=bur[i]-ar[i];
		tat=wt[i]+bur[i];
	}
	
	avgtat=tat/np;			
	avgwt=wt/np;
	prinf("\nResults:")
	printf("\nAverage Turn Around Time: %d",avgtat);
	printf("\nAverage Waiting Time: %d",avgwt);
//..................................................................................
	return 0;
} 			//end of main
	
//..................................................................................................................................

	
	
		
	
		
	
