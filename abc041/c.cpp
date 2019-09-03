#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    rep(i,n){
        int a;
        cin >> a;
        vp.push_back({i+1,a});
    }
    sort(vp.begin(),vp.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.second>b.second; });
    cout << endl;
    rep(i,n)cout << vp[i].first << endl;
    return 0;
}