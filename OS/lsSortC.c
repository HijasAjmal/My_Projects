/*
Program		: The equivalant of ls -l | sort -n +4
			sort the output of 'ls -l', on numeric by skipping 4 fields.That is,
			sort based on file size.
			fd[0] - Read
			fd[1] - Write
			The op of 'ls -l', created by child will be redirected (from standard op)
			to fd[1].The parrent process who sort the files in ascending order of 
			size, will read its input from fd[0]. In parent, standard input is 
			redirected to fd[0]. The child will write its op to the pipe and the 
			parent will take its input from the pipe. The new process is forked 
			after the creation of the pipe.
Date		: 07-12-10
LastModify	: 08-12-10
File		: lsSortC.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	pid_t childpid;
	int fd[2];

	system("clear");
	if ( pipe(fd) < 0 ) {
		perror("Pipe creation");
		exit(1);
	}
	childpid=fork();
	if(childpid == 0 ) {
		printf("\nI am child Executing 'ls -l' \n");
		if ( dup2(fd[1],STDOUT_FILENO)< 0 ) {
			perror("Failed Redirection");
			exit(1);
		}
		else
			printf("\nIn child, STDOUT Redirected to pipe write\n");

		close(fd[0]);
		close(fd[1]);

		execl("/bin/ls", "ls", "-l", NULL);
		perror("Failed ls");
	}
	else{
		printf("\nI am parent\n");
		if ( dup2(fd[0],STDIN_FILENO)< 0 ){
			perror("Error redirection");
			exit(1);
		}
		else
			printf("\nIn parent, STDIN Redirected to pipe read\n");

		close(fd[0]);
		close(fd[1]);
		execl("/bin/sort", "sort", "-n", "+4",  NULL);
		perror("Failed sort");
	}
	return 0;

}
/*
[root@mail Pipes]# gcc lsSortC.c  -o lsSortC
[root@mail Pipes]# ./lsSortC

I am child Executing 'ls -l'

I am parent

In parent, STDIN Redirected to pipe write

In child, STDOUT Redirected to pipe write
total 92
-rw-r--r--   1 root     root          507 Dec  8 11:00 lsSortA.c
-rw-r--r--   1 root     root          509 Dec  7 13:50 Apipe.c
-rw-r--r--   1 root     root          524 Dec  7 17:53 Dpipe.c
-rw-r--r--   1 root     root          581 Dec  7 16:17 Readme.txt
-rw-r--r--   1 root     root          757 Dec  7 17:24 Cpipe.c
-rw-r--r--   1 root     root          771 Dec  7 16:51 Bpipe.c
-rw-r--r--   1 root     root          800 Dec  8 11:33 lsSortB.c
-rw-r--r--   1 root     root         1069 Dec  8 10:15 lsSort.c
-rw-r--r--   1 root     root         1509 Dec  8 12:21 lsSortC.c
-rwxr-xr-x   1 root     root         4873 Dec  8 11:00 lsSortA
-rwxr-xr-x   1 root     root         5468 Dec  7 13:50 Apipe
-rwxr-xr-x   1 root     root         5633 Dec  8 11:24 lsSortB
-rwxr-xr-x   1 root     root         5673 Dec  7 14:04 Bpipe
-rwxr-xr-x   1 root     root         5896 Dec  8 10:09 lsSort
-rwxr-xr-x   1 root     root         5923 Dec  7 17:25 Cpipe
-rwxr-xr-x   1 root     root         6039 Dec  8 12:21 lsSortC
[root@mail Pipes]#
*/
