#include<stdio.h>
int main(){
    int n,m,i,j,k;
    n=5;//no of processes
    m=3;//no of resources
    int alloc[n][m];
    int max[n][m];
    for(int i=0;i<n;i++){
            printf("allocation for P%d:",i+1);
        for (int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
          printf("max for P %d",i+1);
          for (int k=0;k<m;k++){
            scanf("%d",&max[i][k]);
        }

    }
    int avail[3]={3,3,2};
    int f[n],ans[n],ind=0;
    for(k=0;k<n;k++){
        f[k]=0;
    }
    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];
    }
    int y=0;
    for(k=0;k<5;k++){
        for(i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;
                for(j=0;j<m;j++)
                {

                    if(need[i][j]>avail[j]){
                        flag=1;
                    break;
                }
            }
            if(flag==0){
                ans[ind++]=i;
                for(y=0;y<m;y++)
                    avail[y]+=alloc[i][y];
                f[i]=1;

            }
        }
    }
    }
    int flag=1;
     for(i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("The system given is not safe");
            break;
        }
     }
     if(flag==1){
        printf("The above given sequence is safe \n");
        for(i=0;i<n-1;i++)
            printf("P%d ->",ans[i]);
        printf("P%d:",ans[n-1]);
     }
     return 0;
}
