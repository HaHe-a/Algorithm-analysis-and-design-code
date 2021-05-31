#include<bits/stdc++.h>

using namespace std;
int graph[105][105];
int n,m;
int color[105];
int ans=0;
void dfs(int cnt)
{
    if(cnt>n){
        for(int i=1;i<=n;i++){
            printf("%d%c",color[i]," \n"[i==n]);
        }
        ans++;
        return;
    }
    for(int i=1;i<=m;i++){
        color[cnt]=i;
        int k=1;
        for(int j=1;j<=n;j++){
            if(graph[cnt][j]&&color[j]==color[cnt]){
                k=0;
                break;
            }
        }
        if(k){
            dfs(cnt+1);
        }
        color[cnt]=0;
    }
}
int main()
{
    cin>>n>>m;
    while(1){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==0&&v==0)break;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    dfs(1);
    printf("sum=%d\n",ans);
}

/*
5 4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
0 0

*/