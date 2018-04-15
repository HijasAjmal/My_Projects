/*
	Program	: Prodecer Consumer Problem. Producer and consumer access a buffer of size n
	File	: J-ProCon.c
	Date	: 22-11-10
	LastModi: 23-11-10
	Compile	: gcc  -lpthread J-proCon.c -o J-ProCon
	Run	: ./J-ProCon <int> <int>

	Stauts	:
			used semaphore
			rand() used to creatw data items
			Buffer has global scope 
			rand() within a range 1-500
			Identify threads by a number
			n producer, n consumers
			Number of Prod & cons as cmd line args
			Buffer-size fixed to 5
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


#define BUFFER_SIZE 5
#define RAND_DIVISOR 100000000
#define TRUE 1
#define FALSE 0

typedef int buffer_item;


sem_t mutex; // Semaphore for mutual exclusion


sem_t full, empty;


buffer_item buffer[BUFFER_SIZE]; // Buffer


int counter; // Buffer item counter

pthread_t tid[100];       //Thread ID of Producers
pthread_t tidc[100];       //Thread ID of Consumers

buffer_item item;
 
void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */

void initializeData() {

   
	sem_init(&mutex, 0, 1);

  
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, BUFFER_SIZE);
	counter = 0;
}

void *producer(void *param) {

	int *id;
	id=(int *)param;
	while(TRUE) {
      		sleep(1);

		item = 1+(int) (500.0*(rand()/(RAND_MAX+1.0)));	// generate a random number 1-500 

      		sem_wait(&empty);
      		sem_wait(&mutex);

      		if(insert_item(item)) {
         		fprintf(stderr, " Producer-%d report error condition\n",id);
      		}
      		else {
         		printf("producer-%d produced %d  as Item-%d\n",id, item,counter);
      		}
      		sem_post(&mutex);
      		sem_post(&full);
   	}
}


void *consumer(void *param) {
	
	int *id;
	id=(int *)param;
	
	while(TRUE) {
      		sleep(3);

      		sem_wait(&full);
      		sem_wait(&mutex);
      		if(remove_item(&item)) {
         		fprintf(stderr, "Consumer-%d report error condition\n",id);
      		}
      		else {
         		printf("\t\tconsumer-%d consumed %d-----item:%d\n",id, item,counter+1);
      		}
      		sem_post(&mutex);
      		sem_post(&empty);
   	}
}

int insert_item(buffer_item item) {
   // When the buffer is not full add the item and increment the counter
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
  //When the buffer is not empty remove the item  and decrement the counter 
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
	int countProd, countCons;
	
	if(argc != 3) {	//No.cmd line arguments
      		fprintf(stderr, "USAGE:./J-ProCon  <No.Producers> <No.consumers>\n");
		exit(1);
   	}

	countProd = atoi(argv[1]); /* Number of producer threads */
   	countCons = atoi(argv[2]); /* Number of consumer threads */



   	initializeData();

   /* Create the producer tnd consumer hreads */
	for(i=1; i<=countProd; i++) {
      		pthread_create(&tid[i],NULL,producer,(void *)i);
	}
	for(i=1; i<=countCons; i++) {
      		pthread_create(&tidc[i],NULL,consumer,(void *)i);
	}
	for(i=1; i<=countProd; i++) {
	
		pthread_join(tid[i],NULL);
	}	
	for(i=1; i<=countCons; i++) {
		pthread_join(tidc[i],NULL);
	}
	//sleep(100);  // Uncomment if pthread_join is not used

   	//printf("Exit the program\n");  // Uncomment if pthread_join is not used
   	exit(0);
}
