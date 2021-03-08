#include<bits/stdc++.h>
using namespace std;
int fa[10005];
struct IN{
	int x,y,w;
}s[200005];
bool cmp(IN a,IN b){
	return a.w<b.w;
}
void init(int n)
{
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
 } 
 int find(int x)
 {
 	return (fa[x]==x)?x:fa[x]=find(fa[x]);
 }
 void merge(int i,int j)
 {
 	int x=find(i),y=find(j);
 	
 		fa[y]=x;
	 
 }
 int main()
 {
 	int n,m,sum;
 	scanf("%d %d",&n,&m);
 	init(n);
 	sum=0;
 	for(int i=1;i<=m;i++){
 		scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].w);
	}
	sort(s+1,s+m+1,cmp);
	int pos=0;
	for(int i=1;i<=m;i++){
	 	if(find(s[i].x)!=find(s[i].y)){
		 	sum+=s[i].w;
		 	merge(s[i].x,s[i].y);
		 	pos++;
		}
		if(pos==n-1)break;
	}
	printf("%d\n",sum);
	return 0;
 }