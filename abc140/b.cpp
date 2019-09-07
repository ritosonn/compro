#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n-1)cin >> c[i];
    int sum=0;
    rep(i,n){
        sum+=b[a[i]-1];
        if(i<n-1&&a[i]+1==a[i+1])sum+=c[a[i]-1];
    }
    cout << sum << endl;
    return 0;
}