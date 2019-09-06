#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n),s(n+1);
    rep(i,n)cin >> a[i];
    s[0]=0;
    rep(i,n)s[i+1]=s[i]+a[i];
    ll min_diff=1e15;
    rep(i,n){
        //[0,i)を二等分
        int l=0,r=i;
        while(r-l>1){
            int m=(l+r)/2;
            if(s[m]*2>s[i])r=m;
            else l=m;
        }
        ll b_sum[2]={s[l],s[r]},c_sum[2]={s[i]-s[l],s[i]-s[r]};
        //[i,n)を二等分
        l=i;
        r=n;
        while(r-l>1){
            int m=(l+r)/2;
            if((s[m]-s[i])*2>s[n]-s[i])r=m;
            else l=m;
        }
        ll d_sum[2]={s[l]-s[i],s[r]-s[i]},e_sum[2]={s[n]-s[l],s[n]-s[r]};
        rep(j,2)rep(k,2){
            ll sum_all[4]={b_sum[j],c_sum[j],d_sum[k],e_sum[k]};
            sort(sum_all,sum_all+4);
            min_diff=min(min_diff,sum_all[3]-sum_all[0]);
        }
    }
    cout << min_diff << endl;
    return 0;
}