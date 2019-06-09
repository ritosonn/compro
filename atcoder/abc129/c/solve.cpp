#include<cstdio>
using ll = long long;
ll const p=1e9+7;
ll dp[100001];
int a[100000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    int ai=0;
    dp[0]=1;
    if(a[ai]==1){
        dp[1]=0;
        ai++;
    }else{
        dp[1]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[ai]==i){
            dp[i]=0;
            ai++;
        }else{
            dp[i]=(dp[i-1]+dp[i-2])%p;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}