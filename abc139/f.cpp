#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    vector<double> theta(n);
    rep(i,n){
        cin >> x[i] >> y[i];
        ll len=x[i]*x[i]+y[i]*y[i];
        if(len==0||(y[i]==0&&x[i]>0))theta[i]=0;
        else if(y[i]==0&&x[i]<0)theta[i]=M_PI;
        else theta[i]=(y[i]>0?1:-1)*acos(x[i]/sqrt(len));
    }
    ll ans_sq=0;
    rep(i,n)rep(j,n){
        double theta_min=min(theta[i],theta[j]), theta_max=max(theta[i],theta[j]);
        ll tmp_x=0,tmp_y=0;
        rep(k,n)if(theta_min<=theta[k]&&theta[k]<=theta_max){
            tmp_x+=x[k];
            tmp_y+=y[k];
        }
        ans_sq=max(ans_sq,tmp_x*tmp_x+tmp_y*tmp_y);
        tmp_x=0,tmp_y=0;
        rep(k,n)if(theta_min>=theta[k]||theta[k]>=theta_max){
            tmp_x+=x[k];
            tmp_y+=y[k];
        }
        ans_sq=max(ans_sq,tmp_x*tmp_x+tmp_y*tmp_y);
    }
    cout << setprecision(20) << sqrt((double)ans_sq) << endl;
    return 0;
}