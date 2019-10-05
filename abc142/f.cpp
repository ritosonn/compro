#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define loop(i, n) rep(i, 0, n)
using namespace std;
using ll = long long;
class findLoop
{
public:
    int max_len;
private:
    int v;
    vector<vector<int>> G;
    vector<int> bfs(int i)
    {
        queue<int> q;
        vector<int> d(v,numeric_limits<int>::max()), last(v,-1);
        d[i]=0;
        q.push(i);
        int rev=-1;
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            for(const auto &w: G[v]){
                if(d[w]>d[v]+1){
                    d[w]=d[v]+1;
                    last[w]=v;
                    q.push(w);
                }
            }
        }
        return {};
    }

public:
    findLoop(int v) : v(v) { G.assign(v, vector<int>()); }
    void add_edge(int from, int to) { G[from].push_back(to); }
    vector<int> run()
    {
        loop(i, v)
        {
            auto path = bfs(i);
            if (!path.empty())
            {
                reverse(path.begin(), path.end());
                return path;
            }
        }
        return {};
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    findLoop G(n + 1);
    G.max_len=n;
    loop(i, m)
    {
        int a, b;
        cin >> a >> b;
        G.add_edge(a, b);
    }
    auto l = G.run();
    if (G.run().empty())
    {
        cout << -1 << endl;
        return 0;
    }

    int l_size_min = 1, l_size_max = l.size();
    while(l_size_max-l_size_min>1){
        int mid = (l_size_min+l_size_max)/2;
        G.max_len=mid;
        if(G.run().empty())l_size_min=mid;
        else l_size_max=mid;
    }
    G.max_len=l_size_min;
    l=G.run();
    if(l.empty()){
        G.max_len=l_size_max;
        l=G.run();
    }
    cout << l.size() << endl;
    for (const auto &i : l)
    {
        cout << i << endl;
    }
    return 0;
}