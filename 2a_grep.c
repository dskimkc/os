// #include <stdio.h>
// #include <string.h>
// int main() {
//    char filename[10],pattern[10],temp[200],res[100];
//    FILE *fp;
//     printf("\n Enter file name:"); 
//     scanf("%s",filename);
//     printf("\n Enter the pattern:");
//     scanf("%s",pattern);
//     fp=fopen(filename,"r");   
//     if(fp==NULL)
//     {
//         printf("\n Error opening file.\n");
//         return 1;
//     }
//    while(!feof(fp))
//     {
//         fgets(temp,sizeof(temp),fp);
//         if(strstr(temp,pattern))
//         {
//             printf("%s",temp);
//         }
//     } 
//     fclose(fp);
//     return 0;
// }


#include<stdio.h>
#include<string.h>
int main(){
    char filename[10],pattern[10],temp[200];
    printf("enter teh filename\n");
    scanf("%s",filename);
   
    printf("\n Enter the pattern\n");
    scanf("%s",pattern);

    FILE  *fp;
    fp=fopen(filename,"r");
    if (fp==NULL){
        printf("Error loading file");
        return 1;
    }
    while(!feof(fp)){
        fgets(temp,sizeof(temp),fp);
        if (strstr(temp,pattern)){
            printf("%s",temp);
            
        }
    }
    fclose(fp);
    return 0;
}