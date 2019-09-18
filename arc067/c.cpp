#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
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
//dp[i][j]=i人未満のグループでj人を分ける場合の数
constexpr int max_N=1010;
mint factorial[max_N],finv[max_N],inv[max_N],dp[max_N][max_N];
mint ncr(int i,int j){
    if(i<j)return 0;
    return factorial[i]*finv[j]*finv[i-j];
}
int main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    factorial[0]=1;
    rep(i,1,max_N)factorial[i]=factorial[i-1]*i;
    loop(i,max_N)finv[i]=factorial[i].inv();
    rep(i,1,max_N)inv[i]=mint(i).inv();
    loop(i,max_N)dp[i][0]=1;
    rep(i,a,b+1)loop(j,n+1){
        if(dp[i][j]==0)continue;
        if(j!=0)dp[i+1][j]+=dp[i][j];
        mint p=1;
        for(int k=1;k<=d&&j+i*k<=n;++k){
            p*=ncr(n-j-i*(k-1),i)*inv[k];
            if(k>=c)dp[i+1][j+i*k]+=dp[i][j]*p;
        }
    }
    cout << dp[b+1][n] << endl;
    return 0;
}