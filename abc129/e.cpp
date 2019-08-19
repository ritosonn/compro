#include<cstdio>
#include<vector>
char l[100001];
using ll = long long;
using pll = std::pair<ll,ll>;
ll const p=1e9+7;
int main(){
    scanf("%s",l);
    //ans={a+b==Lになりうる場合の数,a+b<Lが確定した場合の数}
    pll ans={2,1};
    for(int i=1;l[i]!='\0';i++){
        if(l[i]=='0'){
            ans={ans.first,(3*ans.second)%p};
        }else{
            ans={(2*ans.first)%p,(3*ans.second+ans.first)%p};
        }
    }
    printf("%lld\n",(ans.first+ans.second)%p);
    return 0;
}