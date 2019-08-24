#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    int m,d,cnt=0;
    cin >> m >> d;
    rep(i,m+1)rep(j,d+1){
        if(i==0||j%10<=1||j/10<=1)continue;
        if(i==(j/10)*(j%10))++cnt;
    }
    cout << cnt << endl;
    return 0;
}