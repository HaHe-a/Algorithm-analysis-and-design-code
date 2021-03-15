#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353 
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))  
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int NUM = 1005;
struct edge{
	int from,to,w;
	edge(int a,int b,int c){from=a;to=b;w=c;}
};
vector<edge>e[NUM];
struct s_node{
	int id,n_dis;
	s_node(int b,int c){id=b;n_dis=c;}
	bool operator < (const s_node &a) const
	{return n_dis>a.n_dis;}
};
int n,m;
int dis[NUM];
//打印路径
int pre[NUM];
void print_path(int s,int t)
{
	if(s==t)printf("%d",s);
	print_path(s,pre[t]);
	printf("%d",t);
}
void Dijkstra(int s)  //s是起点
{
    bool done[NUM];
    for(int i=1;i<=n;i++){dis[i]=INF;done[i]=false;}
    dis[s]=0;
    ;priority_queue<s_node>Q;
    Q.push(s_node(s,dis[s]));
    while(!Q.empty())
    {
    	s_node u=Q.top();
        Q.pop();
        if(done[u.id])continue;
        done[u.id]=true;
        for(int i=0;i<e[u.id].size();i++){
        	edge y=e[u.id][i];
        	if(done[y.to])continue;
        	if(dis[y.to]>y.w+u.n_dis){
        		dis[y.to]=y.w+u.n_dis;
        		Q.push(s_node(y.to,dis[y.to]));
        		pre[y.to]=u.id;
        	}
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        getchar();
        char x,y;
    	int c;
        scanf("%c %c %d",&x,&y,&c);
        e[int(x-'a'+1)].push_back(edge(int(x-'a'+1),int(y-'a'+1),c));
    }
    Dijkstra('a'-'a'+1);
    printf("%d\n",dis['h'-'a'+1]);
	return 0;
}

/*
8 11
a b 1
b d 2
c a 2
d c 1
d f 8
e d 2
e g 2
f e 2
g f 3
g h 3
h f 2
*/