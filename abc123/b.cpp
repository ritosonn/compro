#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    ll a[5];
    rep(i,5)cin >> a[i];
    sort(a,a+5,[](ll x,ll y){return (x+9)%10<(y+9)%10;});
    rep(i,5){
        if(i!=0)a[0]+=(a[i]+9)/10*10;
    }
    cout << a[0] << endl;
    return 0;
}