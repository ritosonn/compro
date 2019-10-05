#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    if(n%2==0)cout << 0.5 << endl;
    else cout << setprecision(20) << 1-1.0*(n/2)/n << endl;
    return 0;
}