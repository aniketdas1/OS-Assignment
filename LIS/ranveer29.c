/*Ques 29. Write a C program to create a page table for a program of 5MB.
Consider page size as 2KB. Assign frame numbers randomly in page table. 
(for conceptual clarity refer the textbook)
*/

#include<stdio.h>
#include<math.h>
int main()
{
	//in physical address the page table is stored which is composed of page size and no of pages 
	double ps=pow(20,2);	//2KB
	int i;
	double fn[5]={10,11,12,13,14};
	double x;
	for(i=0;i<5;i++)
	{	
		x=pow(fn[i],2);
		printf("Page Table %d = %f ----- %f",i+1,x,ps);				
		printf("\n");
	}
	
	return 0;
}
