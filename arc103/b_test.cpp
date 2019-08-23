#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
pair<ll,ll> times(pair<ll,ll> p,ll x){
    return {x*p.first,x*p.second};
}
pair<ll,ll> plus_vect(pair<ll,ll> p,pair<ll,ll> q){
    return {p.first+q.first,p.second+q.second};
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> d(m);
    rep(i,m)cin >> d[i];
    unordered_map<char,pair<ll,ll>> umap={{'L',{-1,0}},{'R',{1,0}},{'U',{0,1}},{'D',{0,-1}}};
    rep(i,n){
        string w;
        cin >> w;
        pair<ll,ll> coord={0,0};
        rep(j,(int)w.size()){
            coord=plus_vect(coord,times(umap[w[j]],d[j]));
        }
        cout << coord.first << " " << coord.second << endl;
    }
    return 0;
}