#include<vector>
#include<cstdint>
#include<limits>
#include<queue>
#include<cstdio>

using to_t = std::size_t;
using ll = std::int64_t;

struct node {
    to_t to;
};
using graph = std::vector<std::vector<node>>;

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

ll ext_gcd(ll a,ll b,ll &x,ll &y){
    //b==0ならa*1+b*0=a
    if(b==0){x=1;y=0;return a;}
    ll q=a/b, g=ext_gcd(b,a-q*b,x,y), z=x-q*y;
    x=y; y=z;
    return g;
}

ll inv(ll a,ll p){
    ll x,y;
    ext_gcd(a,p,x,y);
    return (x+p)%p;
}

//x[i]=i*(i-1)*...*2*1
void make_factorial(ll *x, int len, ll p){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*i)%p;
}

ll npr(ll n,ll r,ll *fct,ll p){
    if(n<0||n<r||r<0)return 0;
    return fct[n]*inv(fct[n-r],p)%p;
}

ll fct[100000];
constexpr ll p=1e9+7;

int main(){
    //input
    int n,k;
    scanf("%d%d",&n,&k);
    graph g(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a-1].push_back({(b-1)});
        g[b-1].push_back({(a-1)});
    }
    auto g_add=add_orientation(g);
    make_factorial(fct,100000,p);
    //根から順番に決める
    std::queue<to_t> qu;
    //根の塗り方はk通り
    ll ans=k;
    //根に直でつながっている子はg_add[0].size()個で、それらは根と異なる色(k-1通り)を塗る
    for(auto &i:g_add[0]){
        qu.push(i.to);
    }
    ans=ans*npr(k-1,g_add[0].size(),fct,p)%p;
    //そのほかは、g_add[i].size()個の子に、自分ともその親とも異なる色(k-2通り)を塗る
    while(!qu.empty()){
        auto i=qu.front();
        qu.pop();
        for(auto &j:g_add[i]){
            qu.push(j.to);
        }
        ans=(ans*npr(k-2,g_add[i].size(),fct,p))%p;
    }
    printf("%lld\n",ans);
    return 0;
}