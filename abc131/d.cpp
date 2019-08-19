#include<cstdio>
#include<vector>
#include<algorithm>
using ll=long long;
using pii=std::pair<ll,ll>;
int main(){
    int n;
    scanf("%d",&n);
    std::vector<pii> vp;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        vp.push_back({a,b});
    }
    std::sort(vp.begin(),vp.end(),[](pii a,pii b)->bool{return a.second<b.second;});
    ll asum=0;
    for(int i=0;i<n;i++){
        ll a=vp[i].first, b=vp[i].second;
        asum+=a;
        if(asum>b){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}