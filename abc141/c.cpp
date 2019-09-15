#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> p(n+1,k-q);
    loop(i,q){
        int a;
        cin >> a;
        ++p[a];
    }
    rep(i,1,1+n){
        cout << ((p[i]>0)?"Yes":"No") << endl;
    }
    return 0;
}