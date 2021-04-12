#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;

struct node{
	double x,y;
}s[maxn];
node p1,p2;
double min_dis=10e8;
double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&s[i].x,&s[i].y);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double nowdis=dis(s[i],s[j]);
			if(nowdis<min_dis){
				min_dis=nowdis;
				p1=s[i];
				p2=s[j];
			}
		}
	}
	cout<<min_dis<<endl;
	cout<<"<"<<p1.x<<","<<p1.y<<">"<<" "<<"<"<<p2.x<<","<<p2.y<<">"<<endl;
}