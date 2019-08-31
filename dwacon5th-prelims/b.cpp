#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n*n);
    rep(i,n)cin >> a[i];
    rep(i,n)rep(j,n){
        if(i==j)b[i*n+j]=a[j];
        else if(i<j)b[i*n+j]=b[i*n+j-1]+a[j];
    }
    ll x_max=0;
    for(int i=40;i>=0;--i){
        //もしx_max+(1<<i)が立っているようなb[j]がk個以上あれば、そのk個のandはx_maxの下界
        int cnt=0;
        rep(j,n*n)if(((x_max+(1<<i))&b[j])==(x_max+(1<<i)))++cnt;
        if(cnt>=k)x_max+=(1<<i);
    }
    cout << x_max << endl;
    return 0;
}