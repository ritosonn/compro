#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    cout << n*(n-1)/2 << endl;
    return 0;
}