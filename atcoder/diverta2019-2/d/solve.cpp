#include<cstdio>
#include<algorithm>
//dp[i]=i個のどんぐりを使って取引所A→Bを使ったあとのどんぐりの個数の最大値
long long dp[5001];
//dp2[i]=i個のどんぐりを使って取引所B→Aを使ったあとのどんぐりの個数の最大値
long long dp2[5000*5000+1];
int main(){
    long long n,a[3],b[3];
    scanf("%lld",&n);
    for(int i=0;i<3;i++)scanf("%lld",&a[i]);
    for(int i=0;i<3;i++)scanf("%lld",&b[i]);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        for(int j=0;j<3;j++){
            if(a[j]<=i)dp[i]=std::max(dp[i],dp[i-a[j]]+b[j]);
        }
    }
    dp2[0]=0;
    for(int i=1;i<=dp[n];i++){
        dp2[i]=dp2[i-1]+1;
        for(int j=0;j<3;j++){
            if(b[j]<=i)dp2[i]=std::max(dp2[i],dp2[i-b[j]]+a[j]);
        }
    }
    printf("%lld\n",dp2[dp[n]]);
    return 0;
}