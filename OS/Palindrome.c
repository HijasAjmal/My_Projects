#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>
int main(){
	int id,fd1[2],fd2[2],i;
	char string1[50],string2[50];
	int length1;
	pipe(fd1);
	pipe(fd2);
	int flag=0,flag1=0;
	id=fork();
	if(id!=0)
	{
		printf("enter the string:: \n");
		gets(string1);
		close(fd1[0]);
		write(fd1[1],&string1,sizeof(string1));
		close(fd2[1]);
		read(fd2[0],&flag1,sizeof(flag1));

		if(flag1 == 0)
			printf("the given string is palindrome");
		else
			printf("the given string is not palindrome");
	}
	else{
		close(fd1[1]);
		read(fd1[0],&string2,sizeof(string2));
		length1 = strlen(string2);
		length1--;
		printf("%d\n",length1);
		for(i =0;i<length1;i++){
			if(string2[i] != string2[length1]){
				flag = 1;
				break;
			}
			length1--;
		}
		printf("reciever: recieved msg is ::%s\n",string2);
		close(fd2[0]);
		write(fd2[1],&flag,sizeof(flag));
	}
}
