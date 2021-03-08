#include<bits/stdc++.h>
#define ll long long
#define MOD 1e9+7 
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))  
#define _for(i,a,b) for(int i=a; i< b; i++)
#define _rep(i,a,b) for(int i=a; i<=b; i++)
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
const int MAXN = 1000005 ;
inline int rd() 
{
    int res = 0,flag = 0;
    char ch;
    if ((ch = getchar()) == '-')flag = 1;
    else if(ch >= '0' && ch <= '9')res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')res = (res<<1) + (res<<3) + (ch - '0');
    return flag ? -res : res;
}
//
int head[MAXN]; 
int num=0;
struct edg{
   int next,to;
}edge[MAXN];
void edge_add(int u,int v)   //链式前向星存图
{
   num++;
   edge[num].next=head[u];edge[num].to=v;head[u]=num;
   edge[++num].next=head[v];edge[num].to=u;head[v]=num;
}
//---------------------
// lca部分
int n,m,s;
int dep[MAXN]={0},f[MAXN][23];
void dfs(int u,int father)//对应深搜预处理f数组 
{
    dep[u]=dep[father]+1;
    for(int i=1;(1<<i)<=dep[u];i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father)continue;//双向图需要判断是不是父亲节点 
        f[v][0]=u;
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)//从大到小枚举使x和y到了同一层 
    {
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
        if(x==y)return x;
    }
    for(int i=20;i>=0;i--)//从大到小枚举 
    {
        if(f[x][i]!=f[y][i])//尽可能接近 
        {
            x=f[x][i];y=f[y][i];
        } 
    } 
    return f[x][0];//随便找一个**输出 
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a1);scanf("%d",&a2);
        edge_add(a1,a2);//链式存边 
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a1,&a2);
        printf("%d\n",lca(a1,a2));//求两个节点的LCA 
    }
    return 0;
} 