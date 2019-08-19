#include<cstdio>
long long ext_gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){x=1;y=0;return a;}
    long long q=a/b, g=ext_gcd(b,a-q*b,x,y), z=x-q*y;
    x=y; y=z;
    return g;
}
long long gcd(long long a,long long b){
    long long x,y;
    return ext_gcd(a,b,x,y);
}
int main(){
    int n;
    long long a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",gcd(a,b));
    }
    return 0;
}