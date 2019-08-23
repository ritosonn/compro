#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using cand_t = pair<char,pair<ll,ll>>;
ll d_l1(pair<ll,ll> a,pair<ll,ll> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
void arm(pair<ll,ll> p_start,pair<ll,ll> p_end,ll dist){
    if(dist==0&&p_start==p_end){
        cout << endl;
        return;
    }
    if(dist<1)dist=1;
    vector<cand_t> candidate;
    candidate.push_back({'L',{p_start.first-dist,p_start.second}});
    candidate.push_back({'R',{p_start.first+dist,p_start.second}});
    candidate.push_back({'D',{p_start.first,p_start.second-dist}});
    candidate.push_back({'U',{p_start.first,p_start.second+dist}});
    std::sort(candidate.begin(),candidate.end(),[&](cand_t a,cand_t b){return d_l1(p_end,a.second)<d_l1(p_end,b.second);});
    cout << candidate[0].first;
    arm(candidate[0].second,p_end,dist/2);
}
int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> xy;
    bool is_even;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        if(i==0)is_even=((x+y)%2==0);
        else if(is_even!=((x+y)%2==0)){
            cout << -1 << endl;
            return 0;
        }
        xy.push_back({x,y});
    }
    cout << 33 + (is_even?1:0) << endl;
    rep(i,33) cout << (1LL<<(32-i)) << " ";
    if(is_even) cout << 1;
    cout << endl;
    rep(i,n)arm({0,0},xy[i],1LL<<32);
    return 0;
}