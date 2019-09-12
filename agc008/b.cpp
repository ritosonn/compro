#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
ll sum_a[100001],sum_aplus[100001];
int main(){
    int n,k;
    cin >> n >> k;
    sum_a[0]=0;
    sum_aplus[0]=0;
    loop(i,n){
        ll a;
        scanf("%lld",&a);
        sum_a[i+1]=sum_a[i]+a;
        sum_aplus[i+1]=sum_aplus[i]+max(a,0LL);
    }
    ll ans=0;
    loop(i,n-k+1){
        //i,i+1,...,i+k-1は同じ色で塗る
        ll tmp1=max(0LL,sum_a[i+k]-sum_a[i]);
        //0,...,i-1とi+k,...,n-1は任意の色で塗る
        ll tmp2=sum_aplus[i]+sum_aplus[n]-sum_aplus[i+k];
        ans=max(ans,tmp1+tmp2);
    }
    cout << ans << endl;
    return 0;
}