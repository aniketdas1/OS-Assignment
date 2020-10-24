/*Q31. Write a C program to solve the following problem:
Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder143, and the previous request was at cylinder 125. The queue of pending requests, in FIFO order is:
86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130
Starting from the current head position, what is the total distance (in cylinders)that the disk arm moves to satisfy all the pending requests for each of the SSTF disk-scheduling algorithms? (for conceptual clarity refer the textbook)
*/

#include<stdio.h>
#include<windows.h>
int cydrive[5000];
int que[9]={86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
int ar[9]={143,144,145,146,147,148,149,150,151};
int sum=0;
int i=0;
int main()
{
	printf("Processing from cylinder 143 value :\n");
	for(i=0;i<9;i++)
	{
		cydrive[ar[i]]=que[i];
		sum=sum+que[i];
		printf("Processing %d : %d",ar[i],que[i]);
		printf("\n");
		sleep(1);
	}
	printf("\nDistance - %d",sum);
	return 0;
}
