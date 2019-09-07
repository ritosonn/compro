#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> p(n+1),inv_p(n+1);
    rep2(i,1,n+1)cin >> p[i];
    rep2(i,1,n+1)inv_p[p[i]]=i;
    multiset<int> s;
    s.emplace(0);
    s.emplace(n+1);
    s.emplace(0);
    s.emplace(n+1);
    ll sum=0;
    for(int i=n;i>0;--i){
        //...p[a]...p[b]...p[i]...p[c]...p[d]...
        auto itr=s.lower_bound(inv_p[i]);
        ll c=*itr;
        ++itr;
        ll d=*itr;
        --itr;
        --itr;
        ll b=*itr;
        --itr;
        ll a=*itr;
        sum+=((b-a)*(c-inv_p[i])+(inv_p[i]-b)*(d-c))*i;
        s.emplace(inv_p[i]);
    }
    cout << sum << endl;
    return 0;
}