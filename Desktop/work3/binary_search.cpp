#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int value[maxn],n,x;
int search(int num)
{
	int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(value[mid]<num) l=mid+1;
        else if(value[mid]>num) r=mid-1;
        else return mid;
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