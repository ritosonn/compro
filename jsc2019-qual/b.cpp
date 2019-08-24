#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
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
};
using mint = basic_modint<ll,ll(1e9+7)>;
int main(){
    int n;
    mint k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<mint> cnt(n),cnt_all(n);
    rep(i,n)rep(j,n){
        if(a[i]>a[j]){
            if(i<j)cnt[i]+=(mint)1;
            cnt_all[i]+=(mint)1;
        }
    }
    mint ret=0;
    rep(i,n)ret+=(k-1)*k/((mint)2)*cnt_all[i]+k*cnt[i];
    cout << ret << endl;
    return 0;
}