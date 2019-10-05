#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    loop(i,n){
        int a;
        cin >> a;
        vp[i]={a,i+1};
    }
    sort(vp.begin(),vp.end());
    loop(i,n){
        cout << vp[i].second << (i==n-1?"\n":" ");
    }
    return 0;
}