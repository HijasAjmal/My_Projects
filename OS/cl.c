/*
 * shm-client - client program to demonstrate shared memory.

	Reference : https://users.cs.cf.ac.uk/Dave.Marshall/C/node27.html
Date :14-12-16
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>

#define SHMSZ     27

main()
{
    int shmid,i;
    key_t key;
    char ch,*shm, *s[1000];

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 5678;

    /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     * Now read what the server put in the memory.
     */
    
       printf("\n=>	Enter the elements to sort::");
	while(1)
	{
		ch = getchar();
		if(ch == '\n')
		{
			break;
		}
		else
		{
			for(i = 0;i<1000;i++)
			{
				s[i] = ch;
			}
		}
	}
    /*
     * Finally, change the first character of the 
     * segment to '*', indicating we have read 
     * the segment.
     */
    *shm = '*';

    exit(0);
}
