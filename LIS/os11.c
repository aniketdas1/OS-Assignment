/*Ques. 41. Write a program which incorporate Peterson's solution for synchronizing two processes 
those are simultaneously trying to write on a shared file named as File.txt. 
*/

#include<stdio.h>
#include<pthread.h>
void *f1(void *);
void *f2(void *);
int flag[2]; 	
FILE*fptr;
int turn=0;
int i=0;
int main()
{
	/*turn indicates whose turn it is to enter the crtical ssection
	Flag array is used to indicate if a process is ready to enter the critical 
	section*/
	pthread_t t1; 	//thread of process 1
	pthread_t t2; 	//thread of process 2
	pthread_create(&t1,NULL,f1,NULL);	//thread 1 creation
	pthread_create(&t2,NULL,f2,NULL);	//thread 2 creation
	pthread_join(t1,NULL);	//joining thread 1
	pthread_join(t2,NULL);	//joining thread 2
	return 0;
}

void *f1(void *p) 	//process 1 active function
{
    while(i<2)		
    {
        flag[0]=1;	//active process p1 state
        turn=1;		//turn of process p1
        while(flag[1]==1 && turn==1);
		writefile1();	//process p1 falls into critical state 
        flag[0]=0;	//exits the process state
        i++;
    }
}

void *f2(void *p) 	//process 1 active function
{
    while(i<2)		
    {
        flag[1]=1;	//active process p2 state
        turn=0;		//turn of process p2
        while(flag[0]==1 && turn==0);
        writefile2();	//process p2 falls into critical state 
        flag[1]=0;	//exits the process state
        i++;
    }
}


int writefile1() 		//function of writing to a file 
{
	fptr=fopen("FILE.txt","w");
	//writing in file
	if(fptr==NULL)
	{
		printf("FILE DOES'NT EXISTS.");
	}
	else
	{
		printf("Writing");
		fprintf(fptr,"Common File Write by process P1");
		fprintf(fptr,"\nFile Writing Complete");
	}
	
	fclose(fptr);
	return 0;
}

int writefile2() 		//function of writing to a file 
{
	fptr=fopen("FILE.txt","w");
	//writing in file
	if(fptr==NULL)
	{
		printf("FILE DOES'NT EXISTS.");
	}
	else
	{
		printf("Writing");
		fprintf(fptr,"Common File Write by process P2");
		fprintf(fptr,"\nFile Writing Complete");
	}
	
	fclose(fptr);
	return 0;
}


