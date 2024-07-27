

#include<stdio.h>
int main(){
    
    int res=3,proc=5;
    int avail[3]={ 3 , 3 , 2 } ;
    int max [5][3]={ { 7 , 5 , 3 } , // P0 // MAX Matrix  
                    { 3 , 2 , 2 } , // P1  
                    { 9 , 0 , 2 } , // P2  
                    { 2 , 2 , 2 } , // P3  
                    { 4 , 3 , 3 } };
    int alloc[5][3]={ { 0 , 1 , 0 }, // P0 // Allocation Matrix  
                        { 2 , 0 , 0 } , // P1  
                        { 3 , 0 , 2 } , // P2  
                        { 2 , 1 , 1 } , // P3  
                        { 0 , 0 , 2 } } ;
    int need[proc][res];
    for (int i=0;i<proc;i++){
        for(int j=0;j<res;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    int f[proc];
    for (int i=0;i<proc;i++){
        f[i]=0;
    }
    int ans[proc], ind=0;
    for (int k=0;k<5;k++){
        for(int i=0;i<proc;i++){

            if(f[i]==0){
                int flag=0;
                for(int j=0;j<res;j++){
                    if (need[i][j]>avail[j])
                    {flag=1;
                    break;}
                }
                if (flag==0){
                    f[i]=1;
                    ans[ind++]=i;
                   
                    for(int j=0;j<res;j++){
                        avail[j]+=alloc[i][j];
                    }
                }
            }
        }
    }
   
    int flag=0;
    for (int i=0;i<proc;i++){
        if (f[i]==1){
            flag=1;
           
            break;
        }
    }
    if (flag==1){
        for(int i=0;i<proc;i++){
            printf("%d\n",ans[i]);
        }
    }
    else{
        printf("Unsafe!!");
    }
}


