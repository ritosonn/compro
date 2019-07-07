#include<cstdio>
#include<algorithm>
using ll=long long;
int main(){
    ll l,r;
    scanf("%lld%lld",&l,&r);
    if(r-l>2019*2){
        printf("0\n");
    }else{
        ll ans=2018;
        for(ll i=l;i<=r;i++){
            for(ll j=i+1;j<=r;j++){
                ans=std::min(ans,(i*j)%2019);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}