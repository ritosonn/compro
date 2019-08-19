#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    int cnt=0;
    rep(i,10)if(i>=1 && i<=n)cnt++;
    rep(i,1000)if(i>=100 && i<=n)cnt++;
    rep(i,100000)if(i>=10000 && i<=n)cnt++;
    cout << cnt << endl;
    return 0;
}