#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll cnt=0;
    rep(i,n)cnt+=a[i]/(n+1);
    rep(i,n)a[i]%=(n+1);
    ll remain = min((ll)n,cnt);
    rep(i,n)a[i]+=remain;
    cnt+=(cnt-remain)*n;
    while(true){
        auto m=max_element(a.begin(),a.end());
        if(*m<n)break;
        for(auto itr=a.begin();itr!=a.end();++itr){
            if(m==itr)*itr-=n;
            else (*itr)++;
        }
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}