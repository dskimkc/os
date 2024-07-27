#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int wait(int s){
    return(--s);
}
int signal(int s ){
    return(++s);
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("producer produces %d",x);
    mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("consumer consumes %d",x);
    x--;
    mutex=signal(mutex);
}

int main(){
    int choice;
    printf("Enter the choice 1. Producer \t 2. Consumer \n");
    while(1){
        printf("Enter choice");
        scanf("%d",&choice);
        switch(choice){
            case 1: if (mutex==1&&empty!=0){
                producer();
                }
                else{
                    printf("BUffer full!!\n");

                }
                break;
            case 2: if (mutex==1&&full!=0){
                consumer();
            }
            else{
                printf("Buffer empty\n");
            }
            break;
            default:printf("Invalid choice\n");
                    exit(0);
        }
    }
}