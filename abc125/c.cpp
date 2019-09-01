#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
template<typename T> T gcd_(T a,T b){ return (a%b)?gcd_(b,a%b):b; }
int main(){
    int n;
    cin >> n;
    vector<int> a(n),l(n),r(n),g(n);
    rep(i,n)cin >> a[i];
    l[0]=a[0];
    for(int i=1;i<n;++i)l[i]=gcd_(l[i-1],a[i]);
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;--i)r[i]=gcd_(r[i+1],a[i]);
    g[0]=r[1];
    g[n-1]=l[n-2];
    for(int i=1;i<n-1;++i)g[i]=gcd_(l[i-1],r[i+1]);
    cout << *max_element(g.begin(),g.end()) << endl;
    return 0;
}