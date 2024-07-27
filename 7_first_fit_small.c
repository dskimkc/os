#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

struct Partition {
    int size;
    bool allocated;
} partitions[MAX_PARTITIONS];

struct Process {
    int size;
    int partition_id; // ID of the allocated partition
} processes[MAX_PROCESSES];

int num_partitions = 3;
int num_processes = 2;

void initialize() {
    // Initialize partitions
    partitions[0] = (struct Partition) {50, false};
    partitions[1] = (struct Partition) {100, false};
    partitions[2] = (struct Partition) {500, false};

    // Initialize processes
    processes[0] = (struct Process) {80, -1};
    processes[1] = (struct Process) {150, -1};
}

void display() {
    printf("Partitions:\nID\tSize\tAllocated\n");
    for (int i = 0; i < num_partitions; i++)
        printf("%d\t%d\t%s\n", i + 1, partitions[i].size, partitions[i].allocated ? "Yes" : "No");

    printf("\nProcesses:\nID\tSize\tPartition ID\n");
    for (int i = 0; i < num_processes; i++)
        printf("%d\t%d\t%d\n", i + 1, processes[i].size, processes[i].partition_id + 1);

    printf("\n");
}

void firstFit() {
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_partitions; j++) {
            if (!partitions[j].allocated && partitions[j].size >= processes[i].size) {
                partitions[j].allocated = true;
                processes[i].partition_id = j;
                printf("Process %d allocated to Partition %d\n", i + 1, j + 1);
                break;
            }
        }
    }
}

int main() {
    initialize();
    printf("Initial State:\n");
    display();
    firstFit();
    printf("After Allocation:\n");
    display();
    return 0;
}