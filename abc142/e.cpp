#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
//dp[i][j]={鍵1,...,iを用いて宝箱j(bitsetで管理)を開けるための費用の最小値}
constexpr int n_max = 12, m_max = 1000;
int dp[m_max+1][1<<n_max];
constexpr int infty = 1e9;
int main(){
    int n,m;
    cin >> n >> m;
    loop(i,1+m){
        loop(j,1<<n){
            dp[i][j]=infty;
        }
    }
    dp[0][0]=0;
    rep(i,1,1+m){
        int a,b,key=0;
        cin >> a >> b;
        loop(j,b){
            int c;
            cin >> c;
            key|=(1<<(c-1));
        }
        loop(j,1<<n)dp[i][j]=dp[i-1][j];
        loop(j,1<<n){
            dp[i][j|key]=min(dp[i][j|key],min(dp[i-1][j|key],dp[i-1][j]+a));
        }
    }
    if(dp[m][(1<<n)-1]==infty)cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
    return 0;
}