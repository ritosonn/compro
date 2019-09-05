#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int r=0,sum=0;
    ll ans=0;
    rep(l,n){
        while(r<n&&(sum+a[r]==(sum^a[r]))){
            sum+=a[r];
            ++r;
        }
        ans+=r-l;
        sum^=a[l];
    }
    cout << ans << endl;
    return 0;
}