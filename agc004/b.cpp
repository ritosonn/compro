#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
using namespace std;
using ll = long long;
ll b[2000][2000];
int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,0,n)cin >> a[i];
    //b[i][k]=k回魔法を唱えてスライムiを手に入れるための最小の時間-k*x
    //       =min(a_i, ..., a_{i-k})
    //       =min(b[i][k-1],a_{i-k})
    rep(i,0,n){
        b[i][0]=a[i];
        rep(k,1,n)b[i][k]=min(b[i][k-1],a[(i-k+n)%n]);
    }
    ll ans=1e15;
    rep(k,0,n){
        ll tmp=k*x;
        rep(i,0,n)tmp+=b[i][k];
        ans=min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}