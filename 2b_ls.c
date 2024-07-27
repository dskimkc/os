#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc,char *argv[]){
    DIR *dir;
    struct dirent *entry;
    if (argc==1){
        dir=opendir(".");
    }
    else if (argc==2){
        dir=opendir(argv[1]);
    }
    else{
        printf("usage %c [directory]",argv[0]);
        return 1;

    }
    if (dir==NULL){
        return 1;
    }
    while((entry=readdir(dir))!=NULL){
        printf("%s\n",entry->d_name);
    }
    closedir(dir);
    return 0;
}