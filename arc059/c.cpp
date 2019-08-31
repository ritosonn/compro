#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
template<typename ll_t,ll_t mod>
class basic_modint{
public:
    ll_t x_;
    constexpr basic_modint(ll_t x=0):x_((x%mod+mod)%mod){}
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
mint x[401][401]={},dp[401][401]={},const_pow[401][401];
int main(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep2(i,1,401){
        const_pow[i][0]=1;
        rep2(j,1,c+1)const_pow[i][j]=const_pow[i][j-1]*i;
    }
    //x[i][j]=a[i]^j+...+b[i]^j
    rep(i,n)rep(j,c+1)rep2(k,a[i],b[i]+1)x[i][j]+=const_pow[k][j];
    //dp[i][j]=i変数j次の単項式の和
    dp[0][0]=1;
    rep2(i,1,n+1){
        rep(j,c+1){
            rep(k,j+1){
                dp[i][j]+=dp[i-1][k]*x[i-1][j-k];
            }
        }
    }
    cout << dp[n][c] << endl;
    return 0;
}