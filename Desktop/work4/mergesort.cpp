#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int data[maxn];
void Merge(int num[],int l,int mid,int r){
    int llen=mid-l+1;
    int rlen=r-mid;
    int lnum[llen],rnum[rlen];
    for(int i=l;i<=mid;i++){
        lnum[i-l]=num[i];
    }
    for(int i=mid+1;i<=r;i++){
        rnum[i-mid-1]=num[i];
    }
    int i=0,j=0,len=l;
    while(i<llen&&j<rlen){
        num[len++]= (lnum[i]<=rnum[j]?lnum[i++]:rnum[j++]);
    }
    while(i<llen){
        num[len++]=lnum[i++];
    }
    while(j<rlen){
        num[len++]=rnum[j++];
    }
}
void MergeSort(int num[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        MergeSort(num,l,mid);
        MergeSort(num,mid+1,r);
        Merge(num,l,mid,r);
    }
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data[i]);
	}
	MergeSort(data,1,n);
	for(int i=1;i<=n;i++){
		printf("%d%c",data[i]," \n"[i==n]);
	}
	return 0;
}