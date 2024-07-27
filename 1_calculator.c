#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void operation(char operation,int a,int b){
    int result;
    switch(operation){
        case '+': result=a+b;
                  printf("result %d\n",result);
                  exit(result);
         case '-': result=a-b;
                  printf("result %d\n",result);
                  exit(result);
         case '*': result=a*b;
                  printf("result %d\n",result);
                  exit(result);
         case '/':if (b!=0){
                 result=a+b;
                  printf("result %d\n",result);
                  exit(result);}
                else{
                    exit(EXIT_FAILURE);
                }
        default: printf("Invalid operation\n");
                exit(EXIT_FAILURE);
    }
}

int main(){
    char op;int a,b,status;
    printf("Enter the operation,first number,second number");
    scanf("%c%d%d",&op,&a,&b);
    pid_t pid=fork();
    if (pid<0){
        perror("fork");
        return EXIT_FAILURE;
    }
    else if (pid==0){
        operation(op,a,b);
    }
    else{
        waitpid(pid,&status,0);
        if WIFEXITED(status){
            printf("The result is %d",WEXITSTATUS(status));
        }
        else{
            printf("Child didnt run successfully\n");
        }

    }
    return EXIT_SUCCESS;
}