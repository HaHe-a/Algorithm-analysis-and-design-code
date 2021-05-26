#include<bits/stdc++.h>

using namespace std;

int w[10005];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        if(sum+w[i]>c)break;
        sum+=w[i];
    }
    printf("%d",sum);
}