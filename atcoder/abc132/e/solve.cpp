#include<cstdio>
#include<vector>
#include<queue>
using graph=std::vector<std::vector<int>>;
constexpr int infty=1e8;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    graph g(3*n+1);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(n+v);
        g[n+u].push_back(2*n+v);
        g[2*n+u].push_back(v);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    std::queue<int> qu;
    std::vector<int> visited(300001,infty);
    qu.push(s);
    visited[s]=0;
    while(!qu.empty()){
        int u=qu.front();
        qu.pop();
        for(auto &v:g[u]){
            if(visited[v]>visited[u]+1){
                visited[v]=visited[u]+1;
                qu.push(v);
            }
        }
    }
    if(visited[t]==infty)printf("-1\n");
    else printf("%d\n",visited[t]/3);
    return 0;
}