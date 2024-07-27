#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[30], time[10], no_of_frames, no_of_pages, counter = 0, faults = 0, hits = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter reference string: ");
    for (int i = 0; i < no_of_pages; ++i) scanf("%d", &pages[i]);

    for (int i = 0; i < no_of_frames; ++i) frames[i] = -1;

    for (int i = 0; i < no_of_pages; ++i) {
        int flag1 = 0;
        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = 1;
                hits++;
                break;
            }
        }
        if (!flag1) {
            int flag2 = 0;
            for (int j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
            if (!flag2) {
                int pos = findLRU(time, no_of_frames);
                counter++;
                faults++;
                frames[pos] = pages[i];
                time[pos] = counter;
            }
        }
        for (int j = 0; j < no_of_frames; ++j) printf("%d\t", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Hit Ratio = %.2f\n", (float)hits / no_of_pages);
    printf("Fault Ratio = %.2f\n", (float)faults / no_of_pages);

    return 0;
}