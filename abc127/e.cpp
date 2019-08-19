#include<cstdio>
//x,y方向のコストは独立
//2マスを選ぶとき距離dになる選び方は(n-d)*m*m通り（高さの選び方×1個目の位置×2個目の位置）
//その2マスについて加算される回数は、残りのn*m-2マスからk-2マスを選ぶ場合の数

long long ext_gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){x=1;y=0;return a;}
    long long q=a/b, g=ext_gcd(b,a-q*b,x,y), z=x-q*y;
    x=y; y=z;
    return g;
}

long long inv(long long a,long long p){
    long long x,y;
    ext_gcd(a,p,x,y);
    return (x+p)%p;
}

void make_factorial(long long *x, int len, long long p){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*i)%p;
}

long long ncr(long long n,long long r,long long *fct,long long p){
    if(n<0||n<r||r<0)return 0;
    return (fct[n]*inv(fct[r],p)%p)*inv(fct[n-r],p)%p;
}

long long fct[200001];
constexpr long long p=1e9+7;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    make_factorial(fct,n*m+1,p);
    long long sum=0;
    //xについて加算
    for(int d=1;d<n;d++){
        sum+=(((ncr(n*m-2,k-2,fct,p)*(n-d)%p)*m%p)*m%p)*d%p;
    }
    //yについて加算
    for(int d=1;d<m;d++){
        sum+=(((ncr(n*m-2,k-2,fct,p)*(m-d)%p)*n%p)*n%p)*d%p;
    }
    printf("%lld\n",sum%p);
    return 0;
}