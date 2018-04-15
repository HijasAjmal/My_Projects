#include<sys/types.h>
#include<stdio.h>
pid_t pid;
int main() 
{
	int i;
	for (i=1;i<=3;i++)
	{
		pid=fork();
		if ( pid ==0 )
		{
			printf("\nBy Child, I am %d Created when i=%d Son of %d",getpid(),i,getppid());
		}
		else 
		{
			printf("\nBy Parent %d i:%d Son of %d\n\n",getpid(),i,getppid());
		}
	}
	exit (0);
}
