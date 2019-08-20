#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int h[100000];
int main(){
    int n;
    cin >> n;
    rep(i,n)cin >> h[i];
    rep(i,n-2){
        auto ri = n-2-i;
        if(h[ri]>1+h[ri+1]){
            cout << "No" << endl;
            return 0;
        }
        if(h[ri]==1+h[ri+1])h[ri]--;
    }
    cout << "Yes" << endl;
    return 0;
}