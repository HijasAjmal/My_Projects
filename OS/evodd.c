#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>
int main(){
	int id,fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);
	int input_number,flag=0,flag1,input_number1;
	id=fork();
	if(id!=0)
	{
		printf("enter the number:: \n");
		scanf("%d",&input_number);
		close(fd1[0]);
		write(fd1[1],&input_number,sizeof(input_number));
		close(fd2[1]);
		read(fd2[0],&flag1,sizeof(flag1));
		if(flag1 == 0)
			printf("the given number is even");
		else
			printf("the given number is odd");
	}
	else{
		close(fd1[1]);
		read(fd1[0],&input_number1,sizeof(input_number1));
		if(input_number1%2 != 0)
			flag = 1;
		printf("reciever: recieved msg is ::%d\n",input_number1);
		close(fd2[0]);
		write(fd2[1],&flag,sizeof(flag));
	}
}
