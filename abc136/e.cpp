#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

template<typename ll_t>
vector<pair<ll_t,ll_t>> factorize(ll_t x){
    vector<pair<ll_t,ll_t>> ret; ll_t x_tmp=x, cnt;
    if(x_tmp%2==0) { cnt=0; while(x_tmp%2==0) {x_tmp/=2; ++cnt;} ret.push_back({2,cnt});}
    for(ll_t p=3;x_tmp>1&&p*p<=x;p+=2) if(x_tmp%p==0) { cnt=0; while(x_tmp%p==0) {x_tmp/=p; ++cnt;} ret.push_back({p,cnt});}
    if(x_tmp>1)ret.push_back({x_tmp,1});
    return ret;
}

template<typename ll_t>
vector<ll_t> divisors(ll_t x){
    auto factors=factorize(x); vector<ll_t> ret; ret.push_back(1);
    for(auto &p_s:factors){
        ll_t p=p_s.first, s=p_s.second; vector<ll_t> tmp;
        for(auto &r:ret){ ll_t d=r; for(ll_t i=0;i<=s;++i){ tmp.push_back(d); d*=p; } }
        ret=tmp;}
    sort(ret.begin(),ret.end()); return ret;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n),a_mod_d(n);
    rep(i,n)cin >> a[i];
    auto sum_a=accumulate(a.begin(),a.end(),0);
    int ans=1;
    for(auto &d:divisors(sum_a)){
        rep(i,n)a_mod_d[i]=a[i]%d;
        auto sum_a_mod_d = accumulate(a_mod_d.begin(),a_mod_d.end(),0);
        auto i_larger = n-sum_a_mod_d/d;
        sort(a_mod_d.begin(),a_mod_d.end());
        int k_tmp=0;
        rep(i,n)if(i<i_larger)k_tmp+=a_mod_d[i];
        if(k_tmp<=k)ans=max(ans,d);
    }
    cout << ans << endl;
    return 0;
}