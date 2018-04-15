/*	Program	: Banker's Algorithm 
	File	: E-banker.c
	Status	: Working in a loop to accept  requests
	Date	: 11/10/10

*/


#include <stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

int available[10], max_claim[10][10],allocation[10][10];
int total[10],need[10][10],request[10];

int n; // Processes
int m; //Type of resources

void print2DArray(int a[10][10],int r, int c) {
	int i,j;

	for(i=1; i<=r; i++) {
		for(j=1; j<=c; j++) {
			printf("  %d",a[i][j]);
		}
		printf("\n");
	}
}
void printArray(int a[10],int c) {
	int i;
	for(i=1; i<=c; i++) {
		printf("  %d",a[i]);
	}
}

int isClaimGtTotal(int process, int resType) {
	if( max_claim[process][resType] > total[resType] ) return TRUE;
	else return FALSE;
}
int isAllocGtClaim(int process, int resType) {
	if(allocation[process][resType]>max_claim[process][resType]) return TRUE;
	else return FALSE;
	
}

int safety() {

	int work[10],finish[10],safe[10];
	int c=1,i,j,flag,k;

	for(j=1;j<=m;j++) {
		work[j]=available[j];
	}	
	for(i=1; i<=n; i++) {
		finish[i]=FALSE;
	}
	for(k=1;k<=n;k++) {
		flag=FALSE;
		for(i=1; i<=n; i++){
			if( finish[i] == FALSE) {
				flag=TRUE;
				for(j=1; j<=m; j++) {
					if(need[i][j]>work[j]) flag=FALSE;
				}
				if(flag==TRUE) {
					finish[i]=TRUE;
					for(j=1; j<=m; j++) {
						work[j]=work[j]+allocation[i][j];
					}
					safe[c++]=i;					
				}
			}
		}
	}
	for(i=1; i<=n; i++) {
		if(finish[i]==FALSE) return FALSE;
	}
	printf("\n----------- Safe sequence --------\n" );
	for(i=1; i<c; i++) {
		printf("P%d\t",safe[i]);
	}
	return TRUE;
}

int processRequest(int p) {
	//char answer[30];
	int i;
	for(i=1;i<=m;i++) {
		if(request[i] > need[p][i]) return ERROR;
	}
	for(i=1;i<m;i++) {
		if(request[i]>available[i]) return FALSE;
	}
	
	for(i=1; i<=m; i++) {
		available[i]=available[i]-request[i];
		allocation[p][i]=allocation[p][i]+request[i];
		need[p][i]=need[p][i]-request[i];		
	}
	return TRUE;
}

void restore(int p) {
	int i;
	
	for(i=1; i<=m; i++){
		available[i]=available[i]+request[i];
		allocation[p][i]=allocation[p][i]-request[i];
		need[p][i]=need[p][i]+request[i];
	}
}

void calculateAvailable() {
	int i,j;
	for(i=1; i<=m; i++){
		available[i]=total[i];
	}
	for(i=1; i<=m; i++) { //Resources
		for(j=1; j<=n; j++) { //Processes
			available[i]=available[i]-allocation[j][i];
			if ( available[i] < 0 ) {
				printf("\nWrong allocation state: Allocation > Total for Resourcr Type %d\n",i);
				exit(1);
			}
		}
	}
}

void calculateNeed() {  //Need of each process
	int i,j;
	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++) {
			need[i][j]=max_claim[i][j]-allocation[i][j];
		}
	}
	
}
void printAvailability() {
	printf("\n -------Availability of resource types-----\n");
	printArray(available,m);

}
void printNeed() {
	printf("\n\n-------Need of each process ---------\n");
	calculateNeed();
	print2DArray(need,n,m);

}

int main(){

	int flag,i,j,p;
	char cont='Y';
	char newline;

	system("clear");
	printf("\nHowmany Processes ?:");
	scanf("%d",&n);
	printf("Number of resource types ?:");
	scanf("%d",&m);
	
	printf("\nEnter count of each resource type");
	for(i=1; i<=m; i++){
		printf("\nType %d:",i);
		scanf("%d",&total[i]);
	}
	printf("\n Number of resource types\n");
	printArray(total,m);
	
	printf("\nEnter claims of each process (Input as 1 x %d Array, Values Separated by space)\n",m);
	for(i=1; i<=n; i++){
		printf("\nPocess %d :",i);
		for(j=1; j<=m; j++){
			scanf("%d",&max_claim[i][j]);
			if (  isClaimGtTotal(i,j) ) {
				printf("\nDemand of process P%d is greater than total number of resource type %d\n",i,j);
				exit(0);
			}
		}
	}
	printf("\nDemands of each process\n"); 
	print2DArray(max_claim,n,m);

		
	printf("\n\nEnter current allocation state (Input as 1 x %d array, values separated by space\n",m);
	for(i=1; i<=n; i++) {
		printf("\nPocess %d :",i);
		for(j=1; j<=m; j++) {
			scanf("%d",&allocation[i][j]);
			if (  isAllocGtClaim(i,j) ) {
				printf("\n!!!! For process P%d Allocation of resource type %d is greater than claim \n",i,j);
			exit(0);
			}
		}
	}
	printf("\nCurrent allocation state\n");	
	print2DArray(allocation,n,m);
	
	calculateAvailable();
	printAvailability();
	printNeed();
	printf("\n");

	printf("\n\nChecking state of the system ........");

	flag=safety();
	if ( flag == TRUE ) printf("\nThe system is in safe state ..............");
	else {
		printf("\nThe system is in unsafe state !!!!!!!!!!\n");
		exit(1);
	}
	
	while(cont=='Y'||cont=='y') {
		printf("\nEnter request from a process");

		printf("\nProcess No. ?:");
		scanf("%d",&p);
		printf("\nEnter Number of units of each resource type( Input as 1 x %d array, values separated by space\n ",m);
		for(i=1; i<=m; i++) {
			scanf("%d",&request[i]);
		}
		printf("\n--------------------------------------------------------------------------------");
		printf("\n----------------------Request from Process P%d-------------------------------\n",p );
		printArray(request,m);
		printf("\n--------------------------------------------------------------------------------");
		printf("\nProcessing the request.........");
		flag=processRequest(p);
		if(flag==TRUE) {

			printf("\nRequest is accepted.............");
			printf("\nChecking state of the system...................");
		
			if ( safety() ) {
				printf("\nSystem will be in safe state........Request can be granted\n\n");
			
			}
			else {
				printf("\nSystem will not be in safe state........Request can't be granted\n\n");	
				restore(p);
			}
		}
		else {
			if(flag==ERROR) printf("\n\nRequest exceed maximum claim !!!!!\n");
			else printf("\nWait........Resources are not available\n");	
		}
		printf("\nContinue Receiving Requests Y/N ?:");
		scanf("%c",&newline);
		scanf("%c",&cont);
		scanf("%c",&newline);
	}
}

