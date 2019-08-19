#include<cstdio>
//2k+1回の移動でゴールにたどり着くとする（0<=k, 2k+1<=N-1）。
//A,Bを決めたとき、0,A,A-B,2A-B,...,(k+1)A-kBに対してs_yの和を求める
//A-B=Cとおくと、A+kC=N-1なので、0,C,...,kC,N-1,N-1-C,...,N-1-kCの和を求める
//dp[k][C]をこの和とすると、累積和をとって1個あたりO(1)で求められる
//// dp[0][C]=0, dp[k][C]=dp[k-1][C]+s_{kC}+s_{N-1-kC}
using ll = long long;
ll s[100000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",&s[i]);
    //k=0のとき得点はs_0+s_{N-1}=0
    ll max_score=0;
    for(int c=1;c<n;c++){
        ll dp=0;
        for(int k=1;k*c<n;k++){
            //同じ場所を踏んでいないかチェック
            //N-1がCの倍数なら、kC<N-1-kCならOK
            //N-1がCの倍数でないなら、C<N-1-kC(=A)ならOK
            if((n-1)%c==0 && 2*k*c>=n-1 || (n-1)%c!=0 && c*(k+1)>=n-1)break;
            dp+=s[k*c]+s[n-1-k*c];
            if(dp>max_score)max_score=dp;
        }
    }
    printf("%lld\n",max_score);
    return 0;
}