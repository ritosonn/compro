#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> p(n),dp(n+1);
    rep(i,n)cin >> p[i];
    int ans=0;
    rep(i,n){
        dp[p[i]]=dp[p[i]-1]+1;
        ans=max(ans,dp[p[i]]);
    }
    cout << n-ans << endl;
    return 0;
}