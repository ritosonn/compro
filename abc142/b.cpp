#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,k,cnt=0;
    cin >> n >> k;
    loop(i,n){
        int h;
        cin >> h;
        if(h>=k)++cnt;
    }
    cout << cnt << endl;

    return 0;
}