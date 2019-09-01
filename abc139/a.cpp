#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    string s,t;
    cin >> s >> t;
    int cnt=0;
    rep(i,3)if(s[i]==t[i])cnt++;
    cout << cnt << endl;
    return 0;
}