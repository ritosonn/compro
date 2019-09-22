#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,z,w;
    cin >> n >> z >> w;
    vector<int> a(n);
    loop(i,n)cin >> a[i];
    //最初に先手が全部取るとスコアは |a[n-2]-w| 点になり、1枚残すと |a[n-2]-a[n-1]| 点なので、スコアはこの2つのmax以上
    //最初に先手が2枚以上残すと、後手は最後から2番目を取って |a[n-2]-a[n-1]| 点にできるので、スコアは |a[n-1]-a[n]| 点以下
    if(n==1)cout << abs(a[0]-w) << endl;
    else cout << max(abs(a[n-1]-w),abs(a[n-1]-a[n-2])) << endl;
    return 0;
}