#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using ll = long long;
using pll = std::pair<ll,ll>;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    std::vector<pll> vp;
    for(int i=0;i<n;i++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        vp.push_back({a,b});
    }
    std::sort(vp.begin(),vp.end(),[](pll x,pll y)->bool{return x.first<y.first;});
    //t日目にとるアルバイトiは
    //t + A_i <= M （期限以内にお金がもらえる）を満たすiのうち報酬 B_i が最も多いもの
    //tが大きい方から決定していく
    //for(auto &p:vp)printf("%lld %lld\n",p.first,p.second);
    std::priority_queue<ll> pq;
    int itr=0;
    ll sum=0;
    for(int date=1;date<=m;++date){
        while(itr<n&&vp[itr].first<=date){
            pq.push(vp[itr].second);
            ++itr;
        }
        if(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
    }
    printf("%lld\n",sum);
    return 0;
}