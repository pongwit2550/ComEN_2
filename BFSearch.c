#include <stdio.h>

void bfs(int v);
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1,ans[20],k=0;
int main()
{
int v;
printf("\n Enter the number of vertices:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    q[i]=0;
visited[i]=0;
}
printf("\n Enter graph data in matrix form:\n");
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 {
 printf("G[%d][%d] = ",i,j);
 scanf("%d",&a[i][j]);
}

printf("\n Enter the starting vertex:");
scanf("%d",&v);
ans[k++]=v;
visited[v]=1;
bfs(v);
printf("\n The node which are reachable are:\n");
for(i=0;i<k;i++)
 printf("%d\t",ans[i]);
printf("\n");
}
void bfs(int v)
{ int st=0;
for(i=1;i<=n;i++)
{ st = 0;
 if(a[v][i] && !visited[i])
  { for (int t=0;t<n;t++)
 if (q[t]==i) st =1;
if (st ==0)
q[++r]=i;
}
}
printf("f=%d r= %d \n",f,r);
 for(int p =0;p<=n;p++){
    printf("%d ",q[p]);}
  printf("\n");
 for(int p =0;p<=n;p++)
 printf("%d ",visited[p]);
  printf("\n");
if(f<=r)
{
    if (!visited[q[f]]){
        visited[q[f]]=1;
        ans[k++]=q[f];
        bfs(q[f++]);
    }
}
}
