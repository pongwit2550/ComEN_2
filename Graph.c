#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;


int main(){
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d",&v);
    n = v; // Set the number of vertices
    for(i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {  
            printf("G[%d][%d] = ",i,j); 
            scanf("%d",&a[i][j]); 
        }
    }


    getch();
}














