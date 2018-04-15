/*
Program		: Producer Consumer problem . access buffer of size n. Solution using mutex
Date		: 24-11-10
File		: F-MutexProCon.c
Compile		: gcc -lpthread F-MutexProCon.c -o F-MutexProCon
Run		: ./F-MutexProCon <No.Producer> <No.Consumer>
Last Modify	: 29-11-10
Status		: Working for n producer and n consumer
		  Buffer-size as cmd line argument
		  Number of producers and consumers as cmd line args
					
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
 


#define TRUE 1


typedef int buffer_item;


pthread_mutex_t mutex; // The mutex lock 
pthread_cond_t counterValue; // condition variable
					//counter=0 , consumers wait on condition variable
					//counter=BUFFER_SIZE, producers wait on condition variable

buffer_item buffer[500]; // The buffer 
int BUFFER_SIZE;	//Received as cmd line argument

int counter; // buffer  item counter 

pthread_t tidp[100],tidc[100];       //Thread IDs for producer and consumer
pthread_attr_t attr; 			//Set of thread attributes


void initializeData() {

   
   pthread_mutex_init(&mutex, NULL);  // Create the mutex lock 

   
   
   pthread_attr_init(&attr); // Get the default attributes 

   
   counter = 0; //Buffer item counter
}
int createItem() {
	//Create a random number between 1 and to-value
	
	int item=rand()%50;
	return item;
}

int randomDelay() {
	// 1- n seconds delay
	int delay=rand()%50;
	return delay;
}


void *producer(void *param) {
	buffer_item item;
	int *myNumber;

	myNumber=(int *)param;
	
   	while(TRUE) {
      

      		sleep(randomDelay());
      
      		/* acquire the mutex lock */
      		pthread_mutex_lock(&mutex);
	
//--------------------------------------------------------------------
		while( counter >= BUFFER_SIZE ) {
		
			printf("\n\t\tProducer[%d] Waiting....",*myNumber);
			pthread_cond_wait(&counterValue, &mutex);
			printf("\n\t\tProducer[%d] Wake up....",*myNumber);
		}

	
      		item = createItem(); //Produce an item , a random number

      		if(insert_item(item)) {
         		fprintf(stderr, "Producer report error condition !!!!!!!!!\n");
      		}
      		else {
         		printf("\n\tproducer[%d] produced %d item(%d)\n",*myNumber, item,counter);
      		}
		pthread_cond_broadcast(&counterValue);
//------------------------------------------------------------------------

	
     		pthread_mutex_unlock(&mutex); //Release the mutex
      
      
	}
}


void *consumer(void *param) {
	buffer_item item;
	int *myNumber;

	myNumber=(int *)param;
	
	while(TRUE) {
      			
      			
      			sleep(randomDelay());      
      			
      			pthread_mutex_lock(&mutex); // aquire the mutex lock 
	
//--------------------------------------------------------------------

			while( counter <= 0 ) {
				printf("\nConsumer[%d] Waiting....",*myNumber);
				 pthread_cond_wait(&counterValue, &mutex);
				printf("\nConsumer[%d] Wake up....",*myNumber);
			}

		      if(remove_item(&item)) {
         			fprintf(stderr, "Consumer report error condition!!!!!!!\n");
      			}
      			else {
         			printf("\nconsumer[%d] consumed %d   item  %d\n",*myNumber, item,counter+1);
		      }
			pthread_cond_broadcast(&counterValue);
 //------------------------------------------------------------------
	
			pthread_mutex_unlock(&mutex); // release the mutex lock 
      
      
	}
}

int insert_item(buffer_item item) {
   /* When the buffer is not full add the item
      and increment the counter*/
	if(counter < BUFFER_SIZE) {
		buffer[counter] = item;
		counter++;
		return 0;
	}
	else { /* Error the buffer is full */
		return -1;
	}
}


int remove_item(buffer_item *item) {
   /* When the buffer is not empty remove the item and decrement the counter */
	if(counter > 0) {
		*item = buffer[(counter-1)];
		counter--;
      		return 0;
   	}
   	else { /* Error buffer empty */
      		return -1;
   	}
}

int main(int argc, char *argv[]) {
   
	int i;
	int number[100];

	if(argc != 4) {
		fprintf(stderr, "USAGE:./executable <Buffer-Size> <No.Producers> <No.Consumers>\n");
		exit(1);
	}

   	BUFFER_SIZE=  atoi(argv[1]);
	int numProd = atoi(argv[2]); /* Number of producer threads */
	int numCons = atoi(argv[3]); /* Number of consumer threads */

	/* Initialize the app */
	initializeData();

	for(i=0; i<100; i++) {
		number[i]=i;
	}
	/* Create the producer threads */
	for(i = 0; i < numProd; i++) {
	      /* Create the thread */
	      pthread_create(&tidp[i],&attr,producer, &number[i]);
	}

	/* Create the consumer threads */
	for(i = 0; i < numCons; i++) {
		/* Create the thread */
		pthread_create(&tidc[i],&attr,consumer,&number[i]);
	}
	for(i = 0; i < numProd; i++) {
		pthread_join(tidp[i],NULL);	
	}
	for(i = 0; i < numCons; i++) {
		pthread_join(tidc[i],NULL);	
	}
  
	//sleep(100);	// Uncomment if not using pthread_join()

  
	printf("Exit the program\n");   // Uncomment if not using pthread_join()
	exit(0);
}

