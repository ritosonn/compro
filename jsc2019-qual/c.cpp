#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
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
using mint = basic_modint<ll,ll(1e9+7)>;
int main(){
    int n;
    string s;
    cin >> n >> s;
    if(s[0]!=s[2*n-1] || s[0]=='W'){
        cout << 0 << endl;
        return 0;
    }
    string d;
    d.push_back('L');
    rep2(i,1,2*n){
        if((d.back()=='L')==(s[i]==s[i-1]))d.push_back('R');
        else d.push_back('L');
    }
    vector<mint> l(2*n,0),r(2*n,0);
    l[0]=1;
    rep2(i,1,2*n){
        if(d[i]=='L'){
            l[i]=l[i-1]+1;
            r[i]=r[i-1];
        }else{
            l[i]=l[i-1];
            r[i]=r[i-1]+1;
        }
    }
    if(l[2*n-1]!=r[2*n-1]){
        cout << 0 << endl;
        return 0;
    }
    mint ans=1;
    rep2(i,1,2*n){
        if(d[i]=='R'){
            ans*=(l[i-1]-r[i-1]);
        }
    }
    rep2(i,1,1+n)ans*=i;
    cout << ans << endl;
    return 0;
}