#include<cstdio>
using ll=long long;
constexpr ll p=1e9+7;
//dp[i][j]={s[0..i-1]とt[0..j-1]に含まれる空でない共通部分列の個数}
ll dp[2001][2001];
ll s[2000],t[2000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",&s[i]);
    for(int j=0;j<m;j++)scanf("%lld",&t[j]);
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=1;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])dp[i][j]=(1+dp[i][j-1]+dp[i-1][j])%p;
            else dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+p)%p;
        }
    }
    printf("%lld\n",(dp[n][m]+1)%p);
    return 0;
}