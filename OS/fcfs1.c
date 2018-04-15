#include <stdio.h>


// struct for process creation
struct process
{
	int arrival_time, burst_time, turn_around_time, name_of_process, waiting_time;
	
}array_of_process[100], temp_process;

// start main function
int main(){
	int index1 = 0, index,flag, flag1=0, process_limit,temp_process_id,ctime = 0;
	float avg_ttime,avg_wtime,wtime = 0,ttime = 0;
	printf("\t\t\tProgram for fcfs scheduling-----");
	printf("\n=>	Enter the number of process::");
	scanf("%d", &process_limit);

	// read process informations
	do{
		do{	flag = 0;
			printf("\n=>	Enter the id of process::");
			scanf("%d",&temp_process_id);
			

			// check whether the given process id match to any other process id
			for(index = 0; index<process_limit;index++){
				if(array_of_process[index].name_of_process == temp_process_id){
					flag=1;
					break;
				}
			}
			if(flag == 1)
				printf("\n=>	This id is already used, try another one");
			else
				array_of_process[index1].name_of_process=temp_process_id;
		}while(flag == 1);
			printf("\n=>	Enter the arrival_time of process %d::",array_of_process[index1].name_of_process);
			scanf("%d",&array_of_process[index1].arrival_time);
			printf("\n=>	Enter the burst_time of process %d::",array_of_process[index1].name_of_process);
			scanf("%d",&array_of_process[index1].burst_time);
			printf("\n\n-------------------------------");
			index1++;
	}while(index1<process_limit);

	// sort processes with their arrival time 
	for(index = 0;index<process_limit;index++){
		for(index1 =0;index1<(process_limit-1-index);index1++){
			if(array_of_process[index1].arrival_time>array_of_process[index1+1].arrival_time){
				temp_process = array_of_process[index1];
				array_of_process[index1] = array_of_process[index1+1];
				array_of_process[index1+1] = temp_process;
			}
		}
	}
	// sort with process id, if two or more processes have same arrival time
	
	for(index = 0;index<process_limit;index++){
		for(index1 =0;index1<(process_limit-1-index);index1++){
			if(array_of_process[index1].arrival_time == array_of_process[index1+1].arrival_time){
				if(array_of_process[index1].name_of_process>array_of_process[index1+1].name_of_process){
						temp_process = array_of_process[index1];
						array_of_process[index1] = array_of_process[index1+1];
						array_of_process[index1+1] = temp_process;
					}
			}
		}
	}
	// Display the table of process result
	printf("\n=>	Process id\tarrival_time\tburst_time\tturn_around_time");
	ctime = array_of_process[0].burst_time + array_of_process[0].arrival_time;
	for(index = 0;index<process_limit;index++){
		array_of_process[index].turn_around_time = ctime - array_of_process[index].arrival_time;
		array_of_process[index].waiting_time = array_of_process[index].turn_around_time - array_of_process[index].burst_time;
		wtime += array_of_process[index].waiting_time;
		ttime += array_of_process[index].turn_around_time;
		printf("\n=>	%d\t%d\t%d\t%d",array_of_process[index].name_of_process,array_of_process[index].arrival_time,array_of_process[index].burst_time,array_of_process[index].turn_around_time);
		ctime = ctime + array_of_process[index+1].burst_time;
	}

	//Display the average turn_around_time and waiting_time of total process
	avg_ttime = (float)ttime/process_limit;
	printf("\n=>	Average turn_around time ::%f",avg_ttime);
	avg_wtime = (float)wtime/process_limit;
	printf("\n=>	Average waiting time ::%f",avg_wtime);
	
}






/*		Algorithm

1.	start
2.	create a struct and required variables for process creation
3.	in main function
	3.1	read the process limit to a variable process limit
	3.2	read the process id
	3.3	check whether the given process id is not used
	3.4	if used display "its already used, try another one", else do next step
	3.5	read the following:
		- arrival time
		- burst time
	3.6	sort the processes in asending order of their arrival time
	3.7	sort the processes in asending order of their process id if two or more process have same arrival time
	3.8	calculate and display turnaround time and waiting time of each processes with (tat = ct-at, wt = tat - bt)
	3.9	calculate and display average turnaround time and average waiting time. 
*/
