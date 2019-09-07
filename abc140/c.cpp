#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> b(n-1),a(n);
    rep(i,n-1)cin >> b[i];
    a[0]=b[0];
    rep2(i,1,n-1)a[i]=min(b[i-1],b[i]);
    a[n-1]=b[n-2];
    cout << accumulate(a.begin(),a.end(),0LL) << endl;
    return 0;
}