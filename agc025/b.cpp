#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
template<typename ll_t,ll_t mod>
class basic_modint{
public:
    ll_t x_;
    basic_modint(ll_t x=0):x_((x%mod+mod)%mod){}
    basic_modint& operator+=(const basic_modint a)       { if((x_+=     a.x_)>=mod)x_-=mod; return *this; }
    basic_modint& operator-=(const basic_modint a)       { if((x_+= mod-a.x_)>=mod)x_-=mod; return *this; }
    basic_modint& operator*=(const basic_modint a)       { (x_*=a.x_)%=mod; return *this; }
    basic_modint  operator+ (const basic_modint a) const { basic_modint res(*this); return res+=a; }
    basic_modint  operator- (const basic_modint a) const { basic_modint res(*this); return res-=a; }
    basic_modint  operator* (const basic_modint a) const { basic_modint res(*this); return res*=a; }
    basic_modint  pow(ll_t t) const { if(t==0)return 1; basic_modint a = pow(t>>1); a*=a; if(t%2==1)a*=(*this); return a; }
    basic_modint  inv() const { return pow(mod-2); }
    basic_modint& operator/=(const basic_modint a)       { return (*this) *= a.inv(); }
    basic_modint  operator/ (const basic_modint a) const { basic_modint res(*this); return res/=a; }
    friend istream& operator>>(istream& ist, basic_modint& a) { ist>>a.x_; return ist; }
    friend ostream& operator<<(ostream& ost, basic_modint& a) { ost<<a.x_; return ost; }
    bool operator==(const basic_modint a){return x_==a.x_; }
    bool operator!=(const basic_modint a){return x_!=a.x_; }
};
using mint = basic_modint<ll,998244353>;
int main(){
    int n;
    ll a,b,k;
    cin >> n >> a >> b >> k;
    vector<mint> ncr(n+1);
    ncr[0]=1;
    rep(i,n)ncr[i+1]=ncr[i]*((mint)(n-i))/((mint)(i+1));
    //ax+by=kを満たすx,y\in[0,n]を列挙
    mint ans=0;
    for(ll x=0;x<=n;++x){
        ll y=(k-a*x)/b;
        if(y>n||y<0)continue;
        if(a*x+b*y==k){
            ans+=ncr[x]*ncr[y];
        }
    }
    cout << ans << endl;
    return 0;
}