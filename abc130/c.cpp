#include<cstdio>
using ll=long long;
int main(){
    ll w,h,x,y;
    scanf("%lld%lld%lld%lld",&w,&h,&x,&y);
    printf("%.10lf %d\n",(double)w*h/2,((x*2==w)&&(y*2==h))?1:0);
    return 0;
}