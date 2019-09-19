#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
template<typename weight_t> using graph = vector<vector<pair<int,weight_t>>>;
bool dfs(const graph<int> &g,const vector<int> &x,vector<int> &val,const int i=1){
    //st[i]=iを和として実現できるか
    bitset<5001> st;
    st[0]=1;
    //子をすべて調べる
    loop(itr,g[i].size()){
        int j=g[i][itr].first;
        if(j<i)continue;//親
        if(!dfs(g,x,val,j))return false;
        //x[j]かval[j]をそれぞれの子について足し合わせる必要がある
        st=(st<<x[j])|(st<<val[j]);
    }
    //st[x[i]],st[x[i-1]],...,st[0]のうち最初に実現できる（st[k]==1となる）kを取る
    int k=x[i];
    while(k>=0&&st[k]==0)--k;
    if(k<0)return false;
    //このときsum_{j:iの子}(x[j]とval[j]の適切な方をひとつ)=k なので、
    //（選ばなかった方の和）= sum_{j:iの子}(x[j]+val[j])-k がなりたち、これが最小である。
    //つまり、x[i]-kを頂点iに書けば条件を満たすことができ、val[i]=sum_{j:iの子}(x[j]+val[j])-k
    int sum=-k;
    loop(itr,g[i].size()){
        int j=g[i][itr].first;
        if(j<i)continue;//親
        sum+=x[j]+val[j];
    }
    val[i]=sum;
    return true;
}
int main(){
    int n;
    cin >> n;
    graph<int> g(n+1);
    vector<int> x(n+1);
    rep(i,2,n+1){
        int p;
        cin >> p;
        g[i].push_back({p,1});
        g[p].push_back({i,1});
    }
    rep(i,1,n+1)cin >> x[i];
    //val[j]=(自分と違う色の子が持っている数の和の最小値)
    vector<int> val(n+1);
    cout << (dfs(g,x,val)?"POSSIBLE":"IMPOSSIBLE") << endl;
    return 0;
}