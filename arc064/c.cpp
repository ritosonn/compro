#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
template<typename weight_t> using graph = vector<vector<pair<int,weight_t>>>;
template<typename weight_t> vector<weight_t> dijkstra(const graph<weight_t> &g,const int e){
    using node=pair<int,weight_t>; auto cmp=[](node &a,node &b)->bool {return (a.second>b.second);};
    priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);
    vector<weight_t> w(g.size(),numeric_limits<weight_t>::max());
    vector<bool> done(g.size(),false); pq.push({e,0}); w[e]=0;
    while(!pq.empty()){ auto u=pq.top(); pq.pop(); if(done[u.first])continue; done[u.first]=true;
        for(auto &v:g[u.first]) if(w[u.first]+v.second<w[v.first]){
            w[v.first]=w[u.first]+v.second; pq.push({v.first,w[v.first]}); }}
    return w;
}

int main(){
    double xs,ys,xt,yt;
    int n;
    cin >> xs >> ys >> xt >> yt >> n;
    vector<double> x(n+2),y(n+2),r(n+2);
    x[0]=xs;
    y[0]=ys;
    x[1]=xt;
    y[1]=yt;
    rep(i,2,n+2){
        cin >> x[i] >> y[i] >> r[i];
    }
    graph<double> g(n+2);
    auto dist = [&](double xi,double yi,double xj,double yj)->double{
        return sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));};
    loop(i,n+1)rep(j,i+1,n+2){
        double d=max(0.0,dist(x[i],y[i],x[j],y[j])-r[i]-r[j]);
        g[i].push_back({j,d});
        g[j].push_back({i,d});
    }
    auto ans=dijkstra(g,0);
    cout << setprecision(10) << ans[1] << endl;
    return 0;
}