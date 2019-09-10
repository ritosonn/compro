#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
template<typename weight_t> using graph = vector<vector<pair<int,weight_t>>>;
int main(){
    int n,m;
    cin >> n >> m;
    graph<int> g(n);
    loop(i,m){
        int a,b;
        cin >> a >> b;
        g[a-1].push_back({b-1,1});
        g[b-1].push_back({a-1,1});
    }
    int itr=0;
    while(g[itr].empty())++itr;
    int jtr=g[itr][0].first;
    deque<int> path;
    path.push_front(itr);
    path.push_back(jtr);
    vector<bool> used(n,false);
    used[itr]=true;
    used[jtr]=true;
    while((int)path.size()<n){
        int new_itr=0;
        while(new_itr<(int)g[itr].size()&&used[g[itr][new_itr].first])++new_itr;
        if(new_itr==(int)g[itr].size())break;
        itr=g[itr][new_itr].first;
        path.push_front(itr);
        used[itr]=true;
    }
    while((int)path.size()<n){
        int new_jtr=0;
        while(new_jtr<(int)g[jtr].size()&&used[g[jtr][new_jtr].first])++new_jtr;
        if(new_jtr==(int)g[jtr].size())break;
        jtr=g[jtr][new_jtr].first;
        path.push_back(jtr);
        used[jtr]=true;
    }
    cout << path.size() << endl;
    while(!path.empty()){
        cout << path.front()+1;
        path.pop_front();
        if(!path.empty())cout << " ";
    }
    cout << endl;
    return 0;
}