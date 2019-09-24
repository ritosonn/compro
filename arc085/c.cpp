#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
template<typename capacity_t> class MaxFlow{
    struct edge { int to,rev; capacity_t cap; }; int v; vector<vector<edge>> G; vector<int> itr, level;
    void bfs(int s){ level.assign(v,-1); queue<int> q; level[s]=0; q.push(s);
        while(!q.empty()){ int v=q.front(); q.pop();
            for(auto &e: G[v]) if(e.cap>0 && level[e.to]<0){ level[e.to]=level[v]+1; q.push(e.to); }}}
    capacity_t dfs(int v, int t, capacity_t f) { if(v==t)return f;
        for(int& i=itr[v]; i<(int)G[v].size();++i){ edge& e=G[v][i];
            if(e.cap>0 && level[v]<level[e.to]){ capacity_t d=dfs(e.to,t,min(f,e.cap));
                if(d>0){ e.cap-=d; G[e.to][e.rev].cap+=d; return d; }}}
        return 0;
    }
public:
    MaxFlow(int v):v(v){G.assign(v,vector<edge>());}
    void add_edge(int from, int to, capacity_t cap){ assert(cap>=0);
        G[from].push_back((edge){to,(int)G[to].size(),cap});
        G[to].push_back((edge){from,(int)G[from].size()-1,0}); }
    capacity_t run(int s,int t){ capacity_t ret=0, f;
        while(bfs(s), level[t]>=0){ itr.assign(v,0); while((f=dfs(s,t,numeric_limits<capacity_t>::max()))>0) ret+=f;}
        return ret;
    }
};
/**
 * グラフの頂点を(白,黒)の2値に分類するタスクで
 * 「頂点iが白、頂点jが黒なら罰金k円」の形で与えられた罰金を最小化する問題
 *  -> 最小カット = 最大流
 * 
 * 今回は、白<=>割られた、黒<=>割られていない、の2値分類
 * - iが割られるならc*iも割られる <=> i->c*i に罰金 INF 円
 * - iが割られるなら a[i]<=0 円もらえる <=> 0->i に罰金 -a[i] 円
 * - iが割られるなら a[i]>0 円もらえる <=> iが割られないなら罰金 a[i] 円 <=> i->n+1 に罰金 a[i] 円
 * と定義したグラフの最小カット = 最大流が答え
 */
int main(){
    int n;
    cin >> n;
    MaxFlow<ll> flow(n+2);
    ll ans=0;
    rep(i,1,1+n){
        ll a;
        cin >> a;
        if(a<=0)flow.add_edge(0,i,-a);
        else{
            flow.add_edge(i,n+1,a);
            ans+=a;
        }
    }
    rep(i,1,1+n){
        for(int j=2;i*j<=n;++j){
            flow.add_edge(i,i*j,numeric_limits<ll>::max());
        }
    }
    cout << ans-flow.run(0,n+1) << endl;
    return 0;
}