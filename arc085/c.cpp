#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
//ネットワークの
template<typename weight_t> using network = vector<vector<pair<int,pair<weight_t,weight_t>>>>;
// @brief 頂点sから頂点tへの(増加フローの容量,経路を表す配列で、p[i]=(iの親の番号))の組をbfsで求める
template<typename weight_t>
pair<weight_t,weight_t> edmonds_karp_bfs(const network<weight_t> &g, int s, int t){

}
// @brief 最大フロー
template<typename weight_t>
weight_t maxflow_edmonds_karp(network<weight_t> &g, int s, int t){

}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i,1,1+n)cin >> a[i];
    for(int i=n;i>0;--i){
        ll sum=0;
        for(int j=1;i*j<=n;++j)sum+=a[i*j];
        if(sum<0)for(int j=1;i*j<=n;++j)a[i*j]=0;
    }
    cout << accumulate(a.begin(),a.end(),0) << endl;
    return 0;
}