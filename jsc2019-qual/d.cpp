#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp=j-i;
            int ret=1;
            while(tmp%2==0){
                tmp/=2;
                ++ret;
            }
            cout << ret << ((j==n)?"\n":" ");
        }
    }
    return 0;
}