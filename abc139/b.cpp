#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int a,b;
    cin >> a >> b;
    int cnt=0, tap=1;
    while(tap<b){
        tap+=a-1;
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}