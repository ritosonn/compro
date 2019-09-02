#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int a[1001][999];

using weighted_graph = vector<vector<pair<int,ll>>>;
using unweighted_graph = vector<vector<int>>;
bool visit_dag(int n, const unweighted_graph &g, vector<int> &mark, vector<int> &l){
    if(mark[n]==1)return false; else if(mark[n]==0){ mark[n]=1; for(auto &m:g[n])if(!visit_dag(m,g,mark,l))return false; mark[n]=2; l.push_back(n); } return true; }
vector<int> topological_sort(const unweighted_graph &g){
    vector<int> mark(g.size(),0),l; rep(i,g.size())if(mark[i]==0&&!visit_dag(i,g,mark,l))return {}; reverse(l.begin(),l.end()); return l; }
bool is_dag(const unweighted_graph &g){ return !topological_sort(g).empty(); }
unweighted_graph inverse(const unweighted_graph &g){
    unweighted_graph h(g.size()); rep(i,g.size())rep(j,g[i].size())h[g[i][j]].push_back(i); return h; }
int longest_path_dag(const unweighted_graph &g){
    auto l=topological_sort(g); if(l.empty())return -1;
    auto h=inverse(g); vector<int> dist(g.size(),1);
    rep(i,g.size())rep(j,h[l[i]].size())dist[l[i]]=max(dist[l[i]],1+dist[h[l[i]][j]]);
    return *max_element(dist.begin(),dist.end()); }

int f(int a,int b,int n){
    return (a<b)?(b*(b-1)/2+a-b):f(b,a,n);
}
int main(){
    int n;
    cin >> n;
    rep2(i,1,n+1)rep(j,n-1)cin >> a[i][j];
    unweighted_graph g(n*(n-1)/2);
    rep2(i,1,n+1)rep(j,n-2)g[f(i,a[i][j],n)].push_back(f(i,a[i][j+1],n));
    cout << longest_path_dag(g) << endl;
    return 0;
}