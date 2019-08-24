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
    string s;
    cin >> n >> s;
    vector<int> depth(2*n);
    depth[0]=1;
    depth[2*n-1]=1;
    int l=1,r=2*n-2;
    while(l<r){
        int new_l=l,new_r=r;
        while(new_l<r && s[new_l]==s[l])++new_l;
        while(new_l<new_r && s[new_r]==s[r])--new_r;
        for(int i=l;i<=new_l;++i)depth[i]=depth[l-1]+1;
        for(int i=r;i>=new_r;--i)depth[i]=depth[r+1]+1;
        l=new_l+1;
        r=new_r-1;
    }
    
    vector<mint> factorial(n+1);
    factorial[0]=1;
    for(int i=1;i<=n;i++)factorial[i]=factorial[i-1]*((mint)i);

    return 0;
}