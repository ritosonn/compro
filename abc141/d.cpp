#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<int> qu;
    loop(i,n){
        int a;
        cin >> a;
        qu.push(a);
    }
    loop(i,m){
        int a=qu.top();
        qu.pop();
        qu.push(a/2);
    }
    ll sum=0;
    loop(i,n){
        sum+=qu.top();
        qu.pop();
    }
    cout << sum << endl;
    return 0;
}