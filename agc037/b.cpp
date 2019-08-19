#include<cstdio>
#include<algorithm>
using ll = long long;
constexpr ll mod = 998244353;
char s[300001]={};
int order[100000][3];
int main(){
    int n;
    scanf("%d%s",&n,s);
    int r_itr=0,g_itr=0,b_itr=0;
    for(int i=0;i<n;++i){
        while(s[r_itr]!='R')r_itr++;
        while(s[g_itr]!='G')g_itr++;
        while(s[b_itr]!='B')b_itr++;
        order[i][0]=r_itr;
        order[i][1]=g_itr;
        order[i][2]=b_itr;
        std::sort(order[i],order[i]+3);
        //printf("%d %d %d\n",order[i][0],order[i][1],order[i][2]);
        ++r_itr;
        ++g_itr;
        ++b_itr;
    }
    //printf("\n");
    ll ans=1;
    int min_itr=0,max_itr=0;
    for(int i=0;i<n;i++){
        ans=(ans*(i+1))%mod;
        while(min_itr<n&&order[min_itr][0]<order[i][1])min_itr++;
        ans=(ans*(min_itr-i))%mod;
        while(max_itr<n&&order[max_itr][2]<order[i][1])max_itr++;
        ans=(ans*(1+i-max_itr))%mod;
        //printf("%d %d\n",min_itr-i,1+i-max_itr);
    }
    printf("%lld\n",ans);
    return 0;
}