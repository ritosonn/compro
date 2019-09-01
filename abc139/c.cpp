#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n)cin >> h[i];
    int ans=0,cnt=0;
    rep(i,n-1){
        if(h[i]>=h[i+1])++cnt;
        else{
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    ans=max(ans,cnt);
    cout << ans << endl;
    return 0;
}