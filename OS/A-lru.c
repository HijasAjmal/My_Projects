/*
Program	:	LRU page replacement
Variable timer keeps time.
time[] - Refernce time of a page loaded to a particular frame. 
On refering a page, update time value 
The page referenced long ago will have a low time value.
The page with smallest time value is the LRU page

Date:10/12/16

*/


#include<stdio.h>
 
int findLRU(int time[], int n){
/*
	Return the frame which has min timer value
*/
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}
 
int main()
{
    int no_of_frames, no_of_pages;
    int frames[10], pages[30];
    int	timer = 0, time[10], flag1, flag2, i, j, pos, faults = 0;


    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter reference string: ");
    
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < no_of_frames; ++i){  //mark free frame
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
	printf("\n....................................................................");
	printf ("\n Reference to page %d has come ",pages[i]); 
        
        for(j = 0; j < no_of_frames; ++j){
		
		//printf("\nFrame j- %d =%d and page i- %d=%d",j,frames[j],i,pages[i]);

            if(frames[j] == pages[i]){		//Page is already loaded in frame-j, no page fault		
                timer++;
                time[j] = timer;
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){				//load page to a new free frame
		printf("\nTry to find free frame and load page");	
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){		//check for free frame
                    timer++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = timer;
			printf("\n Page loaded to free Frame-%d . time=%d",j,timer);
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){				//find lru page and replace it
		
            pos = findLRU(time, no_of_frames);
            timer++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = timer;
		printf("\n Replace the page loaded into frame-%d at time =%d",pos,timer);
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
	printf("\n....................................................................");
    }
    
    printf("\n\nTotal Page Faults = %d\n\n", faults);
    
    return 0;
}
