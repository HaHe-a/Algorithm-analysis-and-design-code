#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+10;

int s[maxn];
int find(int L[],int k,int size)
{
    int pos=L[(size+1)/2];
    int L1[size/2+5],L2[size/2+5];
    int size1=0,size2=0;
    for(int i=1;i<=size;i++)
    {
        if(i!=(size+1)/2){
            if(L[i]<=pos)L1[++size1]=L[i];
            else L2[++size2]=L[i];
        }
    }
    if(k==size1+1){
        return pos; 
    }else if(k<size1+1){
        return find(L1,k,size1); 
    }else{
        return find(L2,k-(size1+1),size2);
    }
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	int ans=find(s,k,n);
	cout<<ans<<endl;
}