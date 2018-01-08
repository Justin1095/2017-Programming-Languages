//Justin Seda
//Process 1
//These programs uses shared memory to output "IPC IS FUN!"
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>

#define SIZE 27

int main()
{
	int sharedMID,i;
	key_t key;
	char *sharedM, *s;
	
	key = 4200; 
	
	/*Creates a share memory segements and gives read and write access */
	sharedMID = shmget(key, SIZE, IPC_CREAT | 0666); 
	
	/*Attaches shared memory segments into the address space */
	sharedM = shmat(sharedMID, NULL, 0);
	
	if(sharedMID < 0) //checks if shmget works
	{
		perror("error in shmget");
		return 1;
	}
	
	if(sharedM == (char*)-1) //checks if shmat works
	{
		perror("error in shmat");
		return 1;
	}
	
	/*Indicates that we have read it*/
	while(*sharedM != '*')
	{
		sleep(1);	
	}
	
	/*Puts word into the shared memory*/
	s = sharedM;	
	char word[4] = {'I','P','C', ' '};	
	for(i = 0; i < 4; i++)
	{
		*s++ = (int)word[i];
	}
	*s = 0;
	
	return 0;
}