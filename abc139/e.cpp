#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int a[1001][999];

template<typename Edge>
using graph = vector<vector<Edge>>;



int main(){
    int n;
    cin >> n;
    rep2(i,1,n+1)rep(j,n-1)cin >> a[i][j];
    int days;

    cout << days << endl;
    return 0;
}