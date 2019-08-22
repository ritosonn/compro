#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
constexpr ll traffic=5;
int main(){
    ll n,a[traffic];
    cin >> n;
    rep(i,traffic)cin >> a[i];
    auto min_a = *min_element(a,a+traffic);
    cout << (n+min_a-1)/min_a+traffic-1 << endl;
    return 0;
}