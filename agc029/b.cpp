#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
//n+f(n)が2べき、n>=f(n)
ll f(const ll n){
    ll ret=1,n_tmp=n;
    while(n_tmp>0){ret<<=1;n_tmp>>=1;}
    return ret-n;
}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    multiset<ll> s;
    rep(i,n){
        cin >> a[i];
        s.emplace(a[i]);
    }
    sort(a.begin(),a.end(),greater<ll>());
    int ans=0;
    rep(i,n){
        auto itr=s.find(a[i]);
        if(itr==s.end())continue;
        s.erase(itr);
        itr=s.find(f(a[i]));
        if(itr==s.end())continue;
        s.erase(itr);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}