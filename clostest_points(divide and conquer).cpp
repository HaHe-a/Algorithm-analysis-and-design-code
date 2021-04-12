#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;

struct node{
	double x,y;
}s[maxn];
node p1,p2;
double min_dis=10e8;
bool cmp(node a,node b)
{
	if(fabs(a.x-b.x)<1e-6){
		return a.y<b.y;
	}else{
		return a.x<b.x;
	}
}
double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

vector<node>temp;
void solve(int l,int r)
{
	if(r-l==1){
		double nowdis=dis(s[l],s[r]);
		if(min_dis>nowdis){
			p1=s[l];
			p2=s[r];
			min_dis=nowdis;
		}
	}else if(r-l==2){
		double nowdis=dis(s[l],s[l+1]);
		if(nowdis<min_dis){
			p1=s[l];
			p2=s[l+1];
			min_dis=nowdis;
		}
		nowdis=dis(s[l],s[r]);
		if(nowdis<min_dis){
			p1=s[l];
			p2=s[r];
			min_dis=nowdis;
		}
		nowdis=dis(s[l+1],s[r]);
		if(nowdis<min_dis){
			p1=s[l+1];
			p2=s[r];
			min_dis=nowdis;
		}
	}else{
		int mid=(l+r)/2;
		solve(l,mid);
		solve(mid+1,r);
		temp.clear();
		for(int i=l;i<=r;i++){
			if(s[i].x-s[mid].x<min_dis){
				temp.push_back(s[i]);
			}
		}
		for(int i=0;i<temp.size();i++){
			for(int j=i+1;j<temp.size();j++){
				double nowdis=dis(temp[i],temp[j]);
				if(nowdis<min_dis){
					min_dis=nowdis;
					p1=temp[i];
					p2=temp[j];
				}
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&s[i].x,&s[i].y);
	}
	sort(s+1,s+n+1,cmp);
	solve(1,n);
	cout<<min_dis<<endl;
	cout<<"<"<<p1.x<<","<<p1.y<<">"<<" "<<"<"<<p2.x<<","<<p2.y<<">"<<endl;
}
