#include<stdio.h>#include<conio.h>
int
a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
73
voidbfs(intv){for(i=1;i<=n;i++)
if(a[v][i]&&!visited[i]) q[++r]=i;
if(f<=r) { visited[q[f]]=1;
printf("%d\t",q[f]); bfs(q[f++]);
}}voidmain(){intv;clrscr();
printf("Enterthenoof
vertices:");scanf("%d",&n);
for(i=1;i<=n;i++){q[i]=0;
visited[i]=0;}
printf("\nEntergraphdatainmatrix
form:\n");for(i=1;i<=n;i++)for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("\nEnterthestarting
vertex:");scanf("%d",&v);
visited[v]=1;printf("%d",v);bfs(v);
getch();}
