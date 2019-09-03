#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    string s;
    cin >> s;
    int n=s.size();
    int l=n/2,r=n/2;
    while(l>=0 && s[l]==s[n/2])--l;
    while(r<n && s[r]==s[n/2])++r;
    cout << min(n-1-l,r) << endl;
    return 0;
}