//Justin Seda
//Process 3
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>

#define SIZE 27

int main()
{
	int sharedMID, i;
	key_t key;
	char *sharedM, *s;
	
	key = 4200;
	
	sharedMID = shmget(key, SIZE,IPC_CREAT | 0666);
	sharedM = shmat(sharedMID, NULL, 0);
	
	if(sharedMID < 0)
	{
		perror("error in shmget");
		return 1;
	}
	
	if(sharedM == (char*)-1)
	{
		perror("error in shmat");
		return 1;
	}
	
	while(*sharedM != 'b')
	{
		sleep(1);	
	}
	
	s = sharedM;	
	char word[4] = {'F','U','N','!'};	
	for(i = 0; i < 4; i++)
	{
		*s++ = (int)word[i];
	}
	*s = 0;
		
	*sharedM = 'F';
	
	return 0;
}