#include <stdio.h>
void fcfs(int process[],int n ,int arrival_time[],int burst_time[]){

    int waiting_time[n],turnaround_time[n],c_time[n],total_wait_time,total_turnaround_time;
    c_time[0]=burst_time[0];
    for(int i=1;i<n;i++){
        c_time[i]=c_time[i-1]+burst_time[i];
    }
    for(int i=0;i<n;i++){
        turnaround_time[i]=c_time[i]-arrival_time[i];
        total_turnaround_time+=turnaround_time[i];
    }
    for (int i=0;i<n;i++){
        waiting_time[i]=turnaround_time[i]-burst_time[i];
        total_wait_time+=waiting_time[i];
    }
    printf("pid\tat\tbt\tct\ttt\twt\n");

    for (int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",process[i],arrival_time[i],burst_time[i],c_time[i],turnaround_time[i],waiting_time[i]); 

    }
}

int main(){
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int process[n],burst[n],arrival[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time");
        scanf("%d%d",&arrival[i],&burst[i]);
        process[i]=i+1;
    }
    fcfs(process,n,arrival,burst);
}