/*Ques. 11. Reena's operating system uses an algorithm for deadlock avoidance to manage the allocation of resources say three namely A, B, and C to three processes P0, P1, and P2. Consider the following scenario as reference .user must enter the current state of system as given in this example :
Suppose P0 has 0,0,1 instances , P1 is having 3,2,0 instances and P2 occupies 2,1,1 instances of A,B,C resource respectively.
Also the maximum number of instances required for P0 is 8,4,3 and for p1 is 6,2,0 and finally for P2 there are 3,3,3 instances of resources A,B,C respectively. There are 3 instances of resource A, 2 instances of resource B and 2 instances of resource C available. Write a program to check whether Reena's operating system is in a safe state or not in the following independent requests for additional resources in the
current state:
1.	Request1: P0 requests 0 instances of A and 0 instances of B and 2 instances of C.
2.	Request2: P1 requests for 2 instances of A, 0 instances of B and 0 instances of C.
All the request must be given by user as input.
*/

#include<stdio.h>
//given three processes
//contains the maximum sizes
int maxa[3]={8,4,3};
int maxb[3]={6,2,0};
int maxc[3]={3,3,3};
//avalable
int avail[3]={3,3,2};
//allocation of input
int a[3],b[3],c[3];
int needa[3],needb[3],needc[3];
int i=0;
int flag=0;
int main()
{
	//taking input of allocation
	for(i=0;i<3;i++)
	{
	printf("\nEnter the allocation of process p0:\n");
	scanf("%d",&a[i]);
	}
	for(i=0;i<3;i++)
	{
	printf("\nEnter the allocation of process p1:\n");
	scanf("%d",&b[i]);
	}
	for(i=0;i<3;i++)
	{
	printf("\nEnter the allocation of process p2:\n");
	scanf("%d",&c[i]);
	}
	//generating need 
	for(i=0;i<3;i++)
	{
		//for p0
		needa[i]=maxa[i]-a[i];
		//for p1
		needb[i]=maxb[i]-b[i];
		//for p2
		needc[i]=maxc[i]-c[i];
	}
	//printing need
	for(i=0;i<3;i++)
	{
		printf("\nNeed p0: %d",needa[i]);
		printf("\nNeed p1: %d",needb[i]);
		printf("\nNeed p2: %d",needc[i]);
	}
	//implementing logic
	//checking need < allocation for p0
	
	if(needa[i]<a[i]&&needa[i+1]<a[i+1]&&needa[i+2]<a[i+2])
	{	
		printf("\nP0 running safely!!\n");
		avail[i]=avail[i]+a[i];
		flag=1;
	}
	else
	{
		printf("\ndeadlock");	
		flag=5;
	}
	//checking need < allocation for p0
	if(needb[i]<b[i]&&needb[i+1]<b[i+1]&&needb[i+2]<b[i+2])
	{	
		printf("\nP1 running safely!!\n");
		avail[i]=avail[i]+b[i];
		flag=2;
	}
	else
	{
		printf("\ndeadlock");	
		flag=6;
	}
	//checking need < allocation for p0
	if(needc[i]<c[i]&&needc[i+1]<c[i+1]&&needc[i+2]<c[i+2])
	{	
		printf("\nP2 running safely!!\n");
		avail[i]=avail[i]+c[i];
		flag=3;
	}
	else
	{
		printf("\ndeadlock");	
		flag=7;
	}
	//checking safe state
	if(flag==1&&flag==2&&flag==3)
		printf("\nThe System is in safe state.\n");
	if(flag==5)
		printf("\np0 is in deadlock");
	if(flag==6)
		printf("\np1 is in deadlock");
	if(flag==7)
		printf("\np2 is in deadlock");
	
	
	return 0;		
}

