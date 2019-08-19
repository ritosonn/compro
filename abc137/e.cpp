#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using ll = long long;
struct node {
    ll to;
    ll weight;
};
using graph = std::vector<std::vector<node>>;
constexpr ll infty=-1e15;
void reachable(const graph &g, int s, bool flg[]){
    std::queue<int> qu;
    for(int i=0;i<(int)g.size();i++)flg[i]=false;
    qu.push(s);
    while(!qu.empty()){
        int i=qu.front();
        qu.pop();
        if(flg[i])continue;
        flg[i]=true;
        for(auto &v:g[i]){
            if(flg[v.to])continue;
            qu.push(v.to);
        }
    }
}
bool from_start[2500];
bool to_goal[2500];
bool relaxing(const graph &g, ll l[]){
    bool relaxed=false;
    for(int i=0;i<(int)g.size();i++){
        if(l[i]==infty || !from_start[i] || !to_goal[i])continue;
        for(int j=0;j<(int)g[i].size();j++){
            if(l[g[i][j].to]<l[i]+g[i][j].weight){
                l[g[i][j].to]=l[i]+g[i][j].weight;
                relaxed=true;
            }
        }
    }
    return relaxed;
}
ll l[2500];
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    graph g(n);
    graph g_rev(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a-1].push_back({b-1,c-p});
        g_rev[b-1].push_back({a-1,1});
    }
    reachable(g,0,from_start);
    reachable(g_rev,n-1,to_goal);
    for(int i=0;i<n;i++)l[i]=infty;
    l[0]=0;
    for(int cnt=0;cnt<=m;cnt++){
        if(!relaxing(g,l))break;
    }
    if(relaxing(g,l)){
        printf("-1\n");
    }else{
        printf("%lld\n",std::max(0LL,l[n-1]));
    }
    return 0;
}