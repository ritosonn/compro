#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    int a[5],k;
    rep(i,5)cin >> a[i];
    cin >> k;
    if(a[4]-a[0]>k)cout << ":(" << endl;
    else cout << "Yay!" << endl;
    return 0;
}