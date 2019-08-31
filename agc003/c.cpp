#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    int ans=0;
    rep(i,n)if(i%2!=a[i].second%2)++ans;
    cout << ans/2 << endl;
    return 0;
}