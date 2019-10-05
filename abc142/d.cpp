#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
template<typename T> T gcd_(T a,T b){ return (a%b)?gcd_(b,a%b):b; }
template<typename ll_t>
vector<pair<ll_t,ll_t>> factorize(ll_t x){
    vector<pair<ll_t,ll_t>> ret; ll_t x_tmp=x, cnt;
    if(x_tmp%2==0) { cnt=0; while(x_tmp%2==0) {x_tmp/=2; ++cnt;} ret.push_back({2,cnt});}
    for(ll_t p=3;x_tmp>1&&p*p<=x;p+=2) if(x_tmp%p==0) { cnt=0; while(x_tmp%p==0) {x_tmp/=p; ++cnt;} ret.push_back({p,cnt});}
    if(x_tmp>1)ret.push_back({x_tmp,1});
    return ret;
}
int main(){
    ll a,b;
    cin >> a >> b;
    auto factors = factorize(gcd_(a,b));
    cout << factors.size()+1 << endl;
    return 0;
}