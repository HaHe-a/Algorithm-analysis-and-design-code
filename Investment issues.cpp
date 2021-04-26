#include<bits/stdc++.h>
#define ll long long
#define MOD 1e9+7 
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))  
#define _for(i,a,b) for(int i=a; i< b; i++)
#define _rep(i,a,b) for(int i=a; i<=b; i++)
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dp[105][1005];
int f[105][1005];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>f[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=j;k>=0;k--){
                dp[i][j]=max(dp[i][j],dp[i-1][j-k]+f[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        cout<<endl;
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

/*
4 5
11 12 13 14 15
0 5 10 15 20 
2 10 30 32 40
20 21 22 23 24

*/