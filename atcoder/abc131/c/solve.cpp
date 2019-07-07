#include<cstdio>
using ll=long long;
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
// 1以上x以下の整数でyでもzでも割り切れないものの個数
ll count_anti_divisor(ll x,ll y,ll z){
    return x-x/y-x/z+x/lcm(y,z);
}
int main(){
    ll a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    printf("%lld\n",count_anti_divisor(b,c,d)-count_anti_divisor(a-1,c,d));
    return 0;
}