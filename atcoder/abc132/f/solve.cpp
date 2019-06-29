#include<cstdio>
#include<cmath>
using ll = long long;
constexpr ll p=1e9+7;
//sqrt(1e9)==31622.77...
//dp[i][0][j]=長さiの正整数列で、i番目の数がjであるようなものの個数 (j<=sqrt(n))
//dp[i][1][j]=長さiの正整数列で、(i番目の数)*j<=n,(i番目の数)*(j+1)>nであるようなものの個数 (j<=sqrt(n))
//dp[i+1][0][j]=sum_{l<=j}dp[i][1][l]+sum_l dp[i][0][l]
//dp[i+1][1][j]=(sum_{l<=j}dp[i][0][l])*dp[1][1][j]
//累積和をとると更新を1個当たりO(1)でできる
ll dp11[31624];
ll dp[2][2][31624];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int sqrtn=static_cast<int>(std::sqrt(n));
    for(int j=1;j<=sqrtn;j++){
        dp[1][0][j]=1;
        dp[1][1][j]=n/j-n/(j+1);
    }
    //もしsqrtnがdp[1][1][sqrtn]でカウントされていたら、dp[1][0][sqrtn]ではカウントしない
    if(sqrtn*(sqrtn+1)>n)dp[1][1][sqrtn]=0;
    for(int j=1;j<=sqrtn;j++)dp11[j]=dp[1][1][j];
    for(int i=1;i<k;i++){
        ll psum=0;
        for(int j=1;j<=sqrtn;j++){
            psum+=dp[i%2][0][j];
            psum%=p;
            dp[(i+1)%2][1][j]=psum*dp11[j]%p;
            //printf("%lld ",dp[i+1][1][j]);
        }
        //printf(": ");
        for(int j=sqrtn;j>=1;j--){
            psum+=dp[i%2][1][j];
            psum%=p;
            dp[(i+1)%2][0][j]=psum;
            //printf("%lld ",dp[i+1][0][j]);
        }
        //printf("\n");
    }
    ll ans=0;
    for(int j=1;j<=sqrtn;j++){
        ans+=dp[k%2][0][j]+dp[k%2][1][j];
        ans%=p;
    }
    printf("%lld\n",ans);
    return 0;
}