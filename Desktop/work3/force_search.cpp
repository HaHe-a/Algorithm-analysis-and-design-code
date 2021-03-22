#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int value[maxn],n,x;
int search(int num)
{
	for(int i=1;i<=n;i++){
		if(value[i]==num){
			return i;
		}
	}	
	return 0;
}
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		scanf("%d",&value[i]);
	}
	cout<<search(x)<<endl;
	return 0;
}