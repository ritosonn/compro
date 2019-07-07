#include<vector>
#include<cstdint>
#include<limits>
#include<queue>
#include<stack>

using to_t = std::size_t;
using weight_t = std::int64_t;
constexpr weight_t weight_infty = std::numeric_limits<weight_t>::max();

struct node {
    to_t to;
    weight_t weight;
    //weight_t capacity,flow; //for network algorithms
    //node *inv; //for network algorithms
};
using graph = std::vector<std::vector<node>>;

graph reverse(const graph &g){
    graph h(g.size());
    for(std::size_t i=0;i<g.size();i++){
        for(auto &v:g[i]){
            auto w(v);
            w.to=i;
            h[v.to].push_back(w);
        }
    }
    return h;
}

graph add_orientation(const graph &g, const to_t e=0){
    graph h(g.size());
    std::queue<to_t> qu;
    std::vector<bool> is_visited(g.size(),false);
    qu.push(e);
    is_visited[e]=true;
    while(!qu.empty()){
        to_t a=qu.front();
        qu.pop();
        for(auto &v:g[a]){
            if(!is_visited[v.to]){
                is_visited[v.to]=true;
                h[a].push_back(v);
                qu.push(v.to);
            }
        }
    }
    return h;
}

void bfs(const graph &g,const to_t e){
    std::queue<to_t> qu; //bfs
    //std::stack<to_t> qu; //dfs

    std::vector<bool> is_visited(g.size(),false);
    qu.push(e);
    while(!qu.empty()){
        auto v=qu.front();
        qu.pop();
        if(!is_visited[v]){
            is_visited[v]=true;
            //pointwise computation

            for(auto &w:g[v]){
                qu.push(w.to);
            }
        }
    }
}

std::vector<weight_t> dijkstra(const graph &g,const to_t e){
    auto cmp=[](node &a,node &b)->bool {return (a.weight>b.weight);};
    std::priority_queue<node,std::vector<node>,decltype(cmp)> pq(cmp);
    std::vector<weight_t> w(g.size(),weight_infty);
    pq.push({e,0});
    w[e]=0;
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(auto &v:g[u.to]){
            if(w[u.to]+v.weight<w[v.to]){
                w[v.to]=w[u.to]+v.weight;
                pq.push({v.to,w[v.to]});
            }
        }
    }
    return w;
}

std::vector<to_t> shortest_path(const graph &g,const to_t start,const to_t goal){
    const auto h=reverse(g);
    const auto w=dijkstra(h,goal);
    if(w[start]==weight_infty)return {};
    std::vector<to_t> path;
    to_t i=start;
    while(i!=goal){
        path.push_back(i);
        for(auto &v:g[i]){
            if(w[v.to]==w[i]-v.weight){
                i=v.to;
                break;
            }
        }
    }
    path.push_back(goal);
    return path;
}

