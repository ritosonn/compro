#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
class UnionFind{
    int l_, cnt_, *parent_, *rank_;
public:
    UnionFind(int l):l_(l),cnt_(l){ parent_=new int[l]; rep(i,l)parent_[i]=-1; rank_=new int[l]; rep(i,l)rank_[i]=0; }
    ~UnionFind(){ delete[] parent_; delete[] rank_; }
    int root(int x){ return (parent_[x]<0)?x:(parent_[x]=root(parent_[x])); }
    void unite(int x,int y){ int rx=root(x),ry=root(y); if(rx!=ry){ --cnt_;
        if(rank_[rx]>rank_[ry]){ parent_[rx]+=parent_[ry]; parent_[ry]=rx; }
        else{ if(rank_[rx]==rank_[ry])++rank_[ry]; parent_[ry]+=parent_[rx]; parent_[rx]=ry; }}}
    bool isSameTree(int x,int y){ return root(x)==root(y); }
    int sizeOf(int x){ return -parent_[root(x)]; }
    int count_component(){ return cnt_; }
};
int main(){
    int n,m,lack_edge;
    cin >> n >> m;
    lack_edge=n-1-m;
    if(lack_edge==0){
        cout << 0 << endl;
        return 0;
    }
    if(n<2*lack_edge){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    UnionFind uf(n);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        uf.unite(x,y);
    }
    vector<vector<pair<int,int>>> connected_components(n);
    rep(i,n)connected_components[uf.root(i)].push_back({a[i],i});
    rep(i,n)sort(connected_components[i].begin(),connected_components[i].end());
    ll ans=0;
    vector<int> rest;
    rep(i,n){
        for(auto itr=connected_components[i].begin();itr!=connected_components[i].end();++itr){
            if(itr==connected_components[i].begin())ans+=(*itr).first;
            else rest.push_back((*itr).first);
        }
    }
    sort(rest.begin(),rest.end());
    rep(i,2*lack_edge-(n-m))ans+=rest[i];
    cout << ans << endl;
    return 0;
}