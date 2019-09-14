#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1,0);
    rep(i,1,1+n)cin >> a[i];
    int cnt=0;
    for(int i=n;i>0;--i){
        int tmp=a[i];
        int j=2*i;
        while(j<=n){
            tmp^=b[j];
            j+=i;
        }
        b[i]=tmp;
        cnt+=tmp;
    }
    cout << cnt << endl;
    rep(i,1,1+n)if(b[i]>0)cout << i << " ";
    return 0;
}