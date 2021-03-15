#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353 
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))  
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int NUM = 105;
int graph[NUM][NUM];
int n,m;
void Floyd()
{
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(graph[i][k]!=INF){
				for(int j=1;j<=n;j++){
					if(graph[i][k]+graph[k][j]<graph[i][j])graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m)){
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				graph[i][j]=INF;
			}
		}
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			graph[a][b]=c;
		}
		Floyd();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					printf("%d->%d=%d\n",i,j,graph[i][j]);
				}
			}
		}
	}
	return 0;
}