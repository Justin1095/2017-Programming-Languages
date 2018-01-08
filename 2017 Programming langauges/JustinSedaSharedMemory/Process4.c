//Justin Seda
//Process 4
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>

#define SIZE 27

int main()
{
	int sharedMID;
	key_t key;
	char *sharedM, *s, *a, *b;
	
	key = 4200;

	sharedMID = shmget(key, SIZE, 0666);  //Locates segement
	sharedM = shmat(sharedMID, NULL, 0); //attaches address space
	
	/*Checks for errors*/
	if(sharedMID < 0)
	{
		perror("error in shmget");
		return 1;
	}
	
	if(sharedM ==(char *)-1)
	{
		perror("error in shmat");
		return 1;	
	}
	
	/*Gets the words*/
	s = sharedM;
	for (s; *s !=  0; s++) //Reads memory from process 1
	{
		putchar(*s);	
	}
	putchar(' ');
	
	*sharedM = 'a';	
	while (*sharedM != 'I') //removes last memory 
	{
		sleep(1);
	}	
	
	a = sharedM; 
	for (a ; *a !=  0; a++) //Reads memory from process 2
	{
		putchar(*a);	
	}
	putchar(' ');
	
	*sharedM = 'b';
	while (*sharedM != 'F') //Removes the last memory
	{
		sleep(1);
	} 
		
	b =sharedM;
	for (b; *b !=  0; b++) //Reads memory from process 3
	{
		putchar(*b);	
	}
	putchar('\n');
	*sharedM = '*';
	
	return 0;
}