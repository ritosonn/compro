#include<bits/stdc++.h>
using namespace std;

//拡張ユークリッド互除法（ax+by=gcd(a,b) 返り値はgcd）
long long ext_gcd(long long a,long long b,long long &x,long long &y){
    //b==0ならa*1+b*0=a
    if(b==0){x=1;y=0;return a;}
    //a=qb+rとして、bx+qy=gなるx,y,gが得られたとすると、
    //aX+bY=g \iff (qb+r)X+bY=g \iff b(qX+Y)+rX=g
    //より、x=qX+Y, y=X \iff X=y, Y=x-qy
    long long q=a/b, g=ext_gcd(b,a-q*b,x,y), z=x-q*y;
    x=y; y=z;
    return g;
}

long long gcd(long long a,long long b){
    long long x,y;
    return ext_gcd(a,b,x,y);
}

long long inv(long long a,long long p){
    long long x,y;
    ext_gcd(a,p,x,y);
    return (x+p)%p;
}

//x[i]=i*(i-1)*...*2*1
void make_factorial(long long *x, int len, long long p){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*i)%p;
}

//x[i]=a*a*...*a
void make_power(long long *x, long long a, int len, long long p){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*a)%p;
}

long long ncr(long long n,long long r,long long *fct,long long p){
    if(n<0||n<r||r<0)return 0;
    return (fct[n]*inv(fct[r],p)%p)*inv(fct[n-r],p)%p;
}

long long npr(long long n,long long r,long long *fct,long long p){
    if(n<0||n<r||r<0)return 0;
    return fct[n]*inv(fct[n-r],p)%p;
}

template<typename ll_t>
vector<pair<ll_t,ll_t>> factorize(ll_t x){
    vector<pair<ll_t,ll_t>> ret; ll_t x_tmp=x, cnt;
    if(x_tmp%2==0) { cnt=0; while(x_tmp%2==0) {x_tmp/=2; ++cnt;} ret.push_back({2,cnt});}
    for(ll_t p=3;x_tmp>1&&p*p<=x;p+=2) { cnt=0; while(x_tmp%p==0) {x_tmp/=2; ++cnt;} ret.push_back({p,cnt});}
    if(x_tmp>1)ret.push_back({x_tmp,1});
    return ret;
}

template<typename ll_t>
unordered_set<ll_t> divisors(ll_t x){
    auto factors=factorize(x);
    unordered_set<ll_t> ret;
    for(auto &p_s:factors){
        ll_t p=p_s.first;
        ll_t s=p_s.second; 
        unordered_set<ll_t> tmp;
        for(auto &r:ret){
            ll_t d=r;
            for(ll_t i=0;i<=s;++i){
                tmp.emplace(d);
                d*=p;
            }
        }
        ret=tmp;
    }
    return tmp;
}