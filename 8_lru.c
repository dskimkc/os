#include<stdio.h>
int findLRU(int time[], int n){
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
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0, hits = 0, total_requests = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);
	printf("Enter reference string: ");
    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }
    
	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }
    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;
    	for(j = 0; j < no_of_frames; ++j)
            {
    		if(frames[j] == pages[i])
                           {
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			hits++;
	   			total_requests++;
	   			break;
   			}
    	   }
    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			total_requests++;
	    			break;
	    		}
    		}	
    	}
    	if(flag2 == 0){
    		pos = findLRU(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    		total_requests++;
    	}
    	printf("\n");
    	for(j = 0; j < no_of_frames; ++j){
    		printf("%d\t", frames[j]);
    	}
	}	
    printf("\n\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Total Page Requests = %d\n", total_requests);
    float hit_ratio = (float) hits / total_requests;
    float fault_ratio = (float) faults / total_requests;
    printf("Hit Ratio = %.2f\n", hit_ratio);
    printf("Fault Ratio = %.2f\n", fault_ratio);
    return 0;
}      