#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    loop(i,h){
        loop(j,w){
            if((i<b)==(j<a))cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
    return 0;
}