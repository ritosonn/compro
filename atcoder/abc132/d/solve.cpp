#include<cstdio>
using ll = long long;
constexpr ll p=1e9+7;
ll fct[2001];
long long ext_gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){x=1;y=0;return a;}
    long long q=a/b, g=ext_gcd(b,a-q*b,x,y), z=x-q*y;
    x=y; y=z;
    return g;
}
long long inv(long long a){
    long long x,y;
    ext_gcd(a,p,x,y);
    return (x+p)%p;
}
void make_factorial(long long *x, int len){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*i)%p;
}

long long ncr(long long n,long long r){
    if(n<0||n<r||r<0)return 0;
    return (fct[n]*inv(fct[r])%p)*inv(fct[n-r])%p;
}

int main(){
    ll k,n;
    scanf("%lld%lld",&n,&k);
    make_factorial(fct,2001);
    for(int i=1;i<=k;i++){
        printf("%lld\n",ncr(n-k+1,i)*ncr(k-i+i-1,i-1)%p);
    }
    return 0;
}